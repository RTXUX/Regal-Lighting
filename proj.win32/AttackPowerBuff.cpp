#include "AttackPowerBuff.h"



AttackPowerBuff::AttackPowerBuff() : Buff(host), duration(5)
{
}


AttackPowerBuff::~AttackPowerBuff()
{
}

bool AttackPowerBuff::shouldRemove() {
	if (duration < 0) {
		return true;
	}
	return false;
}
int AttackPowerBuff::remove() {
	host->setEffectiveAttack(-effectiveAttackPower);
	effective = false;
}
int AttackPowerBuff::enEffect() {
	effectiveAttackPower = host->getBaseAttack() * 0.3;
	host->setEffectiveAttack(effectiveAttackPower); // Ôö¼Ó30%¹¥»÷Á¦
	effective = true;
}
bool AttackPowerBuff::isEffective() {
	return effective;
}
bool AttackPowerBuff::disEffect() {
	return !effective;
}

int AttackPowerBuff::getDuration() const {
	return duration;
}

void AttackPowerBuff::decreaseDuration(int sec) {
	duration -= sec;
}