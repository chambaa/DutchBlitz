#include "MainWindow.h"
#include<iostream>
#include<string>
#include <qdebug.h>

MainWindow::MainWindow(int playToValue, int numOfPlayers, QWidget *parent) : QWidget(parent)
{
    labelFont = QFont("Helvetica",30,20);
    dutchBlitz = QFont("Helvetica",50,40,true);
    nameFont = QFont("Helvetica",20,40);

    playTo = playToValue;
    numPlayers = numOfPlayers;
    QGridLayout * mainLayout = new QGridLayout();

    QLabel * blitzLabel = new QLabel("BLITZ!");
    blitzLabel->setFont(dutchBlitz);
    blitzLabel->setObjectName("blueLabel");

    QLabel * nameLabel = new QLabel("Name");
    nameLabel->setFont(labelFont);
    nameLabel->setStyleSheet("color:#006400");
    QLabel * scoreLabel = new QLabel("Score");
    scoreLabel->setFont(labelFont);
    scoreLabel->setStyleSheet("color:blue");
    QLabel * totalLabel = new QLabel("Total");
    totalLabel->setFont(labelFont);
    totalLabel->setStyleSheet("color:#FF4500");

    QPushButton * calculate = new QPushButton("Calculate");

    mainLayout->addWidget(blitzLabel,0,0,1,3,Qt::AlignHCenter);

    mainLayout->addWidget(nameLabel,1,0);
    mainLayout->addWidget(scoreLabel,1,1);
    mainLayout->addWidget(totalLabel,1,2);

    score1 = new QLineEdit();
    makeScoreEdit(score1);
    score2 = new QLineEdit();
    makeScoreEdit(score2);
    score3 = new QLineEdit();
    makeScoreEdit(score3);
    score4 = new QLineEdit();
    makeScoreEdit(score4);
    score5 = new QLineEdit();
    makeScoreEdit(score5);
    score6 = new QLineEdit();
    makeScoreEdit(score6);
    score7 = new QLineEdit();
    makeScoreEdit(score7);
    score8 = new QLineEdit();
    makeScoreEdit(score8);

    total1 = new QLineEdit();
    makeTotalEdit(total1);
    total2 = new QLineEdit();
    makeTotalEdit(total2);
    total3 = new QLineEdit();
    makeTotalEdit(total3);
    total4 = new QLineEdit();
    makeTotalEdit(total4);
    total5 = new QLineEdit();
    makeTotalEdit(total5);
    total6 = new QLineEdit();
    makeTotalEdit(total6);
    total7 = new QLineEdit();
    makeTotalEdit(total7);
    total8 = new QLineEdit();
    makeTotalEdit(total8);

    name1 = new QLineEdit();
    makeNameEdit(name1);
    name2 = new QLineEdit();
    makeNameEdit(name2);
    name3 = new QLineEdit();
    makeNameEdit(name3);
    name4 = new QLineEdit();
    makeNameEdit(name4);
    name5 = new QLineEdit();
    makeNameEdit(name5);
    name6 = new QLineEdit();
    makeNameEdit(name6);
    name7 = new QLineEdit();
    makeNameEdit(name7);
    name8 = new QLineEdit();
    makeNameEdit(name8);

    for(int i = 0; i < numOfPlayers; i++) {
        mainLayout->addWidget(getSpecificName(i+1),i+2,0);
        mainLayout->addWidget(getSpecificScore(i+1),i+2,1);
        mainLayout->addWidget(getSpecificTotal(i+1),i+2,2);
    }

    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setSpacing(30);

    mainLayout->addWidget(calculate,10,2);
    connect(calculate,SIGNAL(pressed()),this,SLOT(onCalculatePressed()));
    this->setLayout(mainLayout);
}

void MainWindow::makeNameEdit(QLineEdit * name) {
    name->setPlaceholderText("Name");
    name->setObjectName("green");
    name->setFont(nameFont);
}
void MainWindow::makeTotalEdit(QLineEdit * total) {
    total->setPlaceholderText("0");
    total->setReadOnly(true);
    total->setObjectName("red");
    total->setFont(nameFont);
}
void MainWindow::makeScoreEdit(QLineEdit * score) {
    score->setObjectName("blue");
}
QLineEdit * MainWindow::getSpecificScore(int num) {
    switch(num) {
    case 1:
        return score1;
    case 2:
        return score2;
    case 3:
        return score3;
    case 4:
        return score4;
    case 5:
        return score5;
    case 6:
        return score6;
    case 7:
        return score7;
    case 8:
        return score8;
    default:
        return nullptr;
    }
}
QLineEdit * MainWindow::getSpecificTotal(int num) {
    switch(num) {
    case 1:
        return total1;
    case 2:
        return total2;
    case 3:
        return total3;
    case 4:
        return total4;
    case 5:
        return total5;
    case 6:
        return total6;
    case 7:
        return total7;
    case 8:
        return total8;
    default:
        return nullptr;
    }
}
QLineEdit * MainWindow::getSpecificName(int num) {
    switch(num) {
    case 1:
        return name1;
    case 2:
        return name2;
    case 3:
        return name3;
    case 4:
        return name4;
    case 5:
        return name5;
    case 6:
        return name6;
    case 7:
        return name7;
    case 8:
        return name8;
    default:
        return nullptr;
    }
}


void MainWindow::onCalculatePressed()
{
    for(int i = 0; i < numPlayers; i++) {
        int oldScore = getSpecificTotal(i+1)->text().toInt();
        int add = getSpecificScore(i+1)->text().toInt();
        int newScore = oldScore + add;
        getSpecificTotal(i+1)->setText(std::to_string(newScore).c_str());
        getSpecificScore(i+1)->clear();
        if(newScore >= playTo)
        {
            winners.insert(std::pair<int, int>(i+1,newScore));
        }
    }

    if(winners.size() > 0) {
        std::map<int, int>::iterator itr;
        int high = 0;
        int highNum;
        for (itr = winners.begin(); itr != winners.end(); ++itr) {
            if(itr->second > high)
            {
                high = itr->second;
                highNum = itr->first;
            }
        }

        for(int i = 0; i < numPlayers; i++) {
            ranking.insert(std::pair<QString, int>(getSpecificName(i+1)->text(),
                                         getSpecificTotal(i+1)->text().toInt()));
        }
        QLineEdit * tempTotal = getSpecificTotal(highNum);
        QLineEdit * tempName = getSpecificName(highNum);

        tempTotal->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = tempName->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        int win = winMessage->exec();
        if(win == QMessageBox::Ok) {
            FinalRankingWindow * rankingsWindow = new FinalRankingWindow(ranking,this->numPlayers);
            rankingsWindow->show();
        }
    }
}

