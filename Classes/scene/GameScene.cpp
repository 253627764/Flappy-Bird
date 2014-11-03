//
//  GameScene.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "GameScene.h"
#include "../layer/GameMainLayer.h"
#include "../util/GameResources.h"

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
