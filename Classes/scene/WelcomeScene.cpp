//
//  WelcomeScene.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-3.
//
//

#include "WelcomeScene.h"
#include "MenuScene.h"
#include "../util/GameResources.h"
using namespace CocosDenshion;

WelcomeScene::WelcomeScene()
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    TextureCache *pTextureCache = Director::getInstance()->getTextureCache();
    pFrameCache->addSpriteFramesWithFile(plist_game);
    pTextureCache->addImage(img_game);
}

bool WelcomeScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    auto mWinSize = Director::getInstance()->getWinSize();
    auto welcomeLayer = Layer::create();
    this->addChild(welcomeLayer);
    Sprite *pWelcomeSprite = Sprite::create(img_loading);
    pWelcomeSprite->setPosition(Point(mWinSize.width/2, mWinSize.height/2));
    welcomeLayer->addChild(pWelcomeSprite);
    
    //load resources
    loadAnimation();
    loadEffects();
    
    DelayTime *pDelay = DelayTime::create(3.0f);
    CallFuncN *pCallback = CallFuncN::create(CC_CALLBACK_0(WelcomeScene::relpaceScene, this));
    ActionInterval *pAction = Sequence::create(pDelay, pCallback, nullptr);
    this->runAction(pAction);
    
    return true;
}

void WelcomeScene::relpaceScene()
{
    auto menuScene = MenuScene::create();
    Director::getInstance()->replaceScene(menuScene);
}

void WelcomeScene::loadAnimation()
{
    Vector<SpriteFrame *> pBirdSpriteFrame;
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    char birdSpriteFrameName[12] = {0};
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            sprintf(birdSpriteFrameName, "bird%d_%d.png", j, i);
            SpriteFrame *pFrame = pFrameCache->getSpriteFrameByName(birdSpriteFrameName);
            pBirdSpriteFrame.pushBack(pFrame);
        }
        sprintf(birdSpriteFrameName, "bird%d", j);
        AnimationCache *pBirdAnimationCache = AnimationCache::getInstance();
        pBirdAnimationCache->removeAnimation(birdSpriteFrameName);
        Animation *pBirdAnimation = Animation::createWithSpriteFrames(pBirdSpriteFrame);
        pBirdAnimation->setDelayPerUnit(0.1f);
        pBirdAnimationCache->addAnimation(pBirdAnimation, birdSpriteFrameName);
        pBirdSpriteFrame.clear();
    }
}

void WelcomeScene::loadEffects()
{
    SimpleAudioEngine *pAudioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
    pAudioEngine->preloadEffect("sfx_die.mp3");
    pAudioEngine->preloadEffect("sfx_hit.mp3");
    pAudioEngine->preloadEffect("sfx_point.mp3");
    pAudioEngine->preloadEffect("sfx_swooshing.mp3");
    pAudioEngine->preloadEffect("sfx_wing.mp3");
}
