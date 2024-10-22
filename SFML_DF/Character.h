#pragma once
#include "GameObject.h"

class DSprite;
class Character : public GameObject
{
public:
	Character();
	~Character();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DSprite* m_CharSprite;

protected:
	float m_speed;

};

