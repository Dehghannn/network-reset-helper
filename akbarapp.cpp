#include "akbarapp.h"

AkbarApp::AkbarApp(QObject *parent)
    : QObject{parent}, m_settings{"config.ini", QSettings::IniFormat, this}
{
    m_window.setWindowTitle("Network Reset Helper");
    m_window.setNetworkList(m_adaptorManager.interfaceNameList());
    connect(&m_window, &MainWindow::resetNetworkWithIndex, &m_adaptorManager, &NetowrkAdaptorManager::onResetInterfaceWithIndex);
    connect(&m_window, &MainWindow::resetNetworkWithIndex, this, &AkbarApp::onSaveDefaultInterface);
}

void AkbarApp::showWindow()
{
    if(m_settings.contains("default_interface")){
        m_adaptorManager.onResetInterfaceByName(m_settings.value("default_interface").toString());
        exit(0);
    }
    m_window.show();
}

void AkbarApp::onSaveDefaultInterface(int index)
{
    QString interfaceName = m_adaptorManager.interfaceNameList().at(index);
    m_settings.setValue("default_interface", interfaceName);
}
