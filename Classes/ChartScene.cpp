//
//  ChartScene.cpp
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#include "ChartScene.h"
#include "UserData.h"
#include "SceneMediator.h"

ChartScene::ChartScene()
:_background(nullptr),
_backBtn(nullptr),
_newScoreTitle(nullptr),
_newScoreText(nullptr),
_rankTitle(nullptr){
    
}

ChartScene::~ChartScene(){
    this->removeAllChildren();
}

Scene* ChartScene::createScene(){
    Scene* scene = Scene::create();
    ChartScene* layer = ChartScene::create();
    scene->addChild(layer);
    return scene;
}

bool ChartScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    _background = Background::create();
    this->addChild(_background);
    
    _backBtn = ui::Button::create("back.png");
    _backBtn->setAnchorPoint(Vec2(0, 1));
    _backBtn->setPosition(Vec2(0, visibleSize.height));
    this->addChild(_backBtn);
    
    _newScoreTitle = Sprite::create("new_score.png");
    _newScoreTitle->setAnchorPoint(Vec2(0, 1));
    _newScoreTitle->setPosition(Vec2(0, visibleSize.height - 50));
    this->addChild(_newScoreTitle);
    
    std::string score = StringUtils::format("%d", UserDefault::getInstance()->getIntegerForKey(NEW_SCORE, 0));
    _newScoreText = ui::TextAtlas::create(score, "number.png", 63, 83, "0");
    _newScoreText->setPosition(Vec2(visibleSize.width/2, visibleSize.height - 150));
    this->addChild(_newScoreText);
    
    _rankTitle = Sprite::create("charts_score.png");
    _rankTitle->setAnchorPoint(Vec2(0, 1));
    _rankTitle->setPosition(Vec2(0, visibleSize.height - 200));
    this->addChild(_rankTitle);
    
    _backBtn->addClickEventListener([](Ref* ref){
        SceneMediator::getInstance()->gotoStartScene();
    });
    
    for (int i = 0; i < 5; ++i) {
        std::string score = StringUtils::format("%d", UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", RANK_SCORE, i).c_str(), 0));
        auto row = createRankRow(i, score);
        row->setAnchorPoint(Vec2(0, 1));
        row->setPosition(Vec2(0, visibleSize.height - 200 - 65*(i+1)));
        this->addChild(row);
    }
    return true;
}

Node* ChartScene::createRankRow(int rank, std::string score){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto node = Node::create();
    node->setContentSize(Size(visibleSize.width, 100));
    auto r = ui::TextAtlas::create(StringUtils::format("%d",rank+1), "number.png", 63, 83, "0");
    r->setAnchorPoint(Vec2(0, 0));
    r->setPosition(Vec2(0, 0));
    node->addChild(r);
    auto s = ui::TextAtlas::create(score, "number.png", 63, 83, "0");
    s->setAnchorPoint(Vec2(1, 0));
    s->setPosition(Vec2(visibleSize.width,  0));
    node->addChild(s);
    return node;
}