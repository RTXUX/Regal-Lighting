/****************************************************
*destruct()�����ƻ������ж�
*���������ԣ�
*����Ѫ����500
*��ЧѪ����100
*�����˺���20
*��Ч�˺���40
*������Χ��2*2
****************************************************/
#pragma once
#include "Building.h"
class Defender :public Building {
public:
	virtual void destruct();
	Defender(int, int, int, int Area = 2);
	Defender();
};