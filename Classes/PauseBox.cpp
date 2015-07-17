//
//  PauseBox.cpp
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#include "PauseBox.h"
#include "ui/CocosGUI.h"

bool PauseBox::init(){
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto background = LayerColor::create(Color4B(0, 0, 0, 200));
    auto box = ui::Scale9Sprite::create("message_box.png");
    auto continueBt = ui::Button::create("continue.png");
    auto endGameBt = ui::Button::create("end_game.png");
    
    box->setContentSize(Size(450, 300));
    box->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    continueBt->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 + 50));
    endGameBt->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 50));
    
    this->addChild(background);
    this->addChild(box);
    this->addChild(continueBt);
    this->addChild(endGameBt);
    
    continueBt->addClickEventListener([this](Ref *ref){
        if (_continueCallBack != nullptr) {
            _continueCallBack();
        }
    });
    
    endGameBt->addClickEventListener([this](Ref *ref){
        if (_endGameCallBack != nullptr) {
            _endGameCallBack();
        }
    });
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch,Event* event){return true;};
    listener->setSwallowTouches(true);
    
    background->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, background);
    
    return true;
}

void PauseBox::registerCallBack(std::function<void ()> continueCallBack, std::function<void ()> endGameCallBack){
    _continueCallBack = continueCallBack;
    _endGameCallBack = endGameCallBack;
}