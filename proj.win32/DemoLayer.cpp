#include "DemoLayer.h"

USING_NS_CC;

DemoLayer::DemoLayer()
{
}


DemoLayer::~DemoLayer()
{
}


bool DemoLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event * event)
	{
		log("%d pressed", keyCode);
		keys[keyCode] = true;
	};
	listener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event * event)
	{
		log("%d released", keyCode);
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	auto sprite = Sprite::create("Soldier.png");
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	return true;
}
