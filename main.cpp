#include "pingdialog.h"

#include <QApplication>
#include<QCoreApplication>
#include<QDir>
#include"constants.h"
#include<QWidget>


int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("ERTP");
    QCoreApplication::setOrganizationName("Alamahant");
    QCoreApplication::setApplicationVersion("1.0.0");
    QDir().mkpath(Constants::appDirPath);
    QDir().mkpath(Constants::receivedICMPPath);
    QDir().mkpath(Constants::ermistmpPath);
    QDir().mkpath(Constants::sslPath);


    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/io.github.alamahant.Ermis.png"));

    PingDialog* pingDialog = new PingDialog();
    pingDialog->show();
    pingDialog->setWindowIcon(QIcon(":/io.github.alamahant.Ermis.png"));

    pingDialog->show();
    
    return a.exec();
}
