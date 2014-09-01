#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <QObject>

class ObjectManager;

class DeviceManager : public QObject
{
public:
    explicit DeviceManager(ObjectManager *parent = 0);

    void runAction(const QString &actionName, const QVariantMap &properties);

private:
    void runCreateAdapterAction(const QVariantMap &properties);
    void runCreateDeviceAction(const QVariantMap &properties);
    void runChangeAdapterProperty(const QVariantMap &properties);
    void runChangeDeviceProperty(const QVariantMap &properties);

    ObjectManager *m_objectManager;

};

#endif // DEVICEMANAGER_H