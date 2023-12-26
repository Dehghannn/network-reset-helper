#include <QApplication>
#include "akbarapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AkbarApp App;
    App.showWindow();
    return a.exec();
}
