#pragma once
#include "GameObject.h"

class DSprite;
class EffectObject :
    public GameObject
{
public:
	EffectObject();
	~EffectObject();

	bool Initialize();
	void Reset();
	void Update(float dt);

	void Effect(float lifetime, const sf::Vector2f& point);
private:
	std::vector<DSprite*> m_Parts;
	float m_LifeTime;					//몇초동안 재생될 effect인가  
};

