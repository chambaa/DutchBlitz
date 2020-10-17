#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <string>
#include "MainWindow.h"
#include "StartUpWindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

//    // Load StyleSheet
//    QFile styleFile(":/StyleSheet/StyleSheet.css");
//    styleFile.open(QFile::ReadOnly);

//    // Apply the loaded stylesheet
//    QString style( styleFile.readAll() );
//    app.setStyleSheet(style);

    StartUpWindow * startUp = new StartUpWindow();
    startUp->show();


    return app.exec();
}
