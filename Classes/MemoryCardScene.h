//
//  MemoryCardScene.h
//  MemoryCards
//
//  Created by zh on 15-7-15.
//
//

#ifndef __MemoryCards__MemoryCardScene__
#define __MemoryCards__MemoryCardScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ScoreData.h"
#include "LevelData.h"
#include "EnergyBar.h"
#include "ScoreText.h"
#include "MemoryCardLevel.h"

USING_NS_CC;

class MemoryCardScene: public Layer {
protected:
    ScoreData _scoreData;
    virtual void update(float t);
    void initLevelData();
    void nextLevel();
    void initUI();
    LevelData _nowLevelData;
    EnergyBar *_energyBar;
    ScoreText *_scoreText;
    int allLevel;
    std::vector<LevelData> _levelDataList;
    MemoryCardLevel *_nowCardLevel;
    int _currentLevel;
    ui::Button *_pauseBt;
    
public:
    static Scene* createScene();
    CREATE_FUNC(MemoryCardScene);
    virtual bool init();
    void startGame();
    MemoryCardScene();
    virtual ~MemoryCardScene();
};

#endif /* defined(__MemoryCards__MemoryCardScene__) */
