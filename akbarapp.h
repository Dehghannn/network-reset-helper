#ifndef AKBARAPP_H
#define AKBARAPP_H

#include <QObject>
#include <QSettings>
#include "mainwindow.h"
#include "netowrkadaptormanager.h"

class AkbarApp : public QObject
{
    Q_OBJECT
public:
    explicit AkbarApp(QObject *parent = nullptr);
    void showWindow();

signals:
public slots:
    void onSaveDefaultInterface(int index);
private:
    MainWindow m_window;
    NetowrkAdaptorManager m_adaptorManager;
    QSettings m_settings;

};

#endif // AKBARAPP_H
