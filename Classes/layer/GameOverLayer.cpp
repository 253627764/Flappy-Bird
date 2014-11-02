//
//  GameOverLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-2.
//
//

#include "GameOverLayer.h"
#include "../tools/GameResource.h"
#include "../scene/GameScene.h"
bool GameOverLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    GameResource *pGr = GameResource::getInstance();
    
    //add score panel
    Sprite *pScorePanel = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("score_panel"));
    pScorePanel->setPosition(Point(mWinSize.width/2, mWinSize.height/2));
    this->addChild(pScorePanel);
    
    Menu *pMenu = Menu::create();
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu);
    
    //add restart button
    Sprite *pRestartBtnNor = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_play"));
    Sprite *pRestartBtnDow = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_play"));
    Size mRestartBtnSize = pRestartBtnNor->getContentSize();
    pRestartBtnDow->setScale(0.9f);
    MenuItemSprite *pRestartMenuItem = MenuItemSprite::create(pRestartBtnNor, pRestartBtnDow, CC_CALLBACK_0(GameOverLayer::gameRestart, this));
    pRestartMenuItem->setPosition(Point(mWinSize.width/2 - mRestartBtnSize.width/2, mWinSize.height*0.32));
    pMenu->addChild(pRestartMenuItem);
    
    //add shareScore button
    Sprite *pShareScoreBtnNor = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_score"));
    Sprite *pShareScoreBtnDow = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_score"));
    Size mShareScoreBtnSize = pShareScoreBtnNor->getContentSize();
    pShareScoreBtnDow->setScale(0.9f);
    MenuItemSprite *pShareScoreMenuItem = MenuItemSprite::create(pShareScoreBtnNor, pShareScoreBtnDow, CC_CALLBACK_0(GameOverLayer::gameShareScore, this));
    pShareScoreMenuItem->setPosition(Point(mWinSize.width/2 + mShareScoreBtnSize.width/2, mWinSize.height*0.32));
    pMenu->addChild(pShareScoreMenuItem);
    
    return true;
}

void GameOverLayer::gameRestart()
{
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(gameScene);
}

void GameOverLayer::gameShareScore()
{
    //TODO
}
