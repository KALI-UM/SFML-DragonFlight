#pragma once
#include "GameObject.h"

class DSprite;
class DRectangle;
class Monster;
class P2_Score;
class DustEffect;
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
	void getMonster(std::vector<Monster*>* mons);
	void getScore(P2_Score* score);
	void GetEffect(std::vector< DustEffect*>* effects);

	DSprite* m_Bullet;
	DRectangle* m_HitBox;

protected:
	float m_Speed;
	std::vector<Monster*>* m_Enemy;
	P2_Score* m_Score;
	std::vector< DustEffect*>* m_Effects;
};

