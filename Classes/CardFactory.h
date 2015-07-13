//
//  CardFactory.h
//  MemoryCards
//
//  Created by zh on 15-7-9.
//
//

#ifndef __MemoryCards__CardFactory__
#define __MemoryCards__CardFactory__

#include <iostream>
#include "cocos2d.h"
#include "ICard.h"

USING_NS_CC;

class CardFactory {
    
public:
    static ICard* createCard(int backId, int number);
};

#endif /* defined(__MemoryCards__CardFactory__) */
