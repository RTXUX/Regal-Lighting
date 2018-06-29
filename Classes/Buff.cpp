#include "Buff.h"


/**
 *
 */
Buff::Buff(Unit* host, int duration) : host(host), duration(duration)
{
}

Buff::~Buff()
{
}

int Buff::getTimeLeft() const {
	RWorld* rWorld = RWorld::getInstance();
	float offset = duration - (rWorld->getTime() - effectiveTime);
	return offset > 0 ? offset : 0;
}

float Buff::getEffectiveTime() const {
	return effectiveTime;
}

AttackPowerBuff::AttackPowerBuff() : Buff(host, 5)
{
}


AttackPowerBuff::~AttackPowerBuff()
{
}

bool AttackPowerBuff::shouldRemove() {
	return getTimeLeft() == 0;
}
int AttackPowerBuff::remove() {
	host->setEffectiveAttack(-effectiveValue);
	effective = false;
}
int AttackPowerBuff::enEffect() {
	effectiveValue = host->getBaseAttack() * 0.3;
	host->setEffectiveAttack(effectiveValue); // 增加30%攻击力
	effective = true;
}
bool AttackPowerBuff::isEffective() {
	return effective;
}
bool AttackPowerBuff::disEffect() {
	return !effective;
}

MovingSpeedBuff::MovingSpeedBuff() : Buff(host, 10)
{
}


MovingSpeedBuff::~MovingSpeedBuff()
{
}

bool MovingSpeedBuff::shouldRemove() {
	return getTimeLeft() == 0;
}
int MovingSpeedBuff::remove() {
	host->setEffectiveAttack(-effectiveValue);
	effective = false;
}
int MovingSpeedBuff::enEffect() {
	effectiveValue = 0;
	host->setEffectiveAttack(effectiveValue); // 增加30%移动速度
	effective = true;
}
bool MovingSpeedBuff::isEffective() {
	return effective;
}
bool MovingSpeedBuff::disEffect() {
	return !effective;
}

AttackSpeedBuff::AttackSpeedBuff() : Buff(host, 5)
{
}


AttackSpeedBuff::~AttackSpeedBuff()
{
}

bool AttackSpeedBuff::shouldRemove() {
	return getTimeLeft() == 0;
}
int AttackSpeedBuff::remove() {
	host->setEffectiveAttack(-effectiveValue);
	effective = false;
}
int AttackSpeedBuff::enEffect() {
	effectiveValue = 0;
	host->setEffectiveAttack(effectiveValue); // 增加60%攻击速度
	effective = true;
}
bool AttackSpeedBuff::isEffective() {
	return effective;
}
bool AttackSpeedBuff::disEffect() {
	return !effective;
}