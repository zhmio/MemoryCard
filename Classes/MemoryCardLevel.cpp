//
//  MemoryCardLevel.cpp
//  MemoryCards
//
//  Created by zh on 15-7-10.
//
//

#include "MemoryCardLevel.h"
#include "CardFactory.h"

using namespace std;

MemoryCardLevel::MemoryCardLevel():
_unfinishedCard(0),
_selCardA(nullptr),
_selCardB(nullptr){
    
}

MemoryCardLevel::~MemoryCardLevel() {
    this->removeAllChildren();
    _eventDispatcher->removeAllEventListeners();
}

MemoryCardLevel* MemoryCardLevel::create(LevelData data) {
    MemoryCardLevel *pRet = new(std::nothrow) MemoryCardLevel();
    if (pRet && pRet->init(data))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool MemoryCardLevel::init(LevelData data) {
    if (!Layer::init()) {
        return false;
    }
    _levelData = data;
    initCardLayout();
    initEventTouch();
    return true;
}

void MemoryCardLevel::initCardLayout() {
    int backId = CCRANDOM_0_1()*8;
    
    //初始化table
    for (int i = 0; i < _levelData.rows; ++i) {
        vector<Card*> r(_levelData.columns);
        _table.push_back(r);
    }
    
    int number = 0;
    int nums = _levelData.rows*_levelData.columns;
    float cardSize = 0;
    for (int i = 0; i < nums; ++i) {
        //实例化卡片
        Card *card = dynamic_cast<Card*>(CardFactory::createCard(backId, number/2));
        card->getCardData()->row = i/2;
        card->getCardData()->column = i%2;
        
        cardSize = card->getContentSize().width;
        card->setAnchorPoint(Vec2(0.5, 0.5));
        card->setPosition(Vec2(i%2*cardSize + cardSize/2, i/2*cardSize + cardSize/2));
        this->addChild(card);
        _table[i/2][i%2] = card;
        
        number++;
    }
    //Card *card = dynamic_cast<Card*>(CardFactory::createCard(backId, number));
    //this->addChild(card);
    //this->setPosition(Vec2(300, 300));
    this->setContentSize(Size(cardSize*_levelData.columns, cardSize*_levelData.rows));
}

void MemoryCardLevel::initEventTouch() {
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch *touch, Event *event){
        auto point = this->convertToNodeSpace(touch->getLocation());
        auto size = this->getContentSize();
        auto rect = Rect(0, 0, size.width, size.height);
        if (rect.containsPoint(point)) {
            return true;
        }
        return false;
    };
    listener->onTouchEnded = [=](Touch *touch, Event *event) {
        auto point = this->convertToNodeSpace(touch->getLocation());
        for (int i = 0; i < _levelData.rows; ++i) {
            auto rows = _table[i];
            for (int j = 0; j < _levelData.columns; ++j) {
                auto card = rows[j];
                if (card == nullptr) {
                    continue;
                }
                auto pos = card->getPosition();
                auto size = card->getContentSize();
                auto rect = Rect(pos.x - size.width/2, pos.y - size.height/2, size.width, size.height);
                if (rect.containsPoint(point)) {
                    if (_selCardA == nullptr) {
                        //第一次选择
                        //log("%d -- %d",card->getCardData()->row, card->getCardData()->column);
                        
                        card->flipToFront();
                        _selCardA = card;
                        break;
                    } else {
                        card->flipToFront();
                        if (card->getCardData()->number == _selCardA->getCardData()->number) {
                            _selCardB = card;
                            auto fade = FadeOut::create(2);
                            //_selCardA->runAction(Sequence::create(fade, NULL));
                            _selCardB->runAction(fade);
                        } else {
                            _selCardA->flipToBack();
                            _selCardB->flipToBack();
                        }
                        //_selCardA = nullptr;
                        //_selCardB = nullptr;
                    }
                }
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}