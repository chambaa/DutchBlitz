#include "FinalRankingWindow.h"

FinalRankingWindow::FinalRankingWindow(std::map<QString,int> ranking, int numPlayers, QWidget *parent) : QWidget(parent) {
  labelFont = QFont("Helvetica",30,30);
  dutchBlitz = QFont("Helvetica",50,40,true);

  QLabel * rankingLabel = new QLabel("RANKINGS");
  rankingLabel->setFont(dutchBlitz);
  rankingLabel->setStyleSheet("color:#FFD700");

  rankings = ranking;
  mainLayout = new QGridLayout();
  mainLayout->addWidget(rankingLabel,0,0,1,3);

  for(int i = 0; i < numPlayers; i++) {
      FindHighestValue(i+1);
  }

  playAgainButton = new QPushButton("Play Again");
  mainLayout->addWidget(playAgainButton,numPlayers+1,2);
  mainLayout->setAlignment(Qt::AlignTop);
  mainLayout->setSpacing(30);

  connect(playAgainButton,SIGNAL(pressed()),this,SLOT(onPlayAgainClicked()));
  this->setStyleSheet("color:blue");
  this->setLayout(mainLayout);
}

void FinalRankingWindow::FindHighestValue(int row) {
    std::map<QString, int>::iterator itr;
    int high = 0;
    QString highName;
    for(itr = rankings.begin(); itr != rankings.end(); ++itr) {
        if(itr->second > high){
            high = itr->second;
            highName = itr->first;
        }
    }
    rankings.erase(highName);

    QLabel * name = new QLabel(highName);
    name->setFont(labelFont);
    QLabel * score = new QLabel(std::to_string(high).c_str());
    score->setFont(labelFont);
    QString rankString = std::to_string(row).c_str();
    rankString.append(". ");
    QLabel * rank = new QLabel(rankString);
    rank->setFont(labelFont);
    mainLayout->addWidget(rank,row,0);
    mainLayout->addWidget(name,row,1);
    mainLayout->addWidget(score,row,2);

}

void FinalRankingWindow::onPlayAgainClicked() {
    StartUpWindow * startUp = new StartUpWindow();
    startUp->show();
}
