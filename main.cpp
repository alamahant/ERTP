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

    QWidget parent;

    PingDialog* pingDialog = new PingDialog(&parent);
    pingDialog->setAttribute(Qt::WA_DeleteOnClose);  // Deletes itself when closed
    pingDialog->setWindowIcon(QIcon(":/io.github.alamahant.Ermis.png"));

    pingDialog->show();

    return a.exec();
}
