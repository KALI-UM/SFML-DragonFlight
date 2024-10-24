#include "pch.h"
#include "Background_Lobby.h"
#include "DSprite.h"
#include "SFML/Audio.hpp"

Background_Lobby::Background_Lobby()
{
}

Background_Lobby::~Background_Lobby()
{
}

bool Background_Lobby::Initialize()
{
	m_Logo = new DSprite("ui/logo.png", DrawType::UI);
	m_Background[0] = new DSprite("background/001.png", DrawType::Background);
	m_Background[1] = new DSprite("background/001.png", DrawType::Background);
	m_LobbyCharacter = new DSprite("ui/character_01.png", DrawType::Normal);
	m_BackgroundMusic = new sf::Sound();
	m_BackgroundMusic->setBuffer(*ResourceManager<sf::SoundBuffer>::GetInstance()->GetByFilepath("sound/dragon_flight.mp3"));
	m_ClickEffect = new sf::Sound();
	m_ClickEffect->setBuffer(*ResourceManager<sf::SoundBuffer>::GetInstance()->GetByFilepath("sound/ButtonClick.wav"));

	SetDrawable(m_Background[0]);
	SetDrawable(m_Background[1]);
	SetDrawable(m_LobbyCharacter);
	SetDrawable(m_Logo);
	Reset();
	return false;
}

void Background_Lobby::Reset()
{
	m_BgmVolume = 50;
	m_BackgroundMusic->setLoop(true);
	m_BackgroundMusic->setVolume(m_BgmVolume * GM->GetGlobalVolume());
	m_Logo->SetOriginCenter();
	m_Logo->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 4);
	m_LobbyCharacter->SetOriginCenter();
	m_LobbyCharacter->Transform()->setScale(0.5f, 0.5f);
	m_LobbyCharacter->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
	m_FadeOutSpeed = -1;
	m_CurrvColorValue = 150;
	m_Background[0]->SetColor(m_CurrvColorValue, m_CurrvColorValue, m_CurrvColorValue);
	m_Background[1]->SetColor(m_CurrvColorValue, m_CurrvColorValue, m_CurrvColorValue);
}

void Background_Lobby::Update(float dt)
{
	if (m_BackgroundMusic->getStatus() != sf::SoundSource::Status::Playing)
		m_BackgroundMusic->play();

	if (m_FadeOutSpeed > 0)
	{
		m_CurrvColorValue = m_CurrvColorValue + (dt * m_FadeOutSpeed);
		m_Background[0]->SetColor(m_CurrvColorValue, m_CurrvColorValue, m_CurrvColorValue);
		m_Background[1]->SetColor(m_CurrvColorValue, m_CurrvColorValue, m_CurrvColorValue);
		m_BgmVolume = m_BgmVolume - (dt * m_FadeOutSpeed);

		if (m_BgmVolume < 1)m_BgmVolume = 0;
		m_BackgroundMusic->setVolume(m_BgmVolume * GM->GetGlobalVolume());

		if (m_CurrvColorValue >= 255)
		{
			m_BackgroundMusic->stop();
			SM->ChangeScene("Play1");
		}
	}
}

void Background_Lobby::FadeOutBackGround(float speed)
{
	m_FadeOutSpeed = speed;
}
