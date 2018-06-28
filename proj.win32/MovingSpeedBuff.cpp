#include "MovingSpeedBuff.h"



MovingSpeedBuff::MovingSpeedBuff() : Buff(host), duration(10), effectiveMovingSpeed()
{
}


MovingSpeedBuff::~MovingSpeedBuff()
{
}

bool MovingSpeedBuff::shouldRemove() {
	if (duration < 0) {
		return true;
	}
	return false;
}
int MovingSpeedBuff::remove() {
	host->setEffectiveAttack(-effectiveMovingSpeed);
	effective = false;
}
int MovingSpeedBuff::enEffect() {
	effectiveMovingSpeed = 0;
	host->setEffectiveAttack(effectiveMovingSpeed); // 增加30%移动速度
	effective = true;
}
bool MovingSpeedBuff::isEffective() {
	return effective;
}
bool MovingSpeedBuff::disEffect() {
	return !effective;
}

int MovingSpeedBuff::getDuration() const {
	return duration;
}

void MovingSpeedBuff::decreaseDuration(int sec) {
	duration -= sec;
}