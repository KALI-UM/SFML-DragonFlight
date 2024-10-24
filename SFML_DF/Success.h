#pragma once
#include "GameObject.h"

class DText;
class DRectangle;
class DSprite;
class Character;

class Success : public GameObject
{
public:
	Success();
	~Success();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void FadeOutBackGround(float speed);

	Character* m_Player;

protected:
	DSprite* m_SuccessBackground;
	DText* m_SuccessText[3];
	DRectangle* m_SuccessRect;

	float m_FadeOutSpeed = -1;
	float m_CurrvColorValue;

};

