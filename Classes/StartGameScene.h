//
//  StartGameScene.h
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#ifndef __MemoryCards__StartGameScene__
#define __MemoryCards__StartGameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Background.h"
#include "ui/cocosGUI.h"

USING_NS_CC;

class StartGameScene:public Layer {
protected:
    Background *_background;
    Sprite *_logo;
    
    ui::Button *_startBtn;
    ui::Button *_chartBtn;
    ui::Button *_exitBtn;
    
public:
    StartGameScene();
    virtual ~StartGameScene();
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StartGameScene);
};

#endif /* defined(__MemoryCards__StartGameScene__) */
