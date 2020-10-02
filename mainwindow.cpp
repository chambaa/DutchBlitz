#include "MainWindow.h"
#include<iostream>
#include<string>

MainWindow::MainWindow(int playToValue, int numOfPlayers, QWidget *parent) : QWidget(parent)
{
    labelFont = QFont("Helvetica",30,20);
    dutchBlitz = QFont("Helvetica",50,40,true);
    nameFont = QFont("Helvetica",20,40);

    playTo = playToValue;

    QGridLayout * mainLayout = new QGridLayout();

    QLabel * blitzLabel = new QLabel("BLITZ!");
    blitzLabel->setFont(dutchBlitz);

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
//    calculate->setStyleSheet("background-color:white; color:blue");

    mainLayout->addWidget(blitzLabel,0,0,1,3,Qt::AlignHCenter);

    mainLayout->addWidget(nameLabel,1,0);
    mainLayout->addWidget(scoreLabel,1,1);
    mainLayout->addWidget(totalLabel,1,2);

    mainLayout->addWidget(makeNameEdit(name1),2,0);
    mainLayout->addWidget(makeNameEdit(name2),3,0);
    mainLayout->addWidget(makeNameEdit(name3),4,0);
    mainLayout->addWidget(makeNameEdit(name4),5,0);
    mainLayout->addWidget(makeNameEdit(name5),6,0);
    mainLayout->addWidget(makeNameEdit(name6),7,0);
    mainLayout->addWidget(makeNameEdit(name7),8,0);
    mainLayout->addWidget(makeNameEdit(name8),9,0);

    mainLayout->addWidget(makeScoreEdit(score1),2,1);
    mainLayout->addWidget(makeScoreEdit(score2),3,1);
    mainLayout->addWidget(makeScoreEdit(score3),4,1);
    mainLayout->addWidget(makeScoreEdit(score4),5,1);
    mainLayout->addWidget(makeScoreEdit(score5),6,1);
    mainLayout->addWidget(makeScoreEdit(score6),7,1);
    mainLayout->addWidget(makeScoreEdit(score7),8,1);
    mainLayout->addWidget(makeScoreEdit(score8),9,1);

    mainLayout->addWidget(makeTotalEdit(total1),2,2);
    mainLayout->addWidget(makeTotalEdit(total2),3,2);
    mainLayout->addWidget(makeTotalEdit(total3),4,2);
    mainLayout->addWidget(makeTotalEdit(total4),5,2);
    mainLayout->addWidget(makeTotalEdit(total5),6,2);
    mainLayout->addWidget(makeTotalEdit(total6),7,2);
    mainLayout->addWidget(makeTotalEdit(total7),8,2);
    mainLayout->addWidget(makeTotalEdit(total8),9,2);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setSpacing(30);

    mainLayout->addWidget(calculate,10,2);
    connect(calculate,SIGNAL(pressed()),this,SLOT(onCalculatePressed()));

    this->setStyleSheet("background-color:white; color:#FFD700");
    this->setLayout(mainLayout);

}

QLineEdit * MainWindow::makeNameEdit(QLineEdit * name) {
    name = new QLineEdit();
    name->setPlaceholderText("Name");
    name->setStyleSheet("border:none; color:#006400");
    name->setFont(nameFont);
    return name;
}
QLineEdit * MainWindow::makeTotalEdit(QLineEdit * total) {
    total = new QLineEdit();
    total->setPlaceholderText("0");
    total->setReadOnly(true);
    total->setStyleSheet("border:none; color:#FF4500");
    total->setFont(nameFont);
    return total;
}
QLineEdit * MainWindow::makeScoreEdit(QLineEdit * score) {
    score = new QLineEdit();
    score->setStyleSheet("border-color: blue; border-style: solid; border-width: 2px;");
    return score;
}

void MainWindow::onCalculatePressed()
{

    int oldScore1 = total1->text().toInt();
    int add1 = score1->text().toInt();
    int newScore1 = oldScore1 + add1;
    total1->setText(std::to_string(newScore1).c_str());
    score1->clear();
    if(newScore1 >= playTo)
    {
        winners.insert(std::pair<int, int>(1,newScore1));
    }

    int oldScore2 = total2->text().toInt();
    int add2 = score2->text().toInt();
    int newScore2 = oldScore2 + add2;
    total2->setText(std::to_string(newScore2).c_str());
    score2->clear();
    if(newScore2 >= playTo)
    {
        winners.insert(std::pair<int, int>(2,newScore2));
    }

    int oldScore3 = total3->text().toInt();
    int add3 = score3->text().toInt();
    int newScore3 = oldScore3 + add3;
    total3->setText(std::to_string(newScore3).c_str());
    score3->clear();
    if(newScore3 >= playTo)
    {
        winners.insert(std::pair<int, int>(3,newScore3));
    }

    int oldScore4 = total4->text().toInt();
    int add4 = score4->text().toInt();
    int newScore4 = oldScore4 + add4;
    total4->setText(std::to_string(newScore4).c_str());
    score4->clear();
    if(newScore4 >= playTo)
    {
        winners.insert(std::pair<int, int>(4,newScore4));
    }

    int oldScore5 = total5->text().toInt();
    int add5 = score5->text().toInt();
    int newScore5 = oldScore5 + add5;
    total5->setText(std::to_string(newScore5).c_str());
    score5->clear();
    if(newScore5 >= playTo)
    {
        winners.insert(std::pair<int, int>(5,newScore5));
    }

    int oldScore6 = total6->text().toInt();
    int add6 = score6->text().toInt();
    int newScore6 = oldScore6 + add6;
    total6->setText(std::to_string(newScore6).c_str());
    score6->clear();
    if(newScore6 >= playTo)
    {
        winners.insert(std::pair<int, int>(6,newScore6));
    }

    int oldScore7 = total7->text().toInt();
    int add7 = score7->text().toInt();
    int newScore7 = oldScore7 + add7;
    total7->setText(std::to_string(newScore7).c_str());
    score7->clear();
    if(newScore7 >= playTo)
    {
        winners.insert(std::pair<int, int>(7,newScore7));
    }

    int oldScore8 = total8->text().toInt();
    int add8 = score8->text().toInt();
    int newScore8 = oldScore8 + add8;
    total8->setText(std::to_string(newScore8).c_str());
    score8->clear();
    if(newScore8 >= playTo)
    {
        winners.insert(std::pair<int, int>(8,newScore8));
    }

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
    if(highNum == 1)
    {
        total1->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name1->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total1->setStyleSheet("border: none");
        }

    }
    else if(highNum == 2)
    {
        total2->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name2->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total2->setStyleSheet("border: none");
        }
    }
    else if(highNum == 3)
    {
        total3->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name3->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total3->setStyleSheet("border: none");
        }
    }
    else if(highNum == 4)
    {
        total4->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name4->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total4->setStyleSheet("border: none");
        }
    }
    else if(highNum == 5)
    {
        total5->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name5->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total5->setStyleSheet("border: none");
        }
    }
    else if(highNum == 6)
    {
        total6->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name6->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total6->setStyleSheet("border: none");
        }
    }
    else if(highNum == 7)
    {
        total7->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name7->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total7->setStyleSheet("border: none");
        }
    }
    else if(highNum == 8)
    {
        total8->setStyleSheet("border-color: #d4af37");
        QMessageBox * winMessage = new QMessageBox();
        QString message = name8->text() + " wins!!";
        winMessage->setText(message);
        winMessage->addButton(QMessageBox::Ok);
        winMessage->addButton(QMessageBox::No);
        int win = winMessage->exec();
        switch(win) {
          case QMessageBox::No:
            winners.clear();
            playTo = 100;
            total8->setStyleSheet("border: none");
        }
    }
}

