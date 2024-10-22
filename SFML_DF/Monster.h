#pragma once
#include "GameObject.h"

class DSprite;
class DRectangle;
class Monster : public GameObject
{
public:
	Monster();
	~Monster();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DSprite* m_monster;
	DRectangle* m_HitBox;


protected:
	float m_speed;

};

