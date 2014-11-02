//
//  MenuScene.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-28.
//
//

#include "MenuScene.h"
#include "GameScene.h"
#include "../layer/MenuLayer.h"
#include "../layer/MenuBottomLayer.h"
#include "../tools/GameResource.h"
#include "../util/GameResources.h"

MenuScene::MenuScene()
{
    auto pTexture2D = Director::getInstance()->getTextureCache()->addImage(img_name);
    GameResource *pGr = GameResource::getInstance();
    pGr->loadAtlas(file_name, pTexture2D);
}

MenuScene::~MenuScene()
{
    SpriteFrameCache *pFrameCache = SpriteFrameCache::getInstance();
    pFrameCache->removeUnusedSpriteFrames();
    TextureCache *pTextureCache = Director::getInstance()->getTextureCache();
    pTextureCache->removeTextureForKey(img_name);
}

bool MenuScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    Size mWinSize = Director::getInstance()->getWinSize();
    auto menuLayer = MenuLayer::create();
    this->addChild(menuLayer);
    
    //    auto menuBottomLayer = MenuBottomLayer::create();
    //    menuBottomLayer->setPosition(Point(mWinSize.width/2, mWinSize.height*0.187));
    //    menuBottomLayer->doMove();
    //    this->addChild(menuBottomLayer);
    
    return true;
}
