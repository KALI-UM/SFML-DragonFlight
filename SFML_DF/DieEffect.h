#pragma once
#include "GameObject.h"
class DSprite;
class DieEffect :
    public GameObject
{
public:
	DieEffect();
	~DieEffect();

	bool Initialize();
	void Reset();
	void Update(float dt);
	void Effect(const sf::Vector2f& point);
private:
	std::vector<DSprite*> m_Dusts;
	float m_Speed;
	float m_Offset;
};

