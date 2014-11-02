//
//  GameScene.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#ifndef __supertarkartGame__GameScene__
#define __supertarkartGame__GameScene__

#include "cocos2d.h"
using namespace cocos2d;

class GameScene:public Layer
{
public:
    GameScene();
    ~GameScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    static Scene *createScene();
    void gamePause();
    void gameOver();
    void gameStart();
    void gameRestart();
};

#endif /* defined(__supertarkartGame__GameScene__) */
