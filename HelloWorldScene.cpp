#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "AppDelegate.h"
#include "MyLayer.hpp"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = HelloWorld::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0,-100));
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
     auto visibleSize = Director::getInstance()->getVisibleSize();
     Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backGround = Sprite::create("bg_night.png");
    //backGround->setAnchorPoint(Vec2(0,0));
    backGround->setPosition(visibleSize/2);
    addChild(backGround);
    
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//    
//    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
    
//    auto backGround = Sprite::create("bg_night.png");
//    //backGround->setAnchorPoint(Vec2(0,0));
//    backGround->setPosition(visibleSize/2);
//    addChild(backGround);
//    
    //循环播放小鸟
//        auto bird = Sprite::create("bird0_0.png");
//        bird->setPosition(visibleSize/2);
//        addChild(bird);
//        bird = Sprite::create("bird0_1.png");
//        bird->setPosition(visibleSize/2);
//        addChild(bird);
//        bird = Sprite::create("bird0_2.png");
//        bird->setPosition(visibleSize/2);
//        addChild(bird);
//
//    auto title = Sprite::create("title.png");
//    title->setPositionX(visibleSize.width/2);
//    title->setPositionY(visibleSize.height/2+50);
//    addChild(title);
//    
//    auto land = Sprite::create("land.png");
//    land->setPositionX(visibleSize.width/2);
//    land->setPositionY(50);
//    addChild(land);
//    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = [](Touch *t, Event *e){
//        return false;
//    };
    
//    scheduleOnce([visibleSize](float f){
//        auto newScene = Scene::create();
//        auto newBackGround = Sprite::create("bg_day.png");
//        newBackGround->setPosition(visibleSize/2);
//        auto tutorial = Sprite::create("tutorial.png");
//        tutorial->setPosition(visibleSize/2);
//        auto layer = Layer::create();
////        auto land = Sprite::create("land.png");
////        land->setPositionX(visibleSize.width/2);
////        land->setPositionY(50);
////        newScene->addChild(land);
//        newScene->addChild(tutorial);
//        newScene->addChild(newBackGround);
//        
//        
//        
//        auto transition = TransitionCrossFade::create(1, newScene);
//        Director::getInstance()->replaceScene(transition);
//    }, 2,"test");
//    
//    MyLayer* layer1 = static_cast<MyLayer*>(Layer::create());
//    
//    auto listener = add
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this, layer1);

    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* touch, Event* event){
        log("hahahahah\n");
        //bird->runAction(MoveBy::create(0.5,Vec2(0, 20)));
//        bird->getPhysicsBody()->setRotationEnable(true);
//        bird->getPhysicsBody()->setRotationOffset(10);
        //bird->getPhysicsBody()->setAngularDamping(10);
        //bird->getPhysicsBody()->setMass(0.1);
     //   bird->getPhysicsBody()->setMoment(1000);
        //bird->getPhysicsBody()->setLinearDamping(10);
        //bird->getPhysicsBody()->setGravityEnable(false);
      //  bird->getPhysicsBody()->setAngularVelocity(5);
        bird->getPhysicsBody()->setVelocity(Vec2(0, 100));
        return false;};
    listener->setSwallowTouches(true);//不向下传递触摸
    dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    startGame();
    
    BeginContact();
    
    scheduleUpdate();
    
    return true;
}

void HelloWorld::startGame()
{
    scheduleUpdate();
    schedule(schedule_selector(HelloWorld::addBar),6);
}

void HelloWorld::stopGame()
{
    unscheduleUpdate();
    unschedule(schedule_selector(HelloWorld::addBar));
}

void HelloWorld::BeginContact()
{
    auto listener1 = EventListenerPhysicsContact::create();
    listener1->onContactBegin = [this](PhysicsContact& contact){
        //contact.getShapeA()->getBody()->getContactTestBitmask()
        log("onContactBegin");
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1,this);
}

void HelloWorld::addBar(float dt)
{
    float offset = -rand()%50;
    
    downBar = Sprite::create("pipe_up.png");
    downBar->setPhysicsBody(PhysicsBody::createEdgeBox(Size(downBar->getContentSize())));
    //go left with velocity 10 m/s
    downBar->getPhysicsBody()->setVelocity(Vec2(-20,0));
    downBar->setAnchorPoint(Vec2(0,0));
    downBar->setPositionX(visibleSize.width/2+144);
    downBar->setPositionY(offset);
    addChild(downBar);
    
    upBar = Sprite::create("pipe_down.png");
    upBar->setPhysicsBody(PhysicsBody::createEdgeBox(Size(upBar->getContentSize())));
    //go left with velocity 10 m/s
    upBar->getPhysicsBody()->setVelocity(Vec2(-20,0));
    upBar->setAnchorPoint(Vec2(0,0));
    upBar->setPositionX(visibleSize.width/2+144);
    upBar->setPositionY((downBar->getContentSize()).height+offset+100);
    //upBar->setPosition(visibleSize/2);
    addChild(upBar);
}

void HelloWorld::addLand()
{
    auto land = Sprite::create("land.png");
    land->setPhysicsBody(PhysicsBody::createEdgeSegment(Vec2(-(land->getContentSize()).width/2,(land->getContentSize()).height-35), Vec2((land->getContentSize()).width/2,(land->getContentSize()).height-35)));
    land->setPositionX(visibleSize.width/2);
    land->setPositionY(50);
    addChild(land);
}

void HelloWorld::onEnter()
{
    Scene::onEnter();
    
    addBird();
    
    addLand();
    
    addEdges();
    
    addBar(10);
}

void HelloWorld::addEdges()
{
    Size fuckSize;
    fuckSize.width = 144;
    fuckSize.height = 270;
    auto body = PhysicsBody::createEdgeBox(fuckSize);
    auto edgeShape = Node::create();
    edgeShape->setPhysicsBody(body);
    edgeShape->setPosition(visibleSize/2);
    addChild(edgeShape);
}

void HelloWorld::addBird()
{
    bird = Sprite::create("bird0_0.png");
    bird->setPhysicsBody(PhysicsBody::createCircle(5));//(bird->getContentSize()));
    bird->setPosition(visibleSize/2);
    addChild(bird);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
