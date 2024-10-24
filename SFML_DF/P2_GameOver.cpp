#include "pch.h"
#include "P2_GameOver.h"
#include "DText.h"
#include "DRectangle.h"
#include "DSprite.h"

P2_GameOver::P2_GameOver()
{
}

P2_GameOver::~P2_GameOver()
{
}

bool P2_GameOver::Initialize()
{
    m_GameOverBackground = new DSprite("background/003.png", DrawType::Background);
    m_GameOverText[0] = new DText("resource/CookieRun Black.ttf", "GameOver...", 80, DrawType::UI);
    m_GameOverText[1] = new DText("resource/CookieRun Black.ttf", "ReStart(R)", 50, DrawType::UI);
    m_GameOverText[2] = new DText("resource/CookieRun Black.ttf", "Go Main(M)", 50, DrawType::UI);
    m_GameOverRect = new DRectangle({ 0,0 }, { 300, 400 }, sf::Color::White, 1, sf::Color::White, DrawType::UI);

    Reset();

	return false;
}

void P2_GameOver::Reset()
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

void P2_GameOver::Update(float dt)
{
    if (IM->GetKeyDown(sf::Keyboard::R))
    {
        SM->ChangeScene("Play2");
    }

    if (IM->GetKeyDown(sf::Keyboard::M))
    {
        SM->ChangeScene("Lobby");
    }
}

