#pragma once
#include "GameObject.h"

class DText;
class DRectangle;
class DSprite;
class Character;

class P2_GameOver : public GameObject
{
public:
	P2_GameOver();
	~P2_GameOver();

	bool Initialize();
	void Reset();
	void Update(float dt);


	Character* m_Player;

protected:
	DSprite* m_GameOverBackground;
	DText* m_GameOverText[3];
	DRectangle* m_GameOverRect;

};

