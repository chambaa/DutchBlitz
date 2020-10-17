#ifndef FINALRANKINGWINDOW_H
#define FINALRANKINGWINDOW_H

#include <QObject>
#include <QtWidgets>
#include "StartUpWindow.h"

class FinalRankingWindow : public QWidget
{
    Q_OBJECT
public:
    FinalRankingWindow(std::map<QString,int> ranking, int numPlayers, QWidget *parent = nullptr);
    QFont labelFont;
    QFont dutchBlitz;
    QFont nameFont;
    std::map<QString, int> rankings;

private:
    void FindHighestValue(int row);
    QGridLayout * mainLayout;
    QPushButton * playAgainButton;

private slots:
    void onPlayAgainClicked();
};

#endif // FINALRANKINGWINDOW_H
