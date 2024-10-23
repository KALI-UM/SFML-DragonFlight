#pragma once
#include "GameObject.h"


class DSprite;
class DRectangle;
class Monster;
class Character : public GameObject
{
public:
	Character();
	~Character();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void getMonster(std::vector<Monster*> *mons);

	DSprite* m_CharSprite;
	DRectangle* m_HitBox;
	sf::FloatRect m_ColliderBox;

protected:
	float m_speed;
	std::vector<Monster*>* m_Enemy;

};

