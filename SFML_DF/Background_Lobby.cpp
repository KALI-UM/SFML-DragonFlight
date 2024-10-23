#include "pch.h"
#include "Background_Lobby.h"
#include "DSprite.h"

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

	SetDrawable(m_Background[0]);
	SetDrawable(m_Background[1]);
	SetDrawable(m_LobbyCharacter);
	SetDrawable(m_Logo);
	Reset();
	return false;
}

void Background_Lobby::Reset()
{
	m_Logo->SetOriginCenter();
	m_Logo->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 4);
	m_LobbyCharacter->SetOriginCenter();
	m_LobbyCharacter->Transform()->setScale(0.8f, 0.8f);
	m_LobbyCharacter->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
	m_FadeOutSpeed = -1;
	currvColorValue = 150;
	m_Background[0]->SetColor(currvColorValue, currvColorValue, currvColorValue);
	m_Background[1]->SetColor(currvColorValue, currvColorValue, currvColorValue);
}

void Background_Lobby::Update(float dt)
{


	if (m_FadeOutSpeed > 0)
	{
		currvColorValue = currvColorValue +(dt * m_FadeOutSpeed);
		m_Background[0]->SetColor(currvColorValue, currvColorValue, currvColorValue);
		m_Background[1]->SetColor(currvColorValue, currvColorValue, currvColorValue);

		if (currvColorValue >=255)
		{
			SM->ChangeScene("Test");
		}
	}
}

void Background_Lobby::FadeOutBackGround(float speed)
{
	m_FadeOutSpeed = speed;
}
