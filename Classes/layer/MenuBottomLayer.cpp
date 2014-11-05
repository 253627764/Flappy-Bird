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
    //add land1
    pLand1 = Sprite::create("land.png");
    PhysicsBody *pLandBody1 = PhysicsBody::create();
    PhysicsShapeBox *pLandBox1 = PhysicsShapeBox::create(pLand1->getContentSize());
    pLandBody1->addShape(pLandBox1);
    pLandBody1->setDynamic(false);
    pLandBody1->setGravityEnable(false);
    pLandBody1->setCategoryBitmask(1);
    pLandBody1->setCollisionBitmask(-1);
    pLandBody1->setContactTestBitmask(-1);
    pLand1->setPhysicsBody(pLandBody1);
    
    Size mLandSize = pLand1->getContentSize();
    pLand1->setPosition(Point(mWinSize.width/2, mLandSize.height/2));
    this->addChild(pLand1);
    
    isStart = true;
    mMinX = -mLandSize.width/2;
    mPosX = mWinSize.width/2 + mLandSize.width;
    //add land2
    pLand2 = Sprite::create("land.png");
    PhysicsBody *pLandBody2 = PhysicsBody::create();
    PhysicsShapeBox *pLandBox2 = PhysicsShapeBox::create(pLand2->getContentSize());
    pLandBody2->addShape(pLandBox2);
    pLandBody2->setDynamic(false);
    pLandBody2->setGravityEnable(false);
    pLandBody2->setCategoryBitmask(1);
    pLandBody2->setCollisionBitmask(-1);
    pLandBody2->setContactTestBitmask(-1);
    pLand2->setPhysicsBody(pLandBody2);
    
    pLand2->setPosition(Point(mPosX, mLandSize.height/2));
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
    pLand1->stopAllActions();
    pLand2->stopAllActions();
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