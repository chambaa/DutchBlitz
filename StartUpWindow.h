#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QApplication>
#include <QtWidgets>
#include "MainWindow.h"

class StartUpWindow : public QWidget
{
    Q_OBJECT
public:
    StartUpWindow();

private:
    QLineEdit * playingToValue;
    QComboBox * numOfPlayersBox;

private slots:
    void onPlayClicked();
};

#endif // STARTUPWINDOW_H
