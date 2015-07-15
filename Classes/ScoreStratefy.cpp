//
//  ScoreStratefy.cpp
//  MemoryCards
//
//  Created by zh on 15-7-15.
//
//

#include "ScoreStratefy.h"

ScoreStratefy::ScoreStratefy():_continuous(0){
    
}

void ScoreStratefy::execute(ScoreData *score, CardData *cardDataA, CardData *cardDataB) {
    if (cardDataA->number == cardDataB->number) {
        _continuous++;
        if (_continuous > score->maxCount) {
            score->maxCount = _continuous;
        }
        score->energy += 100;
        score->score += 100*_continuous;
    } else {
        if (cardDataA->flipCount == 0 && cardDataB->flipCount == 0) {
            
        } else {
            score->maxCount = 0;
            score->energy -= 100;
        }
        cardDataA->flipCount++;
        cardDataB->flipCount++;
    }
}