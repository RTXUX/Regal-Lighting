#include "Star.h"
void Star::destruct() {

}

Star::Star(int x, int y, int _side, int Area) {
	setSide(_side);
	setAttackArea(Area);
	setName("Star_tower");
	setBaseHp(200);
	setEffectiveHp(100);
	setBaseAttack(0);
	setEffectiveAttack(0);
}

Star::Star() { }