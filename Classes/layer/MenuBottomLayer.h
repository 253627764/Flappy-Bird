//
//  MenuBottomLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#ifndef __supertarkartGame__MenuBottomLayer__
#define __supertarkartGame__MenuBottomLayer__

#include "cocos2d.h"
using namespace cocos2d;

class MenuBottomLayer:public Layer
{
public:
    MenuBottomLayer();
    virtual bool init();
    CREATE_FUNC(MenuBottomLayer);
    virtual void update(float dt);
    void stopMove();
    void doMove();
private:
    Sprite *pLand1;
    Sprite *pLand2;
    float mMinX;
    float mPosX;
    bool isStart;
};

#endif /* defined(__supertarkartGame__MenuBottomLayer__) */
