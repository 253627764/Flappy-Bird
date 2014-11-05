//
//  GameData.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-5.
//
//

#ifndef __supertarkartGame__GameData__
#define __supertarkartGame__GameData__

#include "cocos2d.h"
using namespace cocos2d;

class GameData
{
public:
    GameData();
    static GameData *getInstance();
    static void releaseInstance();
    void readData();
    void saveData();
    int getBestScore();
    int mPlayerScore;
};

#endif /* defined(__supertarkartGame__GameData__) */
