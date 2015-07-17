//
//  EnergyBar.cpp
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#include "EnergyBar.h"

bool EnergyBar::init(){
    if (!Node::init()) {
        return false;
    }
    _progress = ProgressTimer::create(Sprite::create("energy_front.png"));
    _progress->setType(ProgressTimer::Type::BAR);
    _progress->setMidpoint(Vec2(0, 0));
    _progress->setBarChangeRate(Vec2(1, 0));
    updateProgress(1000);
    _background = Sprite::create("energy_back.png");
    this->addChild(_background);
    this->addChild(_progress);
    this->setContentSize(_background->getContentSize());
    return true;
}

void EnergyBar::updateProgress(float p){
    auto percent = p/1000.0f*100.0f;
    //_progress->setPercentage(percent);
    if (abs(percent - _percent) > 1.0f) {
        _progress->runAction(EaseBackOut::create(ProgressTo::create(0.25, percent)));
        _percent = percent;
    }
}