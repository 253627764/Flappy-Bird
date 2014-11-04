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
    GameOverLayer();
    virtual bool init();
    CREATE_FUNC(GameOverLayer);
    void gameRestart();
    void gameShareScore();
    void showPanel(int mScore);
private:
    Sprite *pMedal;
    Label *pCurScoreLabel;
    Label *pBestScoreLabel;
};

#endif /* defined(__supertarkartGame__GameOverLayer__) */
