//
//  GameResource.cpp
//  supertarkartGame
//
//  Created by 陶正凯 on 14-10-30.
//
//

#include "GameResource.h"
static GameResource *pGameResouceInstance = nullptr;

GameResource::GameResource()
{
    
}

GameResource *GameResource::getInstance()
{
    if (!pGameResouceInstance) {
        pGameResouceInstance = new GameResource();
    }
    return pGameResouceInstance;
}

void GameResource::releaseInstance()
{
    CC_SAFE_DELETE(pGameResouceInstance);
}

void GameResource::loadAtlas(string fileName, cocos2d::Texture2D *pTexture)
{
    string fileTmpStr= FileUtils::getInstance()->getStringFromFile(fileName);
    unsigned long pos = fileTmpStr.find_first_of("\n");
    Altas mAltas;
    string fileStr = fileTmpStr.substr(0, pos);
    fileTmpStr = fileTmpStr.substr(pos+1);
    while (fileStr != "") {
        sscanf(fileStr.c_str(), "%s %d %d %f %f %f %f", mAltas.imgName, &mAltas.imgWidth, &mAltas.imgHeight, &mAltas.imgStartPoint.x, &mAltas.imgStartPoint.y, &mAltas.imgEndPoint.x, &mAltas.imgEndPoint.y);
        mAltas.imgStartPoint.x *= 1024;
        mAltas.imgStartPoint.y *= 1024;
        mAltas.imgEndPoint.x   *= 1024;
        mAltas.imgEndPoint.y   *= 1024;
        
        pos = fileTmpStr.find_first_of("\n");
        fileStr = fileTmpStr.substr(0, pos);
        fileTmpStr = fileTmpStr.substr(pos+1);
        
        if (mAltas.imgName == string("land")) {
            mAltas.imgStartPoint.x += 1;
        }
        Rect mRect = Rect(mAltas.imgStartPoint.x, mAltas.imgStartPoint.y, mAltas.imgWidth, mAltas.imgHeight);
        auto pSpriteFrame = SpriteFrame::createWithTexture(pTexture, mRect);
        pSpriteFrameCache.insert(string(mAltas.imgName), pSpriteFrame);
    }
}

SpriteFrame *GameResource::getSpriteFrameByName(string fileName)
{
    return pSpriteFrameCache.at(fileName);
}

