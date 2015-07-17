//
//  Background.h
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#ifndef __MemoryCards__Background__
#define __MemoryCards__Background__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Background: public Node {
public:
    
    Background();
    virtual ~Background();
    virtual bool init();
    CREATE_FUNC(Background);
private:
    virtual void update(float t);
    Sprite *background;
};

#endif /* defined(__MemoryCards__Background__) */
