/**
 * @file main.cpp
 * @author fl0mll
 * @date 2016/06/07
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief Main entry point
 */
#include "settingsview.h"
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SettingsView w;

    // Load an application style
    QFile styleFile(":/styles/styles/default.qss");
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style( styleFile.readAll() );
    app.setStyleSheet( style );

//    QFontDatabase fontDB;
//    fontDB.addApplicationFont(":/GraphicsView/fonts");
//    foreach(QString s, fontDB.families())
//    {
//        qDebug() << s;
//    }

    w.show();

    return app.exec();
}
