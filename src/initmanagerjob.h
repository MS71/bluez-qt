#ifndef QBLUEZ_INITMANAGERJOB_H
#define QBLUEZ_INITMANAGERJOB_H

#include <QObject>

#include "job.h"
#include "manager.h"
#include "qbluez_export.h"

namespace QBluez
{

class QBLUEZ_EXPORT InitManagerJob : public Job
{
    Q_OBJECT

public:
    ~InitManagerJob();

    Manager *manager() const;

Q_SIGNALS:
    void result(InitManagerJob *job);

private:
    explicit InitManagerJob(Manager *manager, Manager::InitType initType);

    void doStart() Q_DECL_OVERRIDE;
    void doEmitResult() Q_DECL_OVERRIDE;

    class InitManagerJobPrivate *d;

    friend class InitManagerJobPrivate;
    friend class Manager;
};

} // namespace QBluez

#endif // QBLUEZ_INITMANAGERJOB_H
