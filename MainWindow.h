#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtWidgets>
#include "StartUpWindow.h"
#include "FinalRankingWindow.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(int playToValue, int numOfPlayers, QWidget *parent = nullptr);

    QLineEdit * score1;
    QLineEdit * score2;
    QLineEdit * score3;
    QLineEdit * score4;
    QLineEdit * score5;
    QLineEdit * score6;
    QLineEdit * score7;
    QLineEdit * score8;

    QLineEdit * total1;
    QLineEdit * total2;
    QLineEdit * total3;
    QLineEdit * total4;
    QLineEdit * total5;
    QLineEdit * total6;
    QLineEdit * total7;
    QLineEdit * total8;

    QLineEdit * name1;
    QLineEdit * name2;
    QLineEdit * name3;
    QLineEdit * name4;
    QLineEdit * name5;
    QLineEdit * name6;
    QLineEdit * name7;
    QLineEdit * name8;

    std::map<int,int> winners;
    std::map<QString, int> ranking;

    int playTo;
    int numPlayers;

    QFont labelFont;
    QFont dutchBlitz;
    QFont nameFont;

private:
    void makeNameEdit(QLineEdit * name);
    void makeTotalEdit(QLineEdit * total);
    void makeScoreEdit(QLineEdit * score);
    QLineEdit * getSpecificScore(int num);
    QLineEdit * getSpecificTotal(int num);
    QLineEdit * getSpecificName(int num);

public slots:
    void onCalculatePressed();

};

#endif // MAINWINDOW_H
