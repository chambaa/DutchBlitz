#include "StartUpWindow.h"
#include<iostream>
#include<string>

StartUpWindow::StartUpWindow()
{
    QFont dutchBlitz = QFont("Helvetica",50,40,true);
    QFont nameFont = QFont("Helvetica",20,40);

    QLabel * blitzLabel = new QLabel("BLITZ!");
    blitzLabel->setFont(dutchBlitz);
    blitzLabel->setStyleSheet("color:#FFD700");

    QLabel * numOfPlayersLabel = new QLabel("Number of Players: ");
    numOfPlayersLabel->setFont(nameFont);
    numOfPlayersBox = new QComboBox();
    for(int i = 1; i < 8; i++) {
        numOfPlayersBox->addItem(std::to_string(i+1).c_str());
    }

    QLabel * playingToLabel = new QLabel("Playing to: ");
    playingToValue = new QLineEdit();
    playingToLabel->setFont(nameFont);

    QPushButton * playButton = new QPushButton("Play!");

    QGridLayout * mainLayout = new QGridLayout();

    mainLayout->addWidget(blitzLabel,0,0,1,3,Qt::AlignHCenter);
    mainLayout->addWidget(numOfPlayersLabel,1,0);
    mainLayout->addWidget(numOfPlayersBox,1,1);
    mainLayout->addWidget(playingToLabel,2,0);
    mainLayout->addWidget(playingToValue,2,1);
    mainLayout->addWidget(playButton,3,1);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setSpacing(30);

    connect(playButton,SIGNAL(pressed()),this,SLOT(onPlayClicked()));

    this->setStyleSheet("background-color:white; color:blue");
    this->setLayout(mainLayout);
}

void StartUpWindow::onPlayClicked() {
    int playToValue = playingToValue->text().toInt();
    int numOfPlayers = numOfPlayersBox->currentText().toInt();
    MainWindow * mainWindow = new MainWindow(playToValue, numOfPlayers);
    mainWindow->show();
}
