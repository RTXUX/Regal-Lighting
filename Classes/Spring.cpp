#include "Spring.h"
Spring::Spring(int x, int y, int _side, int Area) {
	if(_side == 1)
		setSide(2);
	else setSide(1);
	setAttackArea(Area);
	setName("Spring");
	setBaseHp(1e9);
	setEffectiveHp(1e9);
	setBaseAttack(-30);
	setEffectiveAttack(0);
}

Spring::Spring() { }