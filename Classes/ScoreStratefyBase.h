//
//  ScoreStratefyBase.h
//  MemoryCards
//
//  Created by zh on 15-7-15.
//
//

#ifndef MemoryCards_ScoreStratefyBase_h
#define MemoryCards_ScoreStratefyBase_h
#include "ScoreData.h"
#include "CardData.h"

class ScoreStratefyBase {
    
public:
    virtual void execute(ScoreData *score, CardData *cardDataA, CardData *cardDataB) = 0;
};

#endif
