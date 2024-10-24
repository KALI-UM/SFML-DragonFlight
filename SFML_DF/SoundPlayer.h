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

class SoundObject;
class SoundPlayer :
    public GameObject
{
public:
	SoundPlayer();
	~SoundPlayer();  

	bool Initialize() override;
	void Reset()override;
	void Update(float dt)override;
	void Release() override;

	void PlayEffect(const std::string& filepath);
	void PlayBGM(const std::string& filepath);

	//void EffectFadeOut(const std::string& filepath, float duration);
	void BGMFadeOut(const std::string& filepath, float duration);
private:
	std::unordered_map<std::string, SoundObject*> m_Effects;
	std::unordered_map<std::string, SoundObject*> m_BGMs;

	std::vector<SoundObject*> m_BGM;
};
