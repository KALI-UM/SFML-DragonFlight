#pragma once
#include "GameObject.h"


class DAnimation;
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

	int RectCheck();						//true�� �ش� ������ �ε����� false�� -1��ȯ
	void SetStopCharacter();

	void getMonster(std::vector<Monster*> *mons);

	DAnimation* m_CharSprite;
	DRectangle* m_HitBox;
	sf::FloatRect m_ColliderBox;

protected:
	float m_speed;
	std::vector<Monster*>* m_Enemy;
};

