#pragma once

#include "cocos2d.h"
class DemoLayer : public cocos2d::Layer
{
private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	cocos2d::Sprite*  sprite;
public:
	DemoLayer();
	virtual bool init();
	CREATE_FUNC(DemoLayer);
	virtual void update(float delta) override;
	virtual void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode);
	virtual void updateSpeed();
	~DemoLayer();
};

