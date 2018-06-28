#include"Defender.h"

void Defender::destruct() {
	
}

Defender::Defender(int x, int y, int _side, int Area) : Building(x, y) {
	setSide(_side);
	setAttackArea(Area);
	setName("Defender_tower");
	setBaseHp(500);
	setEffectiveHp(100);
	setBaseAttack(20);
	setEffectiveAttack(40);
}

Defender::Defender() { }