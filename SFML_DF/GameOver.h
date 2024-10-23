#pragma once
#include "GameObject.h"

class DText;
class GameOver : public GameObject
{
public:
	GameOver();
	~GameOver();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DText* m_GameOver;

protected:


};

