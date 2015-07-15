#include "HelloWorldScene.h"
#include "Card.h"
#include "CardFactory.h"
#include "MemoryCardLevel.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    LevelData data = {};
    data.rows = 4;
    data.columns = 2;
    auto card = MemoryCardLevel::create(data);
    auto levelSize = card->getContentSize();
    card->ignoreAnchorPointForPosition(false);
    card->setAnchorPoint(Vec2(0.5, 0.5));
    card->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    auto scale = visibleSize.height/levelSize.height;
    card->setScale(scale);
    this->addChild(card);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
