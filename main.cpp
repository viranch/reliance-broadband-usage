#include <QtGui/QApplication>
#include "reliancebroadband.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Reliance");
    QCoreApplication::setApplicationName("Broadband Usage");

    RelianceBroadband w;
    w.show();

    return a.exec();
}
