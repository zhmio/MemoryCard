//
//  ChartScene.h
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#ifndef __MemoryCards__ChartScene__
#define __MemoryCards__ChartScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Background.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class ChartScene: public Layer {
protected:
    Background *_background;
    ui::Button *_backBtn;
    Sprite *_newScoreTitle;
    ui::TextAtlas *_newScoreText;
    Sprite *_rankTitle;
    
public:
    ChartScene();
    virtual ~ChartScene();
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(ChartScene);
    
    Node* createRankRow(int rank, std::string score);
};

#endif /* defined(__MemoryCards__ChartScene__) */
