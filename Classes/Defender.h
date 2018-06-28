/****************************************************
*destruct()——破坏条件判定
*防御塔属性：
*基础血量：500
*有效血量：100
*基础伤害：20
*有效伤害：40
*攻击范围：2*2
****************************************************/
#pragma once
#include "Building.h"
class Defender :public Building {
public:
	virtual void destruct();
	Defender(int, int, int, int Area = 2);
	Defender();
};