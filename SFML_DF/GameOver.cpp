#include "pch.h"
#include "GameOver.h"
#include "DSprite.h"
#include "DRectangle.h"
#include "DText.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

bool GameOver::Initialize()
{
    m_GameOverBackground = new DSprite("background/02.png", DrawType::Background);
    m_GameOverText[0] = new DText("resource/CookieRun Black.ttf", "Game Over...", 150, DrawType::UI);
    m_GameOverText[1] = new DText("resource/CookieRun Black.ttf", "다시하기", 100, DrawType::UI);
    m_GameOverText[2] = new DText("resource/CookieRun Black.ttf", "메인화면으로 나가기", 100, DrawType::UI);
    m_GameOverRect = new DRectangle({0,0}, {450, 500}, sf::Color::White, 1, sf::Color::White, DrawType::UI);
    SetDrawable(m_GameOverBackground);
    SetDrawable(m_GameOverText[0]);
    SetDrawable(m_GameOverRect);
    return false;
}

void GameOver::Reset()
{
    m_GameOverRect->SetOriginCenter();
    m_GameOverRect->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
  
    m_GameOverText[0]->SetOriginCenter();
    m_GameOverText[0]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 250);
    m_GameOverText[1]->SetOriginCenter();
    m_GameOverText[1]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 112);
    m_GameOverText[2]->SetOriginCenter();
    m_GameOverText[2]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y + 112);
   
    m_GameOverText[0]->SetFillColor(sf::Color::Red);
    m_GameOverText[1]->SetFillColor(sf::Color::Black);
    m_GameOverText[2]->SetFillColor(sf::Color::Black);

}

void GameOver::Update(float dt)
{
}
