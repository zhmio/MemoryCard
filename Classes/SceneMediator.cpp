//
//  SceneMediator.cpp
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#include "SceneMediator.h"
#include "StartGameScene.h"
#include "ChartScene.h"
#include "MemoryCardScene.h"

SceneMediator* SceneMediator::_instance = nullptr;

SceneMediator* SceneMediator::getInstance(){
    if (_instance  == nullptr) {
        _instance = new SceneMediator();
    }
    return _instance;
}

void SceneMediator::gotoStartScene(){
    auto scene = StartGameScene::createScene();
    Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
}

void SceneMediator::gotoChartScene(){
    auto scene = ChartScene::createScene();
    Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
}

void SceneMediator::gotoGameScene(){
    auto scene = MemoryCardScene::createScene();
    Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.25, scene));
}