//
//  GameData.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-5.
//
//

#include "GameData.h"
#include "../util/GameConst.h"

static GameData *pInstance = nullptr;
GameData::GameData():mPlayerScore(0)
{
    
}

GameData *GameData::getInstance()
{
    if (!pInstance) {
        pInstance = new GameData();
        pInstance->readData();
    }
    return pInstance;
}

void GameData::releaseInstance()
{
    CC_SAFE_DELETE(pInstance);
}

void GameData::readData()
{
    UserDefault *pUd = UserDefault::getInstance();
    mPlayerScore = pUd->getIntegerForKey(playerScore, 0);
}

void GameData::saveData()
{
    UserDefault *pUd = UserDefault::getInstance();
    pUd->setIntegerForKey(playerScore, mPlayerScore);
}
