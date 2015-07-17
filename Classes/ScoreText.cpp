//
//  ScoreText.cpp
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#include "ScoreText.h"

bool ScoreText::init(){
    if (!Node::init()) {
        return false;
    }
    _text = ui::TextAtlas::create("0", "number.png", 63, 83, "0");
    _text->setAnchorPoint(Vec2(1, 0.5));
    this->addChild(_text);
    return true;
}

void ScoreText::updateScore(int value){
    if (value == _score) {
        return;
    }
    _score = value;
    _text->setString(StringUtils::format("%d",value));
    auto effect = _text->clone();
    effect->runAction(Sequence::create(Spawn::create(ScaleTo::create(0.25, 2), FadeOut::create(0.25), NULL), CallFunc::create([effect](){
        effect->removeFromParent();
    }), NULL));
    this->addChild(effect);
}