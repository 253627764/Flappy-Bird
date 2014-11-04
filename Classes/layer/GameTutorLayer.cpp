//
//  GameTutorLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-4.
//
//

#include "GameTutorLayer.h"

bool GameTutorLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    
    Sprite *pTitle = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("text_ready.png"));
    pTitle->setPosition(Point(mWinSize.width/2, mWinSize.height*0.7));
    this->addChild(pTitle);
    
    Sprite *pTap = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName("tutorial.png"));
    pTap->setPosition(Point(mWinSize.width/2, mWinSize.height*0.4));
    this->addChild(pTap);
    
    auto pTouchListener = EventListenerTouchOneByOne::create();
    pTouchListener->setSwallowTouches(true);
    pTouchListener->onTouchBegan = CC_CALLBACK_2(GameTutorLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(pTouchListener, this);
    
    return true;
}

bool GameTutorLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    this->getParent()->removeChild(this);
    return true;
}