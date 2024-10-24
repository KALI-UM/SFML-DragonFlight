#pragma once
#include "GameObject.h"

class DText;
class DRectangle;
class DSprite;
class Character;
class GameOver : public GameObject
{
public:
	GameOver();
	~GameOver();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void FadeOutBackGround(float speed);

	Character* m_Player;

protected:
	DSprite* m_GameOverBackground;
	DText* m_GameOverText[3];
	DRectangle* m_GameOverRect;

	float m_FadeOutSpeed = -1;
	float m_CurrvColorValue;
};

