//
//  ScoreText.h
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#ifndef __MemoryCards__ScoreText__
#define __MemoryCards__ScoreText__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class ScoreText:public Node {
protected:
    ui::TextAtlas *_text;
    int _score;
    
public:
    virtual bool init();
    CREATE_FUNC(ScoreText);
    void updateScore(int value);
};

#endif /* defined(__MemoryCards__ScoreText__) */
