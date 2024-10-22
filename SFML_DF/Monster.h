#pragma once
#include "GameObject.h"

class DSprite;
class Monster : public GameObject
{
public:
	Monster();
	~Monster();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DSprite* m_monster;

protected:
	float m_speed;

};

