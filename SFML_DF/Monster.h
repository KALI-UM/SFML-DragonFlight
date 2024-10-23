#pragma once
#include "GameObject.h"

class DSprite;
class DRectangle;
class DCircle;
class Monster : public GameObject
{
public:
	Monster();
	~Monster();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void SetStopMonster();

	void Set(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale = sf::Vector2f(1, 1), bool origincenter=true);

	DSprite* m_monster;
	DRectangle* m_HitBox;


protected:
	float m_speed;

};

