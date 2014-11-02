//
//  GameOverLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-2.
//
//

#ifndef __supertarkartGame__GameOverLayer__
#define __supertarkartGame__GameOverLayer__

#include "cocos2d.h"
using namespace cocos2d;

class GameOverLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameOverLayer);
    void gameRestart();
    void gameShareScore();
};

#endif /* defined(__supertarkartGame__GameOverLayer__) */
