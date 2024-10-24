#pragma once
#include "GameObject.h"

class DText;
class DRectangle;
class DSprite;
class Character;
class P1_GameOver : public GameObject
{
public:
	P1_GameOver();
	~P1_GameOver();

	bool Initialize();
	void Reset();
	void Update(float dt);


	Character* m_Player;

protected:
	DSprite* m_GameOverBackground;
	DText* m_GameOverText[3];
	DRectangle* m_GameOverRect;
};

