//
//  PauseBox.h
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#ifndef __MemoryCards__PauseBox__
#define __MemoryCards__PauseBox__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class PauseBox: public Layer {
protected:
    std::function<void()> _continueCallBack;
    std::function<void()> _endGameCallBack;
    
public:
    virtual bool init();
    CREATE_FUNC(PauseBox);
    
    void registerCallBack(std::function<void()> continueCallBack, std::function<void()> endGameCallBack);
};

#endif /* defined(__MemoryCards__PauseBox__) */
