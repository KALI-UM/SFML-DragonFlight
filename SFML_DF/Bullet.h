#pragma once
#include "GameObject.h"

class DSprite;
class DRectangle;

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void Shoot(const sf::Vector2f& shootPoint);
	bool BulletRectCheck();

	DSprite* m_Bullet;
	DRectangle* m_HitBox;

protected:
	float m_Speed;
};

