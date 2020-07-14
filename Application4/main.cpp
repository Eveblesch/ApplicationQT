#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Style
    QFile styleFile( ":/styles/style.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/font/KGDoYouLoveMe.ttf");

    QFontDatabase fontDB2;
    fontDB2.addApplicationFont(":/font/Foglihten-068.otf");
//        QFontDatabase db;
//         for(int i=0; i<db.families().size(); i++)
//         {
//           qDebug() << db.families().at(i);
//         }


    return a.exec();
}
