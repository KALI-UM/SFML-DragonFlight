#include "pch.h"
#include "GameStart.h"
#include "DText.h"

GameStart::GameStart()
{
}

GameStart::~GameStart()
{
}

bool GameStart::Initialize()
{
	m_GameStart = new DText("resource/CookieRun Bold.ttf", "GAME START!!", 50, DrawType::UI);
	SetDrawable(m_GameStart);
	return false;
}

void GameStart::Reset()
{
	m_GameStart->SetFillColor(sf::Color::Black);
	m_GameStart->SetOriginCenter();
	m_GameStart->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 150);
}

void GameStart::Update(float dt)
{
}
