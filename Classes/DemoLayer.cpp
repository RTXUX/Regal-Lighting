#include "DemoLayer.h"

USING_NS_CC;

DemoLayer::DemoLayer()
{
}


void DemoLayer::update(float delta)
{
	Layer::update(delta);
	updateSpeed();

}

void DemoLayer::keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode)
{
	int offsetX = 0, offsetY = 0;
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_A:
		offsetX -= 2;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		offsetX += 2;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		offsetY += 2;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		offsetY -= 2;
		break;
	default:
		offsetX = offsetY = 0;
		break;
	}
	auto moveBy = MoveBy::create(0.2, Vec2(offsetX, offsetY));
	//auto moveTo = MoveTo::create(0.3, Vec2(sprite->getPositionX() + offsetX, sprite->getPositionY() + offsetY));
	sprite->runAction(moveBy);
}

void DemoLayer::updateSpeed()
{
	//sprite->getPhysicsBody()->setVelocity(Vec2(0,0));
	Vec2 v;
	if (keys[EventKeyboard::KeyCode::KEY_A])
	{
		v.x -= 100;
	}
	if (keys[EventKeyboard::KeyCode::KEY_D])
	{
		v.x += 100;
	}
	if (keys[EventKeyboard::KeyCode::KEY_W])
	{
		v.y += 100;
	}
	if (keys[EventKeyboard::KeyCode::KEY_S])
	{
		v.y -= 100;
	}
	v*=sprite->getPhysicsBody()->getMass();
	sprite->getPhysicsBody()->applyImpulse(v);

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

	this->scheduleUpdate();
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event * event)
	{
		//log("%d pressed", keyCode);
		keys[keyCode] = true;
	};
	listener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event * event)
	{
		//log("%d released", keyCode);
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	/*sprite = Sprite::create("Soldier.png");
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);*/

	{
		auto closeItem = MenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			[](Ref* pSender)
		{
			Director::getInstance()->end();
		});

		if (closeItem == nullptr ||
			closeItem->getContentSize().width <= 0 ||
			closeItem->getContentSize().height <= 0)
		{
		
		}
		else
		{
			float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
			float y = origin.y + closeItem->getContentSize().height / 2;
			closeItem->setPosition(Vec2(x, y));
		}

		// create menu, it's an autorelease object
		auto menu = Menu::create(closeItem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);
	}
	auto edgeBox = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT);
	edgeBox->getShape(0)->setRestitution(PHYSICS_INFINITY);
	log("Mass is %lf",edgeBox->getMass());
	{
		auto node = Node::create();
		node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
		node->setPhysicsBody(edgeBox);
		addChild(node);
	}
	{
		sprite = Sprite::create("Soldier.png");
		auto body = PhysicsBody::createBox(sprite->getContentSize());
		body->getShape(0)->setFriction(0);
		body->getShape(0)->setRestitution(0);
		body->setCategoryBitmask(1);
		body->setCollisionBitmask(1);
		body->setContactTestBitmask(1);
		body->setGravityEnable(true);
		body->setMass(0.0000001f);
		body->setDynamic(true);
		body->setRotationEnable(false);
		sprite->setPhysicsBody(body);
		sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
		addChild(sprite);
	}
	return true;
}
