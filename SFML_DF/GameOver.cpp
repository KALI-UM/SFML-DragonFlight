#include "pch.h"
#include "GameOver.h"
#include "DText.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

bool GameOver::Initialize()
{
	m_GameOver = new DText("resource/KOMIKAP_.ttf", "Game Over!!", 50, DrawType::UI);
	SetDrawable(m_GameOver);
	return false;
}

void GameOver::Reset()
{
	m_GameOver->SetFillColor(sf::Color::Red);
	m_GameOver->SetOriginCenter();
	m_GameOver->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
}

void GameOver::Update(float dt)
{
}
