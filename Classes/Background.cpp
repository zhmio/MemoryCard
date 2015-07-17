//
//  Background.cpp
//  MemoryCards
//
//  Created by zh on 15-7-16.
//
//

#include "Background.h"

Background::Background(){
    
}

Background::~Background(){
    this->unscheduleUpdate();
}

bool Background::init(){
    if (!Node::init()) {
        return false;
    }
    background = Sprite::create("background.png");
    background->setAnchorPoint(Vec2(0, 0));
    Texture2D::TexParams params{GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    auto visibleSize = Director::getInstance()->getVisibleSize();
    background->getTexture()->setTexParameters(params);
    auto rect = Rect(0, 0, visibleSize.width, visibleSize.height);
    background->setTextureRect(rect);
    this->addChild(background);
    this->scheduleUpdate();
    return true;
}

void Background::update(float t){
    Node::update(t);
    auto rect = background->getTextureRect();
    rect.origin.x += 100*t;
    rect.origin.y += 100*t;
    background->setTextureRect(rect);
}