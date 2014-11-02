//
//  Pipe.h
//  supertarkartGame
//
//  Created by 陶正凯 on 14-11-1.
//
//

#ifndef __supertarkartGame__Pipe__
#define __supertarkartGame__Pipe__

#include "cocos2d.h"
using namespace cocos2d;

class Pipe:public Layer
{
public:
    Pipe();
    ~Pipe();
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(Pipe);
    void addPipe(float dt);
    void startMovePipe();
    void stopMovePipe();
    void moveOverHandle(Ref *pNode);
    void static deletePipe(Ref *pPipe);
private:
    bool isStart;
    Vector<Node *> pPipeVector;
};

#endif /* defined(__supertarkartGame__Pipe__) */
