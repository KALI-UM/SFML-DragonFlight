#pragma once
#include "GameObject.h"

class DText;
class DRectangle;
class DSprite;
class GameOver : public GameObject
{
public:
	GameOver();
	~GameOver();

	bool Initialize();
	void Reset();
	void Update(float dt);


protected:
	DSprite* m_GameOverBackground;
	DText* m_GameOverText[3];
	DRectangle* m_GameOverRect;


};

