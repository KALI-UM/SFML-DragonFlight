#pragma once
#include "GameObject.h"

class DText;
class Score : public GameObject
{
public:
	Score();
	~Score();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DText* m_scoreText;
	float m_Score = 0;

protected:


};

