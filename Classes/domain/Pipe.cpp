//
//  Pipe.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#include "Pipe.h"
#include "../tools/GameResource.h"
#include "../util/GameConst.h"

using namespace CocosDenshion;
Pipe::Pipe():isStart(true)
{
    
}

Pipe::~Pipe()
{
    pPipeVector.clear();
}

bool Pipe::init()
{
    if (!Layer::init()) {
        return false;
    }

    return true;
}

void Pipe::addPipe(float dt)
{
    GameResource *pGr = GameResource::getInstance();
    auto pipe_up = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("pipe_up"));
    pipe_up->setPosition(Point(pipe_up->getContentSize().width/2,pipe_up->getContentSize().height/2));
    auto body_up=PhysicsBody::create();
    auto body_shape_up=PhysicsShapeBox::create(pipe_up->getContentSize());
    body_up->addShape(body_shape_up);
    body_up->setDynamic(false);
    body_up->setGravityEnable(false);
    body_up->setCategoryBitmask(1);
    body_up->setCollisionBitmask(-1);
    body_up->setContactTestBitmask(-1);
    pipe_up->setPhysicsBody(body_up);
    
    //向下管道初始化，这边的THROUGH_HEIGHT是两根管道之间的空隙
    auto pipe_down = Sprite::createWithSpriteFrame(pGr->getSpriteFrameByName("pipe_down"));
    pipe_down->setPosition(Point(pipe_down->getContentSize().width/2,pipe_down->getContentSize().height/2+pipe_up->getContentSize().height+THROUGH_HEIGHT));
    auto body_down=PhysicsBody::create();
    auto body_shape_down=PhysicsShapeBox::create(pipe_down->getContentSize());
    body_down->addShape(body_shape_down);
    body_down->setDynamic(false);
    body_down->setGravityEnable(false);
    body_down->setCategoryBitmask(1);
    body_down->setCollisionBitmask(-1);
    body_down->setContactTestBitmask(-1);
    pipe_down->setPhysicsBody(body_down);
    
    //这边的node相当于一个容器把这两个管道封装在一个节点中并设置target
    auto node=Node::create();
    node->addChild(pipe_up,0,PIPE_UP);
    node->addChild(pipe_down,0,PIPE_DOWN);
    node->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    
    //关于管道Y坐标的设置（就是管道上下长度不一样的处理），大家还是看图例，说不清楚
    //管道是从右边移动到左边，所以PIPE_X的值肯定比游戏的width要大这里设定是300
    int range=rand()%PIPE_RANGE;
    node->setPosition(Point(PIPE_X, PIPE_Y + range));
    
    ActionManager *pActionManager = Director::getInstance()->getActionManager();
    MoveBy *pMoveBy = MoveBy::create(3.2f, Point(-400, 0));
    CallFuncN *pMoveOverCallback = CallFuncN::create(CC_CALLBACK_1(Pipe::moveOverHandle, this));
    ActionInterval *pSeq = Sequence::create(pMoveBy, pMoveOverCallback, nullptr);
    pActionManager->addAction(pSeq, node, false);
    
    this->addChild(node);
    pPipeVector.pushBack(node);
    if (isStart) {
        scheduleUpdate();
        isStart = false;
    }
}

void Pipe::startMovePipe()
{
    schedule(schedule_selector(Pipe::addPipe), 1.6f);
}

void Pipe::moveOverHandle(Ref *pNode)
{
    Node *node = (Node *)pNode;
    this->removeChild(node);
    pPipeVector.eraseObject(node);
}

void Pipe::update(float dt)
{
    Size mWinSize = Director::getInstance()->getWinSize();
    if (pPipeVector.size() <= 0) {
        return;
    }
    Node *pCurNode = (Node *)pPipeVector.at(0);
    if (pCurNode->getPositionX() < mWinSize.width/2 - 48) {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_point.mp3");
        pPipeVector.eraseObject(pCurNode);
    }
}

void Pipe::stopMovePipe()
{
    unschedule(schedule_selector(Pipe::addPipe));
    unscheduleUpdate();
    for_each(pPipeVector.begin(), pPipeVector.end(), deletePipe);
}

void Pipe::deletePipe(Ref *pPipe)
{
    auto node = (Node *)pPipe;
    node->stopAllActions();
    node->getChildByTag(PIPE_UP)->getPhysicsBody()->setEnable(false);
}
