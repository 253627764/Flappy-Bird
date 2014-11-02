//
//  MenuBottomLayer.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "MenuBottomLayer.h"
#include "../tools/GameResource.h"
MenuBottomLayer::MenuBottomLayer()
{
    
}

bool MenuBottomLayer::init()
{
    if (!Node::init())
    {
        return false;
    }
    GameResource *pGr = GameResource::getInstance();
    Sprite *pFloat = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("land"));
    pFloat->setPosition(Point(0, 0));
    this->addChild(pFloat);
    
    return true;
}

void MenuBottomLayer::doMove()
{
    MoveBy *pMoveBy = MoveBy::create(1.5, Point(-10, 0));
    RepeatForever *pRepeateForever = RepeatForever::create(pMoveBy);
    this->runAction(pRepeateForever);
}
