#include <QDebug>
#include <QTimer>
#include <QCoreApplication>

#include "manager.h"
#include "adapter.h"
#include "device.h"
#include "initmanagerjob.h"

QList<QBluez::Device *> foundDevices;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QBluez::Manager *manager = new QBluez::Manager();
    QBluez::InitManagerJob *initJob = manager->init(QBluez::Manager::InitManagerAndAdapters);
    initJob->start();

    QObject::connect(initJob, &QBluez::InitManagerJob::result, [ = ]() {
        if (initJob->error()) {
            qDebug() << "Error initializing manager:" << initJob->errorText();
            return;
        }
        qDebug() << manager << manager->isBluetoothOperational();

        qDebug() << "Adapters:" << manager->adapters().count()
                 << "Devices:" << manager->devices().count();

        if (manager->adapters().isEmpty()) {
            return;
        }

        QBluez::Adapter *adapter = manager->usableAdapter();
        if (!adapter) {
            qDebug() << "No usable adapter!";
            return;
        }

        qDebug() << "Usable adapter:";
        qDebug() << "\t Address:" << adapter->address();
        qDebug() << "\t Name:" << adapter->name();
        qDebug() << "\t Alias:" << adapter->alias();
        qDebug() << "\t Class:" << adapter->adapterClass();
        qDebug() << "\t Powered:" << adapter->isPowered();
        qDebug() << "\t Discoverable:" << adapter->isDiscoverable();
        qDebug() << "\t Pairable:" << adapter->isPairable();
        qDebug() << "\t PairableTimeout:" << adapter->pairableTimeout();
        qDebug() << "\t DiscoverableTimeout:" << adapter->discoverableTimeout();
        qDebug() << "\t Discovering:" << adapter->isDiscovering();
        qDebug() << "\t UUIDs:" << adapter->uuids();
        qDebug() << "\t Modalias:" << adapter->modalias();
        qDebug() << "\t Devices:" << adapter->devices().count();

        QObject::connect(adapter, &QBluez::Adapter::deviceFound, [ = ](QBluez::Device *device) {
            qDebug() << "Found device...";

            QBluez::LoadDeviceJob *deviceJob = device->load();
            deviceJob->start();

            QObject::connect(deviceJob, &QBluez::LoadDeviceJob::result, [ = ]() {
                qDebug() << "Loaded device:";
                qDebug() << "\t Address:" << device->address();
                qDebug() << "\t Name:" << device->name();
                qDebug() << "\t FriendlyName:" << device->friendlyName();
                qDebug() << "\t Alias:" << device->alias();
                qDebug() << "\t Class:" << device->deviceClass();
                qDebug() << "\t Appearance:" << device->appearance();
                qDebug() << "\t Icon:" << device->icon();
                qDebug() << "\t Paired:" << device->isPaired();
                qDebug() << "\t Trusted:" << device->isTrusted();
                qDebug() << "\t Blocked:" << device->isBlocked();
                qDebug() << "\t LegacyPairing:" << device->hasLegacyPairing();
                qDebug() << "\t RSSI:" << device->rssi();
                qDebug() << "\t Connected:" << device->isConnected();
                qDebug() << "\t UUIDs:" << device->uuids();
                qDebug() << "\t Modalias:" << device->modalias();

                foundDevices.append(device);
            });
        });

        QBluez::PendingCall *powerOnCall = adapter->setPowered(true);

        QObject::connect(powerOnCall, &QBluez::PendingCall::finished, [ = ]() {
            if (powerOnCall->error()) {
                qDebug() << "Error powering on adapter:" << powerOnCall->errorText();
                return;
            }
            qDebug() << "Starting discovery...";
            adapter->startDiscovery();

            QTimer *timer = new QTimer();
            timer->setSingleShot(true);
            timer->start(10 * 1000);

            QObject::connect(timer, &QTimer::timeout, [ = ]() {
                qDebug() << "Stopping discovery...";
                adapter->stopDiscovery();

                Q_FOREACH (QBluez::Device *device, foundDevices) {
                    adapter->removeDevice(device);
                }
                foundDevices.clear();
            });
        });

        QObject::connect(adapter, &QBluez::Adapter::discoveringChanged, [ = ](bool discovering) {
            qDebug() << (discovering ? "Discovery STARTED" : "Discovery STOPPED");
        });
    });

    return app.exec();
}
