#include "pch.h"
#include "SoundObject.h"
#include "SFML/Audio.hpp"

SoundObject::SoundObject()
{
}

SoundObject::~SoundObject()
{
}

bool SoundObject::Initialize()
{
	sf::Sound* sound;
	sound = new sf::Sound();
	sound->setBuffer(*ResourceManager<sf::SoundBuffer>::GetInstance()->GetByFilepath("sound/ButtonClick.wav"));
	m_Effect.push_back(sound);

	sound = new sf::Sound();
	sound->setBuffer(*ResourceManager<sf::SoundBuffer>::GetInstance()->GetByFilepath("sound/NextScene.wav"));
	m_Effect.push_back(sound);

	return false;
}

void SoundObject::Reset()
{
	for (auto& sound : m_Effect)
	{
		sound->setVolume(100 * GM->GetGlobalVolume());
	}
}

void SoundObject::Update(float dt)
{
}

void SoundObject::PlayEffect(const SoundEffect& effect)
{
	if ((int)effect >= m_Effect.size())
	{
		std::cout << "�������� �ʴ� ����Ʈ ���� �Դϴ�.\n";
		return;
	}

	if (m_Effect[(int)effect]->getStatus() != sf::SoundSource::Status::Playing)
		m_Effect[(int)effect]->play();
}
