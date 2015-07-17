//
//  ScoreStratefy.h
//  MemoryCards
//
//  Created by zh on 15-7-15.
//
//

#ifndef __MemoryCards__ScoreStratefy__
#define __MemoryCards__ScoreStratefy__

#include <stdio.h>
#include "ScoreStratefyBase.h"

class ScoreStratefy: public ScoreStratefyBase {
    
private:
    int _continuous;
public:
    ScoreStratefy();
    virtual void execute(ScoreData *score, CardData *cardDataA, CardData *cardDataB);
};

#endif /* defined(__MemoryCards__ScoreStratefy__) */
