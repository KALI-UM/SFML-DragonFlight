#pragma once
#include "GameObject.h"

namespace sf
{
	class Sound;
}

enum class SoundEffect
{
	Click,
	NextScene,
};

class SoundObject :
    public GameObject
{
public:
	SoundObject();
	~SoundObject();  

	bool Initialize() override;
	void Reset()override;
	void Update(float dt)override;

	void PlayEffect(const SoundEffect& effect);
private:
	std::vector<sf::Sound*> m_Effect;
};

