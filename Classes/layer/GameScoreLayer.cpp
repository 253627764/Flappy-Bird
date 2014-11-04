//
//  GameScoreLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-2.
//
//

#include "GameScoreLayer.h"
#include "../util/GameResources.h"
using namespace std;

static GameScoreLayer *pInstance = nullptr;
GameScoreLayer::GameScoreLayer():pScoreLabel(nullptr), mScore(0)
{
    
}

bool GameScoreLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    mScore = 0;
    pScoreLabel = Label::createWithBMFont(fnt_font1, "0");
    pScoreLabel->setPosition(Point(mWinSize.width/2, mWinSize.height*0.85));
    this->addChild(pScoreLabel);
    
    return true;
}

GameScoreLayer *GameScoreLayer::getInstance()
{
    if (!pInstance) {
        pInstance = new GameScoreLayer();
        pInstance->init();
    }
    return pInstance;
}

void GameScoreLayer::releaseInstance()
{
    CC_SAFE_DELETE(pInstance);
}

void GameScoreLayer::addScore()
{
    mScore++;
    char scoreStr[5] = {0};
    sprintf(scoreStr, "%d", mScore);
    pScoreLabel->setString(string(scoreStr));
}

void GameScoreLayer::resetScore()
{
    mScore = 0;
    char scoreStr[5] = {0};
    sprintf(scoreStr, "%d", mScore);
    pScoreLabel->setString(string(scoreStr));
}

int GameScoreLayer::getScore()
{
    return mScore;
}
