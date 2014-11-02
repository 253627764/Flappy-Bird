//
//  GameMainLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "GameMainLayer.h"
#include "../tools/GameResource.h"
#include "../domain/Pipe.h"
#include "../util/GameConst.h"
#include "GameOverLayer.h"

using namespace CocosDenshion;
GameMainLayer::GameMainLayer():pBird(nullptr)
{
    
}

bool GameMainLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    GameResource *pGr = GameResource::getInstance();
    
    //add backgroud
    Sprite *pBg = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("bg_day"));
    pBg->setPosition(Point(mWinSize.width/2, mWinSize.height/2));
    this->addChild(pBg);
    
    //add pipes
    auto pipe = Pipe::create();
    pipe->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    pipe->setPosition(Point::ZERO);
    this->addChild(pipe, 1);
    
    //add bird
    pBird = Bird::create();
    pBird->setPosition(Point(mWinSize.width/2, mWinSize.height*0.52));
    pBird->setBirdState(StateNormal);
    this->addChild(pBird, 2);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch *pTouch, Event *pEvent){
        return true;
    };
    touchListener->onTouchEnded = [=](Touch *pTouch, Event *pEvent)
    {
        pipe->startMovePipe();
        gameStart();
        _eventDispatcher->removeEventListener(touchListener);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    pEventListener = EventListenerPhysicsContact::create();
    pEventListener->onContactBegin = [=](const PhysicsContact& contact)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_hit.mp3");
        pipe->stopMovePipe();
        pBird->setBirdState(StateDie);
        GameOverLayer *pGameOverLayer = GameOverLayer::create();
        pGameOverLayer->setPosition(Point::ZERO);
        this->addChild(pGameOverLayer, 128);
        
        _eventDispatcher->removeEventListener(pEventListener);
        return true;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(pEventListener, this);
    return true;
}

void GameMainLayer::gameLogic(float dt)
{
    
}

void GameMainLayer::gameOver()
{
    
}

void GameMainLayer::gamePause()
{
    
}

void GameMainLayer::gameStart()
{
    pBird->setBirdState(StateFly);
}

