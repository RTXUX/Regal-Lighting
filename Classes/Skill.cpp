#include "Skill.h"
#include "Hero.h"
#include "RWorld.h"
#include "Utils.h"
#include "Buff.h"
#include <cmath>

/**
 * \brief 取得技能宿主单位
 * \return 此技能的宿主单位
 */
Unit* Skill::getHost() const
{
	return host;
}
/**
 * \brief 获取技能宿主单位，构建技能对象
 * \param ht 技能宿主单位
 */
Skill::Skill(Unit* ht)
{
	host = ht;
}
/**
 * \brief 取得当前技能剩余cd
 * \return 技能剩余cd
 */
int Skill::getCd() const
{
	int tim(0);
	RWorld* rWorld = RWorld::getInstance();
	tim = CD - (rWorld->getTime() - lastCast);
	if (tim > 0) return tim;
	else return 0;
}
/**
 * \brief 取得上次释放技能时间
 * \return 技能上次释放时间
 */
int Skill::getLastCast() const
{
	return lastCast;
}
/**
 *
 */
Skill::~Skill()
{
}
/**
 * \brief 构造试探技能对象
 * \param ht 技能宿主单位
 */
Probe::Probe(Unit* ht) :Skill(ht)
{
	CD = 10;
}
/**
 * \brief 技能作用：对3格范围内小兵造成300伤害
 */
int Probe::cast()
{
	cocos2d::Point posSelf = Utils::CoordinateTransform::cocosToTileMap(host->getPosition());
	cocos2d::Point posOther; int side_judge;
	RWorld* rWorld = RWorld::getInstance();
	list<shared_ptr<Unit>> Unit_pause = rWorld->getUnitRegistry();
	if (host->getSide() == 1) side_judge = 2;
	else side_judge = 1;
	for ( auto i = Unit_pause.begin(); i != Unit_pause.end(); i++)
	{
		shared_ptr<Unit> it = *i;
		posOther = Utils::CoordinateTransform::cocosToTileMap(it->getPosition());
		shared_ptr<Character> judge_C = dynamic_pointer_cast<Character>(it);
		shared_ptr<Hero> judge_H = dynamic_pointer_cast<Hero>(it);
		if (judge_C != nullptr&&judge_H == nullptr) {
			if(it->getSide()==side_judge)
			if (abs(posOther.x - posSelf.x) <= 2 && abs(posOther.y - posSelf.y) <= 2) {
				it->setEffectiveHp(it->getEffectiveHp() - 300);
			}
		}
	}
	return 0;
}
/**
 * \brief "试探"是否可以释放
 * \return "试探"是否可以释放
 */
bool Probe::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \brief 构造惩戒技能对象
 * \param ht 技能宿主单位
 */
Punishment::Punishment(Unit* ht) :Skill(ht)
{
	CD = 30;
}
/**
 * \brief 技能作用：对3格范围内小兵造成650伤害
 */
int Punishment::cast()
{
	cocos2d::Point posSelf = Utils::CoordinateTransform::cocosToTileMap(host->getPosition());
	cocos2d::Point posOther; int side_judge;
	RWorld* rWorld = RWorld::getInstance();
	if (host->getSide() == 1) side_judge = 2;
	else side_judge = 1;
	list<shared_ptr<Unit>> Unit_pause = rWorld->getUnitRegistry();
	for (auto i = Unit_pause.begin(); i != Unit_pause.end(); i++)
	{
		shared_ptr<Unit> it = *i;
		shared_ptr<Character> judge_C = dynamic_pointer_cast<Character>(it);
		shared_ptr<Hero> judge_H = dynamic_pointer_cast<Hero>(it);
		if (judge_C != nullptr&&judge_H == nullptr) {
			if (it->getSide() == side_judge)
			if (abs(posOther.x - posSelf.x) <= 2 && abs(posOther.y - posSelf.y) <= 2) {
				it->setEffectiveHp(it->getEffectiveHp() - 650);
			}
		}
	}
	return 0;
}
/**
 * \brief "惩戒"是否可以释放
 * \return "惩戒"是否可以释放
 */
bool Punishment::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \brief 构造斩杀技能对象
 * \param ht 技能宿主单位
 */
Execute::Execute(Unit* ht) :Skill(ht)
{
	CD = 90;
}
/**
 * \brief 技能作用：对5格范围内小兵与英雄造成已损失生命值12%伤害
 */
int Execute::cast()
{
	cocos2d::Point posSelf = Utils::CoordinateTransform::cocosToTileMap(host->getPosition());
	cocos2d::Point posOther; int side_judge;
	RWorld* rWorld = RWorld::getInstance();
	if (host->getSide() == 1) side_judge = 2;
	else side_judge = 1;
	list<shared_ptr<Unit>> Unit_pause = rWorld->getUnitRegistry();
	for (auto i = Unit_pause.begin(); i != Unit_pause.end(); i++)
	{
		shared_ptr<Unit> it = *i;
		shared_ptr<Character> judge_C = dynamic_pointer_cast<Character>(it);
		posOther = Utils::CoordinateTransform::cocosToTileMap(it->getPosition());
		if (judge_C != nullptr) {
			if (it->getSide() == side_judge)
			if (abs(posOther.x - posSelf.x) <= 4 && abs(posOther.y - posSelf.y) <= 4) {
				it->setEffectiveHp(it->getEffectiveHp() - ((it->getBaseHp() - it->getEffectiveHp())*0.12));
			}
		}
	}
	return 0;
}
/**
 * \brief "斩杀"是否可以释放
 * \return "斩杀"是否可以释放
 */
bool Execute::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried 构造狂暴技能对象
 * \param ht 技能宿主单位
 */
Rage::Rage(Unit* ht) :Skill(ht)
{
	CD = 60;
}
/**
 * \brief 技能作用：增加攻击力30%，增加攻击速度60%，持续5s
 */
int Rage::cast()
{
	Buffs::Rage rage;
	host->addBuff(rage);
	return 0;
}
/**
 * \brief "狂暴"是否可以释放
 * \return "狂暴"是否可以释放
 */
bool Rage::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried 构造幽灵疾步技能对象
 * \param ht 技能宿主单位
 */
Haste::Haste(Unit* ht) :Skill(ht)
{
	CD = 75;
}
/**
 * \brief 技能作用：增加移动速度30%，持续10s
 */
int Haste::cast()
{
	Buffs::Haste haste;
	host->addBuff(haste);
	return 0;
}
/**
 * \brief "幽灵疾步"是否可以释放
 * \return "幽灵疾步"是否可以释放
 */
bool Haste::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried 构造治疗术技能对象
 * \param ht 技能宿主单位
 */
Cure::Cure(Unit* ht) :Skill(ht)
{
	CD = 120;
}
/**
 * \brief 技能作用：恢复自己与5格范围内的所有我方人员已损失生命值40%
 */
int Cure::cast()
{
	cocos2d::Point posSelf = Utils::CoordinateTransform::cocosToTileMap(host->getPosition());
	cocos2d::Point posOther;
	RWorld* rWorld = RWorld::getInstance();
	list<shared_ptr<Unit>> Unit_pause = rWorld->getUnitRegistry();
	for (auto i = Unit_pause.begin(); i != Unit_pause.end(); i++)
	{
		shared_ptr<Unit> it = *i;
		shared_ptr<Character> judge_C = dynamic_pointer_cast<Character>(it);
		posOther = Utils::CoordinateTransform::cocosToTileMap(it->getPosition());
		if (judge_C != nullptr) {
			if (it->getSide() == host->getSide())
			if (abs(posOther.x - posSelf.x) <= 4 && abs(posOther.y - posSelf.y) <= 4) {
				it->setEffectiveHp(it->getEffectiveHp() + ((it->getBaseHp() - it->getEffectiveHp())*0.4));
			}
		}
	}
	return 0;
}
/**
 * \brief "治疗术"是否可以释放
 * \return "治疗术"是否可以释放
 */
bool Cure::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
