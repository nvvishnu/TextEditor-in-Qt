#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(customcompleter);
    QApplication a(argc, argv); //Create Application
    MainWindow w;
    w.show();
    return a.exec(); //Application starts running
}
