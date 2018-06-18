/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "DemoLayer.h"
#include <stdio.h>
#include "RWorld.h"
USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	this->scheduleUpdate();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    /*auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "MainScene" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }*/

	//std::string file = "l1.tmx";
	//auto str = String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename(file.c_str()).c_str());
	RWorld::create();

	auto tileMap = TMXTiledMap::create("l1.tmx");
	auto metaLayer = tileMap->getLayer("meta");
	metaLayer->setVisible(false);
	this->addChild(tileMap);
	GameVars::initVars();
	auto listener = EventListenerKeyboard::create();
    {
		pWorld = b2WorldNode::create(0, 0);
		addChild(pWorld);
		auto border1 = b2Sprite::create("clear.png", Rect(0, 0, visibleSize.width, 2), b2BodyType::b2_staticBody, 0.0f, 0.0f);
		auto border2 = b2Sprite::create("clear.png", Rect(0, 0, visibleSize.width, 2), b2BodyType::b2_staticBody, 0.0f, 0.0f);
		auto border3 = b2Sprite::create("clear.png", Rect(0, 0, 2, visibleSize.height), b2BodyType::b2_staticBody, 0.0f, 0.0f);
		auto border4 = b2Sprite::create("clear.png", Rect(0, 0, 2, visibleSize.height), b2BodyType::b2_staticBody, 0.0f, 0.0f);
		pWorld->addChild(border1);
		pWorld->addChild(border2);
		pWorld->addChild(border3);
		pWorld->addChild(border4);
		border1->setPosition(visibleSize.width / 2, 1);
		border2->setPosition(visibleSize.width / 2, visibleSize.height - 1);
		border3->setPosition(1, visibleSize.height / 2);
		border4->setPosition(visibleSize.width - 1, visibleSize.height / 2);

    }
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

	hero1 = make_shared<Hero>(100, 100, 1);
	hero2 = make_shared<Hero>(100, 100, 1);
    {
		b2Sprite* sprite = b2Sprite::create("TestCube.png",b2BodyType::b2_dynamicBody,0.0f,0.0f);
		pWorld->addChild(sprite);
		sprite->setPosition(16, visibleSize.height / 2);
		sprite->getBody()->SetFixedRotation(true);
		hero1->setSprite(sprite);
		
    }
    {
		b2Sprite* sprite = b2Sprite::create("TestCube.png", b2BodyType::b2_dynamicBody, 0.0f, 0.0f);
		pWorld->addChild(sprite);
		sprite->setPosition(visibleSize.width-16, visibleSize.height / 2);
		sprite->getBody()->SetFixedRotation(true);
		hero2->setSprite(sprite);
    }

    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
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

void MainScene::update(float delta)
{
	Scene::update(delta);
	RWorld::getInstance()->setTime(RWorld::getInstance()->getTime() + delta);
	updateSpeedForHero1();
	updateSpeedForHero2();
	pWorld->update(delta);
}

void MainScene::updateSpeedForHero1()
{
	b2Sprite *sprite = dynamic_cast<b2Sprite*>(hero1->getSprite());
	b2Vec2 v(0.0f, 0.0f);
	sprite->getBody()->SetLinearVelocity(v);
	if (sprite==nullptr)
	{
		return;
	}
	if (keys[EventKeyboard::KeyCode::KEY_A])
	{
		v.x -= 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_D])
	{
		v.x += 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_W])
	{
		v.y += 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_S])
	{
		v.y -= 100.0f;
	}
	v.Normalize();
	//v *= 32;
	sprite->getBody()->SetLinearVelocity(v);
}

void MainScene::updateSpeedForHero2()
{
	b2Sprite *sprite = dynamic_cast<b2Sprite*>(hero2->getSprite());
	b2Vec2 v(0.0f, 0.0f);
	sprite->getBody()->SetLinearVelocity(v);
	if (sprite == nullptr)
	{
		return;
	}
	if (keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW])
	{
		v.x -= 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW])
	{
		v.x += 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_UP_ARROW])
	{
		v.y += 100.0f;
	}
	if (keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW])
	{
		v.y -= 100.0f;
	}
	v.Normalize();
	//v *= 32;
	sprite->getBody()->SetLinearVelocity(v);
}
