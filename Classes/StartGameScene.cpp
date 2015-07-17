//
//  StartGameScene.cpp
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#include "StartGameScene.h"
#include "MemoryCardScene.h"
#include "SceneMediator.h"

StartGameScene::StartGameScene():
_background(nullptr),_logo(nullptr),
_startBtn(nullptr),_chartBtn(nullptr),_exitBtn(nullptr){
    
}

StartGameScene::~StartGameScene(){
    this->removeAllChildren();
}

Scene* StartGameScene::createScene(){
    Scene* scene = Scene::create();
    Layer* layer = StartGameScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartGameScene::init(){
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    _background = Background::create();
    this->addChild(_background);
    _logo = Sprite::create("logo.png");
    _logo->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 + 200));
    this->addChild(_logo);
    
    _startBtn = ui::Button::create("start.png");
    _startBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(_startBtn);
    
    _chartBtn = ui::Button::create("charts.png");
    _chartBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 100));
    this->addChild(_chartBtn);
    
    _exitBtn = ui::Button::create("exit.png");
    _exitBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 200));
    this->addChild(_exitBtn);
    
    _startBtn->addClickEventListener([](Ref *ref){
        SceneMediator::getInstance()->gotoGameScene();
    });
    _chartBtn->addClickEventListener([](Ref *ref){
        SceneMediator::getInstance()->gotoChartScene();
    });
    return true;
}