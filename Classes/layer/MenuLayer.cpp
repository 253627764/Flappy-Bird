//
//  MenuLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-28.
//
//

#include "MenuLayer.h"
#include "../scene/GameScene.h"
#include "../tools/GameResource.h"
using namespace std;
MenuLayer::MenuLayer()
{
}
bool MenuLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size mSize = Director::getInstance()->getWinSize();
    GameResource *pGr = GameResource::getInstance();
    
    //add backgound
    Sprite* pBg = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("bg_day"));
    pBg->setPosition(Point(mSize.width/2, mSize.height/2));
    this->addChild(pBg);
    
    //add game title
    Sprite *pTitle = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("title"));
    pTitle->setPosition(mSize.width/2, mSize.height*0.75);
    this->addChild(pTitle);
 
    //add game copyright
    Sprite *pCopyRightLabel = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("brand_copyright"));
    pCopyRightLabel->setPosition(Point(mSize.width*0.55, mSize.height*0.7));
    this->addChild(pCopyRightLabel);
    
    //add bird
    Sprite *pBird = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("bird0_0"));
    pBird->setPosition(Point(mSize.width/2, mSize.height*0.62));
    this->addChild(pBird);
    
    //add rate button
    Menu *pMenu = Menu::create();
    pMenu->setPosition(Point(0, 0));
    this->addChild(pMenu);
    
    Sprite *pRateNor = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_rate"));
    Sprite *pRateDow = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_rate"));
    pRateDow->setScale(0.85);
    MenuItemSprite *pRateMenuItem = MenuItemSprite::create(pRateNor, pRateDow, CC_CALLBACK_0(MenuLayer::onRateCallback, this));
    pRateMenuItem->setPosition(Point(mSize.width/2, mSize.height*0.55));
    pMenu->addChild(pRateMenuItem);
    
    //add start button
    Sprite *pStartNor = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_play"));
    Sprite *pStartDow = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_play"));
    pStartDow->setScale(0.85);
    MenuItemSprite *pStartMenuItem = MenuItemSprite::create(pStartNor, pStartDow, CC_CALLBACK_0(MenuLayer::onStartCallback, this));
    Size mStartBtnSize = pStartNor->getContentSize();
    pStartMenuItem->setPosition(Point(mSize.width/2 - mStartBtnSize.width/2, mSize.height*0.45));
    pMenu->addChild(pStartMenuItem);
    
    //add share button
    Sprite *pShareNor = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_score"));
    Sprite *pShareDow = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("button_score"));
    pShareDow->setScale(0.85);
    MenuItemSprite *pShareMenuItem = MenuItemSprite::create(pShareNor, pShareDow, CC_CALLBACK_0(MenuLayer::onShareCallback, this));
    Size mShareBtnSize = pShareNor->getContentSize();
    pShareMenuItem->setPosition(Point(mSize.width/2 + mShareBtnSize.width/2, mSize.height*0.45));
    pMenu->addChild(pShareMenuItem);
    
    return true;
}

void MenuLayer::onRateCallback()
{
    //TODO
}

void MenuLayer::onStartCallback()
{
    auto pGameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(pGameScene);
}

void MenuLayer::onShareCallback()
{
    //TODO
}
