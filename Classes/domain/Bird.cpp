//
//  Bird.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "Bird.h"
#include "../util/GameConst.h"

Bird::Bird():mBirdType(RedBird), bIsDead(false), pBirdSprite(nullptr), touchListener(nullptr)
{
    
}

bool Bird::init()
{
    if (!Node::init()) {
        return false;
    }
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    mBirdType = (BirdType)(rand()%3);
    
    char tmpBirdStr[12] = {0};
    sprintf(tmpBirdStr, "bird%d_0.png", mBirdType);
    pBirdSprite = Sprite::createWithSpriteFrame(pFrameCache->getSpriteFrameByName(tmpBirdStr));
    
    ActionManager *pActionManager = Director::getInstance()->getActionManager();
    AnimationCache *pAnimationCache = AnimationCache::getInstance();
    char tmpBirdAnimationName[12] = {0};
    sprintf(tmpBirdAnimationName, "bird%d", mBirdType);
    Animation *pBirdAnimation = pAnimationCache->getAnimation(tmpBirdAnimationName);
    Animate *pBirdAnimate = Animate::create(pBirdAnimation);
    RepeatForever *pRepeate = RepeatForever::create(pBirdAnimate);
    pActionManager->addAction(pRepeate, pBirdSprite, false);
    
    PhysicsBody *pPhysicsBody = PhysicsBody::create();
    pPhysicsBody->addShape(PhysicsShapeCircle::create(BIRD_RADIUS));
    pPhysicsBody->setDynamic(true);
    pPhysicsBody->setLinearDamping(0.7f);
    pPhysicsBody->setGravityEnable(false);
    pPhysicsBody->setCategoryBitmask(1);
    pPhysicsBody->setCollisionBitmask(-1);
    pPhysicsBody->setContactTestBitmask(-1);
    pBirdSprite->setPhysicsBody(pPhysicsBody);
    pBirdSprite->setPosition(Point(0, 0));
    this->addChild(pBirdSprite);
    
    touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(false);
    touchListener->onTouchBegan = [=](Touch *pTouch, Event *pEvent)
    {
        return true;
    };
    touchListener->onTouchEnded = [=](Touch *pTouch, Event *pEvent)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.mp3");
        pBirdSprite->getPhysicsBody()->setVelocity(Vec2(0, 260));
    };
    scheduleUpdate();
    
    return true;
}

void Bird::update(float dt)
{
    Size mWinSize = Director::getInstance()->getWinSize();
    if (pBirdSprite->getPositionY() >= mWinSize.height) {
        pBirdSprite->setPositionX(mWinSize.height);
    }
    pBirdSprite->setRotation(pBirdSprite->getPhysicsBody()->getVelocity().y*(-0.1));
}

void Bird::setBirdState(BirdState mState)
{
    switch (mState) {
        case StateNormal:
        {
            _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
            pBirdSprite->getPhysicsBody()->setGravityEnable(false);
        }
            break;
        case StateFly:
        {
            pBirdSprite->getPhysicsBody()->setGravityEnable(true);
        }
            break;
        case StateDie:
        {
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_die.mp3");
            unscheduleUpdate();
            _eventDispatcher->removeEventListener(touchListener);
            pBirdSprite->getPhysicsBody()->setGravityEnable(true);
            pBirdSprite->stopAllActions();
            pBirdSprite->setRotation(90);
        }
            break;
        default:
            break;
    }
}
