/*********************************************************
*ˮ����
*���˺�
*Ѫ������300
*���飺������ӻظ�buff
*********************************************************/
#pragma once
#include "Building.h"
class Star :public Building {
public:
	virtual void destruct();
	Star(int, int, int, int Area = 2);
	Star();
};