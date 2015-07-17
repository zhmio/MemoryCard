//
//  MemoryCardLevel.h
//  MemoryCards
//
//  Created by zh on 15-7-10.
//
//

#ifndef __MemoryCards__MemoryCardLevel__
#define __MemoryCards__MemoryCardLevel__

#include <stdio.h>
#include "cocos2d.h"
#include "LevelData.h"
#include "Card.h"
#include <vector>
#include "ScoreStratefy.h"

USING_NS_CC;

class MemoryCardLevel: public Layer {
    
public:
    MemoryCardLevel();
    virtual ~MemoryCardLevel();
    static MemoryCardLevel* create(LevelData data);
    virtual bool initWthData(LevelData data);
    void registerCallFunc(std::function<void(CardData *cardA, CardData *cardB)> pairCardCallback, std::function<void()> completeCallback);
    void setScoreStratefy(std::shared_ptr<ScoreStratefyBase> scroeStratefy);
    
protected:
    std::vector<std::vector<Card*>> _table;
    LevelData _levelData;
    int _unfinishedCard;
    Card *_selCardA;
    Card *_selCardB;
    std::function<void(CardData *cardA, CardData *cardB)> _pairCardCallback;
    std::function<void()> _completeCallback;
    std::shared_ptr<ScoreStratefyBase> _scroeStratefy;
    
    void initCardLayout();
    void initEventTouch();
};

#endif /* defined(__MemoryCards__MemoryCardLevel__) */
