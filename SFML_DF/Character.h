#pragma once
#include "GameObject.h"


class DSprite;
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

	void getMonster(Monster* mons);

	DSprite* m_CharSprite;
	DRectangle* m_HitBox;

protected:
	float m_speed;
	Monster* m_Enemy;

};

