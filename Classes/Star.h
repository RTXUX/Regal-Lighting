/*********************************************************
*水晶类
*无伤害
*血量上限300
*建议：可以添加回复buff
*********************************************************/
#pragma once
#include "Building.h"
class Star :public Building {
public:
	virtual void destruct();
	Star(int, int, int, int Area = 2);
	Star();
};