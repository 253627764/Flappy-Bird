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

class MenuBottomLayer:public Node
{
public:
    MenuBottomLayer();
    virtual bool init();
    CREATE_FUNC(MenuBottomLayer);
    void doMove();
};

#endif /* defined(__supertarkartGame__MenuBottomLayer__) */
