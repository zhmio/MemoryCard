//
//  Card.h
//  MemoryCards
//
//  Created by zh on 15-7-9.
//
//

#ifndef __MemoryCards__Card__
#define __MemoryCards__Card__

#include "cocos2d.h"
#include <stdio.h>
#include "ICard.h"

USING_NS_CC;

class Card:public Node, public ICard {
    Card();
    virtual ~Card();
    
protected:
    CardData _cardData;
    CardState _cardState;
    CC_PROPERTY(Node *, _backImage, BackImage);
    CC_PROPERTY(Node *, _frontImage, FrontImage);
    
    void flipFromTo(Node *a, Node *b, const std::function<void()> &callback = nullptr);
    
public:
    CREATE_FUNC(Card);
    virtual bool init();
    
    virtual void flipToBack(const std::function<void()> &callback = nullptr);
    virtual void flipToFront(const std::function<void()> &callback = nullptr);
    virtual CardState getCardState();
    virtual void setCardData(CardData data);
    virtual CardData* getCardData();
};

#endif /* defined(__MemoryCards__Card__) */
