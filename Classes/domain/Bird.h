//
//  Bird.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#ifndef __supertarkartGame__Bird__
#define __supertarkartGame__Bird__

#include "cocos2d.h"
#include "../util/GameEnum.h"
using namespace cocos2d;

class Bird:public Node
{
public:
    Bird();
    virtual bool init();
    CREATE_FUNC(Bird);
    virtual void update(float dt);
    void loadBirdAnimation();
    void setBirdState(BirdState mState);
private:
    BirdType mBirdType;
    bool bIsDead;
    Sprite *pBirdSprite;
    EventListenerTouchOneByOne *touchListener;
};

#endif /* defined(__supertarkartGame__Bird__) */
