#pragma once
#include "SFML/Audio.hpp"

namespace sf
{
	class Sound;
}

enum class SoundType
{
	Effect,
	BGM
};

class SoundObject
{
public:
	SoundObject(const std::string& filepath, float volume, SoundType type);
	SoundObject(const SoundObject& other);
	SoundObject(SoundObject&& other);
	~SoundObject();

	void Play();
	void Pause();
	void Stop();
	void SetLoop(bool loop);

	void Update(float dt);
	bool GetIsValid()const { return m_IsValid; }
	void SetIsValid(bool valid) { m_IsValid = valid; }
	SoundType GetType()const { return m_Type; }
	bool GetIsPlaying()const;
	void StartFadeOut(float duration);
	//void StartFadeIn(float duration);
private:
	bool			m_IsValid;
	const SoundType	m_Type;
	sf::Sound		m_Sound;

	float			m_DefaultVolume;
	float			m_FadeOutSpeed;
	//float			m_FadeInSpeed;


};

