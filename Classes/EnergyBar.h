//
//  EnergyBar.h
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#ifndef __MemoryCards__EnergyBar__
#define __MemoryCards__EnergyBar__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class EnergyBar: public Node {
    
public:
    virtual bool init();
    CREATE_FUNC(EnergyBar);
    void updateProgress(float p);
    
protected:
    ProgressTimer *_progress;
    Sprite *_background;
    float _percent;
};

#endif /* defined(__MemoryCards__EnergyBar__) */
