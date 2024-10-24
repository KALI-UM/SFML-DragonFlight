#include "pch.h"
#include "P1_GameOver.h"
#include "DSprite.h"
#include "DRectangle.h"
#include "DText.h"
#include "Character.h"



P1_GameOver::P1_GameOver()
{
}

P1_GameOver::~P1_GameOver()
{
}

bool P1_GameOver::Initialize()
{
    m_GameOverBackground = new DSprite("background/001.png", DrawType::Background);
    m_GameOverText[0] = new DText("resource/CookieRun Black.ttf", "Game Over...", 80, DrawType::UI);
    m_GameOverText[1] = new DText("resource/CookieRun Black.ttf", "ReStart(R)", 50, DrawType::UI);
    m_GameOverText[2] = new DText("resource/CookieRun Black.ttf", "Go Main(M)", 50, DrawType::UI);
    m_GameOverRect = new DRectangle({0,0}, {300, 400}, sf::Color::White, 1, sf::Color::White, DrawType::UI);
    SetDrawable(m_GameOverBackground);
    SetDrawable(m_GameOverText[0]);
    SetDrawable(m_GameOverText[1]);
    SetDrawable(m_GameOverText[2]);
    SetDrawable(m_GameOverRect);
    m_GameOverBackground->SetPriority(0);
    m_GameOverRect->SetPriority(1);
    m_GameOverText[0]->SetPriority(2);
    m_GameOverText[1]->SetPriority(2);
    m_GameOverText[2]->SetPriority(2);

    Reset();
    return false;
}

void P1_GameOver::Reset()
{
    m_GameOverRect->SetOriginCenter();
    m_GameOverRect->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
  
    m_GameOverText[0]->SetOriginCenter();
    m_GameOverText[0]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 270);
    m_GameOverText[1]->SetOriginCenter();
    m_GameOverText[1]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 80);
    m_GameOverText[2]->SetOriginCenter();
    m_GameOverText[2]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 + 80);
   
    m_GameOverText[0]->SetFillColor(sf::Color::Red);
    m_GameOverText[1]->SetFillColor(sf::Color::Black);
    m_GameOverText[2]->SetFillColor(sf::Color::Black);
}

void P1_GameOver::Update(float dt)
{
    if (IM->GetKeyDown(sf::Keyboard::R))
    {
        SM->ChangeScene("Play1");
    }

    if (IM->GetKeyDown(sf::Keyboard::M))
    {
        SM->ChangeScene("Lobby");
    }
}
