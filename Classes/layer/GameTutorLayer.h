//
//  GameTutorLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-4.
//
//

#ifndef __supertarkartGame__GameTutorLayer__
#define __supertarkartGame__GameTutorLayer__

#include "cocos2d.h"
using namespace cocos2d;

class GameTutorLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameTutorLayer);
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
};

#endif /* defined(__supertarkartGame__GameTutorLayer__) */
