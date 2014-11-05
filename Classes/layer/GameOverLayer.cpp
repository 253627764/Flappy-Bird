//
//  GameOverLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-2.
//
//

#include "GameOverLayer.h"
#include "../scene/GameScene.h"
#include "../util/GameResources.h"
#include "../util/GameConst.h"
#include "../tools/GameData.h"

using namespace std;
GameOverLayer::GameOverLayer():pMedal(nullptr), pCurScoreLabel(nullptr), pBestScoreLabel(nullptr)
{
    
}

bool GameOverLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    
    //add game over label
    Sprite *pGameOverLabel = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("text_game_over.png"));
    pGameOverLabel->setPosition(Point(mWinSize.width/2, mWinSize.height*0.72));
    this->addChild(pGameOverLabel);
    
    //add score panel
    Sprite *pScorePanel = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("score_panel.png"));
    pScorePanel->setPosition(Point(mWinSize.width/2, mWinSize.height/2));
    this->addChild(pScorePanel);
    
    Size mScorePanelSize = pScorePanel->getContentSize();
    //add medal
    pMedal = Sprite::create();
    pMedal->setPosition(Point(mScorePanelSize.width*0.23, mScorePanelSize.height*0.46));
    pScorePanel->addChild(pMedal);
    
    //add current score
    pCurScoreLabel = Label::createWithBMFont(fnt_font2, "0");
    pCurScoreLabel->setPosition(Point(mScorePanelSize.width*0.81, mScorePanelSize.height*0.59));
    pScorePanel->addChild(pCurScoreLabel);
    
    //add best score
    pBestScoreLabel = Label::createWithBMFont(fnt_font2, "0");
    pBestScoreLabel->setPosition(Point(mScorePanelSize.width*0.81, mScorePanelSize.height*0.26));
    pScorePanel->addChild(pBestScoreLabel);
    
    Menu *pMenu = Menu::create();
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu);
    
    //add restart button
    Sprite *pRestartBtnNor = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_play.png"));
    Sprite *pRestartBtnDow = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_play.png"));
    Size mRestartBtnSize = pRestartBtnNor->getContentSize();
    pRestartBtnDow->setScale(0.9f);
    MenuItemSprite *pRestartMenuItem = MenuItemSprite::create(pRestartBtnNor, pRestartBtnDow, CC_CALLBACK_0(GameOverLayer::gameRestart, this));
    pRestartMenuItem->setPosition(Point(mWinSize.width/2 - mRestartBtnSize.width/2, mWinSize.height*0.32));
    pMenu->addChild(pRestartMenuItem);
    
    //add shareScore button
    Sprite *pShareScoreBtnNor = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_score.png"));
    Sprite *pShareScoreBtnDow = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_score.png"));
    Size mShareScoreBtnSize = pShareScoreBtnNor->getContentSize();
    pShareScoreBtnDow->setScale(0.9f);
    MenuItemSprite *pShareScoreMenuItem = MenuItemSprite::create(pShareScoreBtnNor, pShareScoreBtnDow, CC_CALLBACK_0(GameOverLayer::gameShareScore, this));
    pShareScoreMenuItem->setPosition(Point(mWinSize.width/2 + mShareScoreBtnSize.width/2, mWinSize.height*0.32));
    pMenu->addChild(pShareScoreMenuItem);
    
    return true;
}

void GameOverLayer::gameRestart()
{
    Director *pGd = Director::getInstance();
    auto gameScene = GameScene::createScene();
    pGd->replaceScene(gameScene);
}

void GameOverLayer::gameShareScore()
{
    //TODO
}

void GameOverLayer::showPanel(int mScore)
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    if (mScore >= GOLD_MEDAL) {
        pMedal->setSpriteFrame(pFrameCache->getSpriteFrameByName("medals_3.png"));
    }
    else if (mScore >= SLIVER_MEDAL)
    {
        pMedal->setSpriteFrame(pFrameCache->getSpriteFrameByName("medals_2.png"));
    }
    else if (mScore >= BRANZE_MEDAL)
    {
        pMedal->setSpriteFrame(pFrameCache->getSpriteFrameByName("medals_1.png"));
    }
    else
    {
        pMedal->setSpriteFrame(pFrameCache->getSpriteFrameByName("medals_0.png"));
    }
    
    char scoreStr[5] = {0};
    sprintf(scoreStr, "%d", mScore);
    pCurScoreLabel->setString(string(scoreStr));
    
    GameData *pGd = GameData::getInstance();
    if (mScore > pGd->mPlayerScore) {
        pGd->mPlayerScore = mScore;
        pGd->saveData();
    }
    int mBestScore = pGd->mPlayerScore;
    sprintf(scoreStr, "%d", mBestScore);
    pBestScoreLabel->setString(string(scoreStr));
}
