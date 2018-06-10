#pragma once

#include "cocos2d.h"
class DemoLayer : public cocos2d::Layer
{
private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
public:
	DemoLayer();
	virtual bool init();
	CREATE_FUNC(DemoLayer);

	~DemoLayer();
};

