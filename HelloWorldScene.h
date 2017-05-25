#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "Box2D.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Sprite* downBar;
    Sprite* upBar;
    Node* bird;
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void onEnter();
    
    void addEdges();
    
    void startGame();
    void stopGame();
    
    void BeginContact();
    
private:
    void addLand();
    void addBird();
    void addBar(float dt);
    void initWorld();
};

#endif // __HELLOWORLD_SCENE_H__
