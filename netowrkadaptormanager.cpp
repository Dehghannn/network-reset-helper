#include "netowrkadaptormanager.h"

NetowrkAdaptorManager::NetowrkAdaptorManager(QObject *parent)
    : QObject{parent}
{
    m_interfaceList = QNetworkInterface::allInterfaces();
    foreach(auto config, m_interfaceList){
        qDebug() << config.humanReadableName();
        m_interfaceNameList.append(config.humanReadableName());
    }
}

QList<QNetworkInterface> NetowrkAdaptorManager::interfaceList() const
{
    return m_interfaceList;
}

void NetowrkAdaptorManager::setInterfaceList(const QList<QNetworkInterface> &newInterfaceList)
{
    m_interfaceList = newInterfaceList;
}

QStringList NetowrkAdaptorManager::interfaceNameList() const
{
    return m_interfaceNameList;
}

void NetowrkAdaptorManager::setInterfaceNameList(const QStringList &newInterfaceNameList)
{
    m_interfaceNameList = newInterfaceNameList;
}

void NetowrkAdaptorManager::onResetInterfaceWithIndex(int index)
{
    QNetworkInterface i = m_interfaceList.at(index);
    /// @todo reset the interface i here
    qDebug() << "reset called for interface:" << i.humanReadableName() << i.hardwareAddress();

}

void NetowrkAdaptorManager::onResetInterfaceByName(QString name)
{
    ///@todo reset interface by name here
}
