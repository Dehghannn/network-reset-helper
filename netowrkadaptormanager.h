#ifndef NETOWRKADAPTORMANAGER_H
#define NETOWRKADAPTORMANAGER_H

#include <QObject>
#include <QDebug>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QNetworkInterface>
#include <QProcess>


class NetowrkAdaptorManager : public QObject
{
    Q_OBJECT
public:
    explicit NetowrkAdaptorManager(QObject *parent = nullptr);

    QList<QNetworkInterface> interfaceList() const;
    void setInterfaceList(const QList<QNetworkInterface> &newInterfaceList);

    QStringList interfaceNameList() const;
    void setInterfaceNameList(const QStringList &newInterfaceNameList);

signals:
public slots:
    void onResetInterfaceWithIndex(int index);
    void onResetInterfaceByName(QString name);
private:
    QList<QNetworkInterface> m_interfaceList;
    QStringList m_interfaceNameList;


};

#endif // NETOWRKADAPTORMANAGER_H
