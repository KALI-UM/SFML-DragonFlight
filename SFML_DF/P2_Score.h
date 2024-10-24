#pragma once
#include "GameObject.h"

class DText;
class Bullet;
class P2_Score : public GameObject
{
public:
	P2_Score();
	~P2_Score();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DText* m_scoreText;
	Bullet* m_Bullet;
	float m_IncreaseScore = 0;
};

