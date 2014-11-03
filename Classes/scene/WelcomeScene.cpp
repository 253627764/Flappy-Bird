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

WelcomeScene::WelcomeScene()
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    TextureCache *pTextureCache = Director::getInstance()->getTextureCache();
    pFrameCache->addSpriteFramesWithFile(plist_game);
    pTextureCache->addImage(img_game);
}

WelcomeScene::~WelcomeScene()
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    TextureCache *pTextureCache = Director::getInstance()->getTextureCache();
    pTextureCache->removeTextureForKey(img_game);
    pFrameCache->removeSpriteFramesFromFile(plist_game);
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
    
    DelayTime *pDelay = DelayTime::create(1.5f);
    CallFuncN *pCallback = CallFuncN::create(CC_CALLBACK_0(WelcomeScene::relpaceScene, this));
    ActionInterval *pAction = Sequence::create(pDelay, pCallback, nullptr);
    this->runAction(pAction);
    
    return true;
}

void WelcomeScene::relpaceScene()
{
    auto menuScene = MenuScene::create();
    Director::getInstance()->pushScene(menuScene);
}