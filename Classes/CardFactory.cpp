//
//  CardFactory.cpp
//  MemoryCards
//
//  Created by zh on 15-7-9.
//
//

#include "CardFactory.h"
#include "Card.h"
#include "ui/CocosGUI.h"

ICard* CardFactory::createCard(int backId, int number) {
    //const int cardSize = 256;
    if (backId<0 || backId >=8) {
        backId = 0;
    }
    
    
    auto texture = Director::getInstance()->getTextureCache()->addImage("card_back.png");
    float cardSize = texture->getContentSize().width/2;
    int x = (backId%2)*cardSize;
    int y = (backId/2)*cardSize;
    auto backImage = Sprite::createWithTexture(texture, Rect(x, y, cardSize, cardSize));
    //auto backImage = Sprite::create("card_back.png");
    //log("%f -- %f",backImage->getContentSize().width,backImage->getContentSize().height);
    
    auto frontImage = Node::create();
    //frontImage->setPosition(Vec2(300,300));
    auto sp = Sprite::create("card_front.png");
    sp->setAnchorPoint(Vec2(0,0));
    frontImage->addChild(sp);
    
   // auto numberText = ui::TextAtlas::create(StringUtils::format("%d", number), "card_number.png", 1400, 140, "0");
    //frontImage->addChild(numberText);
    
    CardData data = {};
    data.number = number;
    
    auto card = Card::create();
    card->setBackImage(backImage);
    card->setFrontImage(frontImage);
    card->setCardData(data);
    
    return card;
}