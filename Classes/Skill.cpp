#include "Skill.h"
#include "Hero.h"
#include "RWorld.h"
#include "Utils.h"
#include "Buff.h"
#include <cmath>

/**
 * \brief ȡ�ü���������λ
 * \return �˼��ܵ�������λ
 */
Unit* Skill::getHost() const
{
	return host;
}
/**
 * \brief ��ȡ����������λ���������ܶ���
 * \param ht ����������λ
 */
Skill::Skill(Unit* ht)
{
	host = ht;
}
/**
 * \brief ȡ�õ�ǰ����ʣ��cd
 * \return ����ʣ��cd
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
 * \brief ȡ���ϴ��ͷż���ʱ��
 * \return �����ϴ��ͷ�ʱ��
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
 * \brief ������̽���ܶ���
 * \param ht ����������λ
 */
Probe::Probe(Unit* ht) :Skill(ht)
{
	CD = 10;
}
/**
 * \brief �������ã���3��Χ��С�����300�˺�
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
 * \brief "��̽"�Ƿ�����ͷ�
 * \return "��̽"�Ƿ�����ͷ�
 */
bool Probe::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \brief ����ͽ似�ܶ���
 * \param ht ����������λ
 */
Punishment::Punishment(Unit* ht) :Skill(ht)
{
	CD = 30;
}
/**
 * \brief �������ã���3��Χ��С�����650�˺�
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
 * \brief "�ͽ�"�Ƿ�����ͷ�
 * \return "�ͽ�"�Ƿ�����ͷ�
 */
bool Punishment::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \brief ����նɱ���ܶ���
 * \param ht ����������λ
 */
Execute::Execute(Unit* ht) :Skill(ht)
{
	CD = 90;
}
/**
 * \brief �������ã���5��Χ��С����Ӣ���������ʧ����ֵ12%�˺�
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
 * \brief "նɱ"�Ƿ�����ͷ�
 * \return "նɱ"�Ƿ�����ͷ�
 */
bool Execute::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried ����񱩼��ܶ���
 * \param ht ����������λ
 */
Rage::Rage(Unit* ht) :Skill(ht)
{
	CD = 60;
}
/**
 * \brief �������ã����ӹ�����30%�����ӹ����ٶ�60%������5s
 */
int Rage::cast()
{
	Buffs::Rage rage;
	host->addBuff(rage);
	return 0;
}
/**
 * \brief "��"�Ƿ�����ͷ�
 * \return "��"�Ƿ�����ͷ�
 */
bool Rage::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried �������鼲�����ܶ���
 * \param ht ����������λ
 */
Haste::Haste(Unit* ht) :Skill(ht)
{
	CD = 75;
}
/**
 * \brief �������ã������ƶ��ٶ�30%������10s
 */
int Haste::cast()
{
	Buffs::Haste haste;
	host->addBuff(haste);
	return 0;
}
/**
 * \brief "���鼲��"�Ƿ�����ͷ�
 * \return "���鼲��"�Ƿ�����ͷ�
 */
bool Haste::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
/**
 * \bried �������������ܶ���
 * \param ht ����������λ
 */
Cure::Cure(Unit* ht) :Skill(ht)
{
	CD = 120;
}
/**
 * \brief �������ã��ָ��Լ���5��Χ�ڵ������ҷ���Ա����ʧ����ֵ40%
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
 * \brief "������"�Ƿ�����ͷ�
 * \return "������"�Ƿ�����ͷ�
 */
bool Cure::isCastable()
{
	if (this->getCd() == 0) return true;
	else return false;
}
