//
//  GameMainLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#ifndef __supertarkartGame__GameMainLayer__
#define __supertarkartGame__GameMainLayer__

#include "cocos2d.h"
#include "../domain/Bird.h"
using namespace cocos2d;

class GameMainLayer:public Layer{
public:
    GameMainLayer();
    virtual bool init();
    CREATE_FUNC(GameMainLayer);
    void gameOver();
    void gamePause();
    void gameStart();
    void gameLogic(float dt);
private:
    Bird *pBird;
    EventListenerPhysicsContact *pEventListener;
};

#endif /* defined(__supertarkartGame__GameMainLayer__) */
