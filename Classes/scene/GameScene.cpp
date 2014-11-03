//
//  GameScene.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "GameScene.h"
#include "../layer/GameMainLayer.h"
#include "../tools/GameResource.h"
#include "../util/GameResources.h"

GameScene::GameScene()
{
    auto pTexture2D = Director::getInstance()->getTextureCache()->addImage(img_name);
    GameResource *pGr = GameResource::getInstance();
    pGr->loadAtlas(file_name, pTexture2D);
}

GameScene::~GameScene()
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    pFrameCache->removeUnusedSpriteFrames();
    TextureCache *pTextureCache = Director::getInstance()->getTextureCache();
    pTextureCache->removeTextureForKey(img_name);
}

bool GameScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    GameMainLayer *pGameMainLayer = GameMainLayer::create();
    this->addChild(pGameMainLayer);
    
    return true;
}

Scene *GameScene::createScene()
{
    auto scene= Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -980));
    auto gameScene = GameScene::create();
    scene->addChild(gameScene);
    return scene;
}
