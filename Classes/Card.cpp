//
//  Card.cpp
//  MemoryCards
//
//  Created by zh on 15-7-9.
//
//

#include "Card.h"

Card::Card():
_backImage(nullptr),
_frontImage(nullptr),
_cardState(CardState::BACK) {
    this->setCascadeColorEnabled(true);
}

Card::~Card() {
    this->removeAllChildren();
}

bool Card::init() {
    if (!Node::init()) {
        return false;
    }
    return true;
}

Node* Card::getBackImage() {
    return _backImage;
}

Node* Card::getFrontImage() {
    return _frontImage;
}

void Card::setBackImage(cocos2d::Node *var) {
    if (var == nullptr) {
        return;
    }
    if (_backImage != nullptr) {
        _backImage->removeFromParent();
    }
    _backImage = var;
    _backImage->setCascadeOpacityEnabled(true);//设置子sprite随父sprite透明度变化
    _backImage->setVisible(true);
    //_backImage->setAnchorPoint(Vec2(0, 0));
    this->setContentSize(_backImage->getContentSize());
    addChild(_backImage);
}

void Card::setFrontImage(cocos2d::Node *var) {
    if (var == nullptr) {
        return;
    }
    if (_frontImage != nullptr) {
        _frontImage->removeFromParent();
    }
    _frontImage = var;
    _frontImage->setCascadeOpacityEnabled(true);
    _frontImage->setVisible(false);
    //_frontImage->setAnchorPoint(Vec2(0, 0));
    addChild(_frontImage);
}

void Card::flipFromTo(cocos2d::Node *a, cocos2d::Node *b, const std::function<void()> &callback) {
    if (nullptr == a || nullptr == b) {
        return;
    }
    
    //初始化属性
    
    a->stopAllActions();
    b->stopAllActions();
    
    a->setVisible(true);
    a->setScaleX(1.0f);
    
    b->setVisible(false);
    b->setScaleX(0);
    
    
    //翻出B
    
    auto flipB = [a, b,callback](){
        a->setVisible(false);
        b->setVisible(true);
        
        CallFunc* func=nullptr;
        if (callback!=nullptr) {
            func=CallFunc::create(callback);
        }
        
        b->runAction(Sequence::create(
                                      ScaleTo::create(0.125f, 1.0f, 1.0f),
                                      func,
                                      NULL));
    };
    
    //翻入A
    
    a->runAction(Sequence::create(
                                  ScaleTo::create(0.125f, 0, 1.0f),
                                  CallFunc::create(flipB)
                                  , NULL));
}

void Card::flipToBack(const std::function<void()> &callback) {
    if (_cardState == CardState::BACK) {
        return;
    }
    flipFromTo(_frontImage, _backImage, callback);
    _cardState = CardState::BACK;
}

void Card::flipToFront(const std::function<void()> &callback) {
    if (_cardState == CardState::FRONT) {
        return;
    }
    //_backImage->setVisible(false);
    //_frontImage->setVisible(true);
    flipFromTo(_backImage, _frontImage, callback);
    _cardState = CardState::FRONT;
}

CardState Card::getCardState() {
    return _cardState;
}

void Card::setCardData(CardData data) {
    _cardData = data;
}

CardData* Card::getCardData() {
    return &_cardData;
}

