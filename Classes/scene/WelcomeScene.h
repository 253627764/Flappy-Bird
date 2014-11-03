//
//  WelcomeScene.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-3.
//
//

#ifndef __supertarkartGame__WelcomeScene__
#define __supertarkartGame__WelcomeScene__

#include "cocos2d.h"
using namespace cocos2d;

class WelcomeScene:public Scene
{
public:
    WelcomeScene();
    virtual bool init();
    CREATE_FUNC(WelcomeScene);
    void relpaceScene();
    void loadAnimation();
    void loadEffects();
};

#endif /* defined(__supertarkartGame__WelcomeScene__) */
