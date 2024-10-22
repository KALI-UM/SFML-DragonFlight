#pragma once
#include "GameObject.h"


class DSprite;
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

protected:
	float m_speed;

};

