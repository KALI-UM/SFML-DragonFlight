#pragma once
#include "GameObject.h"


class DAnimation;
class DRectangle;
class Monster;
class Character : public GameObject
{
public:
	Character();
	~Character();

	bool Initialize();
	void Reset();
	void Update(float dt);

	int RectCheck();						//true면 해당 몬스터의 인덱스를 false면 -1반환
	void SetStopCharacter();

	void getMonster(std::vector<Monster*> *mons);

	DAnimation* m_CharSprite;
	DRectangle* m_HitBox;
	sf::FloatRect m_ColliderBox;

protected:
	float m_speed;
	std::vector<Monster*>* m_Enemy;
};

