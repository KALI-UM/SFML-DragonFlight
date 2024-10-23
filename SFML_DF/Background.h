#pragma once
#include "GameObject.h"

class DSprite;
class Background : public GameObject
{
public:
	Background();
	~Background();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void SetStopBackground();

	void Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));
	void Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1));

	DSprite* m_background1;
	DSprite* m_background2;
	

protected:
	float m_speed;
	static float m_XPos;
	static float m_YTopPos;
};

