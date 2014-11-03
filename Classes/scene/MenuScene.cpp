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
