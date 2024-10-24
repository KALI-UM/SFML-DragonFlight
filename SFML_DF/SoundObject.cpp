#include "pch.h"
#include "SoundObject.h"
#include "SFML/Audio.hpp"

SoundObject::SoundObject(const std::string& filepath, float volume, SoundType type)
	:m_IsValid(false), m_Type(type), m_DefaultVolume(volume), m_FadeOutSpeed(-1)
{
	sf::SoundBuffer* soundbuff = ResourceManager<sf::SoundBuffer>::GetInstance()->GetByFilepath(filepath);
	if (soundbuff)
	{
		SetIsValid(true);
		m_Sound.setBuffer(*soundbuff);
		m_Sound.setVolume(m_DefaultVolume * GM->GetGlobalVolume());
	}

	//if (m_Type == SoundType::Effect)
	//	m_Sound.setLoop(false);
	//else if (m_Type == SoundType::BGM)
	//	m_Sound.setLoop(true);
}

SoundObject::SoundObject(const SoundObject& other)
	:m_IsValid(false), m_Type(other.m_Type), m_DefaultVolume(other.m_DefaultVolume), m_FadeOutSpeed(-1)
{
	if (other.m_Sound.getBuffer())
	{
		SetIsValid(true);
		m_Sound = other.m_Sound;
		m_Sound.setVolume(m_DefaultVolume * GM->GetGlobalVolume());
	}
}

SoundObject::SoundObject(SoundObject&& other)
	:m_IsValid(other.m_IsValid), m_Type(other.m_Type), m_DefaultVolume(other.m_DefaultVolume), m_FadeOutSpeed(other.m_DefaultVolume)
{
	if (other.m_Sound.getBuffer())
	{
		m_Sound = other.m_Sound;
	}
	other.SetIsValid(false);
}

SoundObject::~SoundObject()
{
}

void SoundObject::Play()
{
	if (m_Type == SoundType::BGM)
	{
		if (!GetIsPlaying())
			m_Sound.play();
	}
	else
	{
		m_Sound.play();
	}
}

void SoundObject::Pause()
{
	m_Sound.pause();
}

void SoundObject::Stop()
{
	if (GetIsPlaying())
		m_Sound.stop();
}

void SoundObject::SetLoop(bool loop)
{
	m_Sound.setLoop(loop);
}

void SoundObject::Update(float dt)
{
	dt = FM->GetRealDeltaTime();
	if (m_FadeOutSpeed > 0)
	{
		float currv = m_Sound.getVolume() - dt * m_FadeOutSpeed;
		if (currv < 0.1)
		{
			Stop();
			m_Sound.setVolume(m_DefaultVolume * GM->GetGlobalVolume());
			m_FadeOutSpeed = -1;
		}
		else
		{
			m_Sound.setVolume(currv);
		}
	}
}

bool SoundObject::GetIsPlaying() const
{
	return ((int)m_Sound.getStatus() == (int)sf::Sound::Status::Playing);
}

void SoundObject::StartFadeOut(float duration)
{
	if (m_FadeOutSpeed > 0)return;	//이미 페이드아웃중

	float soundDuration = m_Sound.getBuffer()->getDuration().asSeconds();
	if (soundDuration < duration)
		duration = soundDuration;

	m_FadeOutSpeed = m_Sound.getVolume() / duration;
}
