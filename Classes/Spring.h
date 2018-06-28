/**********************************************************
*泉水类
*destruct()--没有破坏条件
*回复量：每秒30点

***********************************************************/
#pragma once
#include"Building.h"
class Spring :public Building {
public:
	virtual void destruct() { }
	Spring(int, int, int, int Area = 3);
	Spring();
};