//
//  MemoryCardScene.cpp
//  MemoryCards
//
//  Created by zh on 15-7-15.
//
//

#include "MemoryCardScene.h"
#include "ScoreStratefy.h"
#include "Background.h"
#include "PauseBox.h"
#include "SceneMediator.h"
#include "UserData.h"
#include <vector>

MemoryCardScene::MemoryCardScene():_currentLevel(0){
    
}

MemoryCardScene::~MemoryCardScene(){
    this->removeAllChildren();
    this->unscheduleUpdate();
}

Scene* MemoryCardScene::createScene(){
    auto scene = Scene::create();
    auto layer = MemoryCardScene::create();
    scene->addChild(layer);
    return scene;
}

bool MemoryCardScene::init(){
    if (!Layer::init()) {
        return false;
    }
    initLevelData();
    initUI();
    startGame();
    this->scheduleUpdate();
    return true;
}

void MemoryCardScene::initUI(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto background = Background::create();
    this->addChild(background);
    
    _energyBar = EnergyBar::create();
    auto energySize = _energyBar->getContentSize();
    _energyBar->setPosition(Vec2(visibleSize.width/2, visibleSize.height - 70));
    this->addChild(_energyBar);
    
    _scoreText = ScoreText::create();
    _scoreText->setPosition(Vec2(visibleSize.width*2/3, visibleSize.height - 30));
    _scoreText->setScale(0.7);
    this->addChild(_scoreText);
    
    _pauseBt = ui::Button::create("pause.png");
    _pauseBt->setAnchorPoint(Vec2(0, 1));
    _pauseBt->setPosition(Vec2(0, visibleSize.height));
    this->addChild(_pauseBt);
    _pauseBt->addClickEventListener([this](Ref *ref){
        this->unscheduleUpdate();
        auto box = PauseBox::create();
        box->registerCallBack([this,box](){
            box->removeFromParent();
            this->scheduleUpdate();
        }, [](){
            SceneMediator::getInstance()->gotoStartScene();
        });
        this->addChild(box);
    });
}

void MemoryCardScene::startGame(){
    _currentLevel--;
    _scoreData = {0,0,1000};
    nextLevel();
}

void MemoryCardScene::nextLevel(){
    _currentLevel++;
    if (_currentLevel > allLevel) {
        _currentLevel = 0;
    }
    _nowLevelData = _levelDataList[_currentLevel];
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    _scoreData.maxCount = 0;
    _scoreData.energy = 1000;
    auto card = MemoryCardLevel::create(_nowLevelData);
    auto levelSize = card->getContentSize();
    card->ignoreAnchorPointForPosition(false);
    card->setAnchorPoint(Vec2(0.5, 0.5));
    card->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 50));
    auto scale = (visibleSize.height - 100)/levelSize.height;
    card->setScale(2);
    card->setOpacity(0);
    card->runAction(Spawn::create(ScaleTo::create(0.25, scale), FadeIn::create(0.25), NULL));
    this->addChild(card);
    std::shared_ptr<ScoreStratefyBase> ss(new ScoreStratefy());
    auto pairCallback = [&, ss](CardData *cardA, CardData *cardB){
        ss->execute(&_scoreData, cardA, cardB);
    };
    _nowCardLevel = card;
    card->registerCallFunc(pairCallback, [this](){
        CCLOG("pair complete!!");
        _nowCardLevel->removeFromParent();
        this->nextLevel();
    });
}

void MemoryCardScene::initLevelData(){
    auto str = FileUtils::getInstance()->getStringFromFile("leveldata.csv");
    std::vector<std::string> rowList;
    char *row = strtok((char*)str.c_str(), "\n");
    while (row) {
        rowList.push_back(row);
        row = strtok(nullptr, "\n");
    }
    for (auto row = rowList.begin(); row != rowList.end(); ++row) {
        char *rows = strtok((char*)row->c_str(), ",");
        char *colums = strtok(nullptr, ",");
        char *loss = strtok(nullptr, ",");
        if (rows == nullptr || colums == nullptr || loss == nullptr) {
            continue;
        }
        
        LevelData levelData = {};
        levelData.rows = atoi(rows);
        levelData.columns = atoi(colums);
        levelData.loss = atoi(loss);
        if (levelData.rows*levelData.columns < 0 || (levelData.rows*levelData.columns) % 2 != 0 || levelData.loss <= 0) {
            continue;
        }
        _levelDataList.push_back(levelData);
    }
    allLevel = _levelDataList.size();
}

void MemoryCardScene::update(float t){
    Layer::update(t);
    _scoreData.energy -= _nowLevelData.loss*t;
    if (_scoreData.energy > 1000) {
        _scoreData.energy = 1000;
    }
    if (_scoreData.energy < 0) {
        this->unscheduleUpdate();
        UserDefault::getInstance()->setIntegerForKey(NEW_SCORE, _scoreData.score);
        std::vector<int> ranks;
        ranks.push_back(_scoreData.score);
        for (int i = 0; i < 5; i++) {
            auto score = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d",RANK_SCORE,i).c_str(), 0);
            ranks.push_back(score);
        }
        std::sort(ranks.begin(), ranks.end(), std::greater<int>());
        for (int i = 0; i < 5; i++) {
            auto score = ranks[i];
            UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d",RANK_SCORE,i).c_str(), score);
        }
        SceneMediator::getInstance()->gotoStartScene();
    }
    _energyBar->updateProgress(_scoreData.energy);
    _scoreText->updateScore(_scoreData.score);
}
