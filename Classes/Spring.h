/**********************************************************
*Ȫˮ��
*destruct()--û���ƻ�����
*�ظ�����ÿ��30��

***********************************************************/
#pragma once
#include"Building.h"
class Spring :public Building {
public:
	virtual void destruct() { }
	Spring(int, int, int, int Area = 3);
	Spring();
};