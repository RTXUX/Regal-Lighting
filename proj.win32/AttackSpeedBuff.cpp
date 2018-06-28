#include "AttackSpeedBuff.h"



AttackSpeedBuff::AttackSpeedBuff() : Buff(host), duration(5), effectiveAttackSpeed()
{
}


AttackSpeedBuff::~AttackSpeedBuff()
{
}

bool AttackSpeedBuff::shouldRemove() {
	if (duration < 0) {
		return true;
	}
	return false;
}
int AttackSpeedBuff::remove() {
	host->setEffectiveAttack(-effectiveAttackSpeed);
	effective = false;
}
int AttackSpeedBuff::enEffect() {
	effectiveAttackSpeed = 0;
	host->setEffectiveAttack(effectiveAttackSpeed); // 增加60%攻击速度
	effective = true;
}
bool AttackSpeedBuff::isEffective() {
	return effective;
}
bool AttackSpeedBuff::disEffect() {
	return !effective;
}

int AttackSpeedBuff::getDuration() const {
	return duration;
}

void AttackSpeedBuff::decreaseDuration(int sec) {
	duration -= sec;
}