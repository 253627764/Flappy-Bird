//
//  MenuLayer.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-28.
//
//

#ifndef __supertarkartGame__MenuLayer__
#define __supertarkartGame__MenuLayer__

#include "cocos2d.h"
using namespace cocos2d;

class MenuLayer:public Layer
{
public:
    MenuLayer();
    virtual bool init();
    CREATE_FUNC(MenuLayer);
private:
    void onRateCallback();
    void onStartCallback();
    void onShareCallback();
    
};

#endif /* defined(__supertarkartGame__MenuLayer__) */
