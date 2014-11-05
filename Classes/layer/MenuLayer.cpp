//
//  MenuLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-28.
//
//

#include "MenuLayer.h"
#include "../scene/GameScene.h"
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
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    
    //add backgound
    Sprite* pBg = Sprite::create("bg_day.png");
    pBg->setPosition(Point(mSize.width/2, mSize.height/2));
    this->addChild(pBg);
    
    //add game title
    Sprite *pTitle = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("title.png"));
    pTitle->setPosition(mSize.width/2, mSize.height*0.75);
    this->addChild(pTitle);
 
    //add game copyright
    Sprite *pCopyRightLabel = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("brand_copyright.png"));
    pCopyRightLabel->setPosition(Point(mSize.width*0.55, mSize.height*0.7));
    this->addChild(pCopyRightLabel);
    
    //add bird
    Sprite *pBird = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("bird0_0.png"));
    pBird->setPosition(Point(mSize.width/2, mSize.height*0.62));
    this->addChild(pBird);
    
    //add rate button
    Menu *pMenu = Menu::create();
    pMenu->setPosition(Point(0, 0));
    this->addChild(pMenu);
    
    Sprite *pRateNor = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_rate.png"));
    Sprite *pRateDow = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_rate.png"));
    pRateDow->setScale(0.85);
    MenuItemSprite *pRateMenuItem = MenuItemSprite::create(pRateNor, pRateDow, CC_CALLBACK_0(MenuLayer::onRateCallback, this));
    pRateMenuItem->setPosition(Point(mSize.width/2, mSize.height*0.55));
    pMenu->addChild(pRateMenuItem);
    
    //add start button
    Sprite *pStartNor = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_play.png"));
    Sprite *pStartDow = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_play.png"));
    pStartDow->setScale(0.85);
    MenuItemSprite *pStartMenuItem = MenuItemSprite::create(pStartNor, pStartDow, CC_CALLBACK_0(MenuLayer::onStartCallback, this));
    Size mStartBtnSize = pStartNor->getContentSize();
    pStartMenuItem->setPosition(Point(mSize.width/2 - mStartBtnSize.width/2, mSize.height*0.45));
    pMenu->addChild(pStartMenuItem);
    
    //add share button
    Sprite *pShareNor = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_score.png"));
    Sprite *pShareDow = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("button_score.png"));
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
