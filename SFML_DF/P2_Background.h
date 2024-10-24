#pragma once
#include "GameObject.h"

class DSprite;
class P2_Background : public GameObject
{
public:
	P2_Background();
	~P2_Background();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void SetStopBackground();

	void Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));
	void Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));

	DSprite* m_P2_Background1;
	DSprite* m_P2_Background2;

protected:
	float m_Speed;
	static float m_XPos;
	static float m_YTopPos;
};

