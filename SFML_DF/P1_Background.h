#pragma once
#include "GameObject.h"

class DSprite;
class P1_Backgound : public GameObject
{
public:
	P1_Backgound();
	~P1_Backgound();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void SetStopBackground();

	void Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));
	void Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));

	DSprite* m_P1_Background1;
	DSprite* m_P1_Background2;
	

protected:
	float m_Speed;
	static float m_XPos;
	static float m_YTopPos;
};

