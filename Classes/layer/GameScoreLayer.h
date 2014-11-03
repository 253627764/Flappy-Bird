//
//  GameScoreLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-2.
//
//

#ifndef __supertarkartGame__GameScoreLayer__
#define __supertarkartGame__GameScoreLayer__

#include "cocos2d.h"
using namespace cocos2d;

class GameScoreLayer:public Layer
{
public:
    GameScoreLayer();
    virtual bool init();
    CREATE_FUNC(GameScoreLayer);
    static GameScoreLayer *getInstance();
    static void releaseInstance();
    void addScore();
    void resetScore();
    int getScore();
    
private:
    Label *pScoreLabel;
    int mScore;
};

#endif /* defined(__supertarkartGame__GameScoreLayer__) */
