//
//  GameResource.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-30.
//
//

#ifndef __supertarkartGame__GameResource__
#define __supertarkartGame__GameResource__

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

typedef struct Altas{
    char imgName[100];
    int imgWidth;
    int imgHeight;
    Point imgStartPoint;
    Point imgEndPoint;
}altas;

class GameResource
{
public:
    GameResource();
    static GameResource* getInstance();
    static void releaseInstance();
    void loadAtlas(string fileName, Texture2D *pTexture);
    SpriteFrame *getSpriteFrameByName(string fileName);
    
private:
    Map<std::string, SpriteFrame *> pSpriteFrameCache;
};

#endif /* defined(__supertarkartGame__GameResource__) */
