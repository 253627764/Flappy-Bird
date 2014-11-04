//
//  MenuBottomLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "MenuBottomLayer.h"
MenuBottomLayer::MenuBottomLayer():pLand1(nullptr), pLand2(nullptr), mMinX(0), mPosX(0), isStart(true)
{
    
}

bool MenuBottomLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    //add land1
    pLand1 = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("land.png"));
    Size mLandSize = pLand1->getContentSize();
    pLand1->setPosition(Point(mWinSize.width/2, mLandSize.height));
    this->addChild(pLand1);
    
    isStart = true;
    mMinX = mLandSize.width;
    mPosX = mWinSize.width/2 + mLandSize.width;
    //add land2
    pLand2 = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("land.png"));
    pLand2->setPosition(Point(mPosX, mLandSize.height));
    this->addChild(pLand2);
    
    return true;
}

void MenuBottomLayer::doMove()
{
    if (isStart) {
        schedule(schedule_selector(MenuBottomLayer::update), 0.6f);
        isStart = false;
    }
    MoveBy *pMoveBy = MoveBy::create(2.0f, Point(-180, 0));
    RepeatForever *pRepeate1 = RepeatForever::create(pMoveBy);
    pLand1->runAction(pRepeate1);
    
    MoveBy *pMoveBy2 = MoveBy::create(2.0f, Point(-180, 0));
    RepeatForever *pRepeate2 = RepeatForever::create(pMoveBy2);
    pLand2->runAction(pRepeate2);
}

void MenuBottomLayer::stopMove()
{
    unschedule(schedule_selector(MenuBottomLayer::update));
}

void MenuBottomLayer::update(float dt)
{
    if (pLand1->getPositionX() < mMinX) {
        pLand1->setPositionX(mPosX);
    }
    if (pLand2->getPositionX() < mMinX) {
        pLand2->setPositionX(mPosX);
    }
}