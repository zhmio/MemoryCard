//
//  ICard.h
//  MemoryCards
//
//  Created by zh on 15-7-9.
//
//

#ifndef MemoryCards_ICard_h
#define MemoryCards_ICard_h

#include "CardState.h"
#include "CardData.h"
#include <functional>

class ICard {
    
public:
    virtual void flipToBack(const std::function<void()> &callback = nullptr) = 0;
    virtual void flipToFront(const std::function<void()> &callback = nullptr) = 0;
    virtual CardState getCardState() = 0;
    virtual void setCardData(CardData data) = 0;
    virtual CardData* getCardData() = 0;
};

#endif
