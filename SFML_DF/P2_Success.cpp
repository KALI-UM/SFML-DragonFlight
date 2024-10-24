#include "pch.h"
#include "P2_Success.h"
#include "DSprite.h"
#include "DText.h"
#include "DRectangle.h"

P2_Success::P2_Success()
{
}

P2_Success::~P2_Success()
{
}

bool P2_Success::Initialize()
{
    m_SuccessBackground = new DSprite("background/003.png", DrawType::Background);
    m_SuccessText[0] = new DText("resource/CookieRun Black.ttf", "Stage2 Success!!", 65, DrawType::UI);
    m_SuccessText[1] = new DText("resource/CookieRun Black.ttf", "Congraturation!!", 50, DrawType::UI);
    m_SuccessText[2] = new DText("resource/CookieRun Black.ttf", "Go Main(M)", 45, DrawType::UI);
    m_SuccessRect = new DRectangle({ 0,0 }, { 400, 400 }, sf::Color::White, 1, sf::Color::White, DrawType::UI);
    SetDrawable(m_SuccessBackground);
    SetDrawable(m_SuccessText[0]);
    SetDrawable(m_SuccessText[1]);
    SetDrawable(m_SuccessText[2]);
    SetDrawable(m_SuccessRect);
    m_SuccessBackground->SetPriority(0);
    m_SuccessRect->SetPriority(1);
    m_SuccessText[0]->SetPriority(2);
    m_SuccessText[1]->SetPriority(2);
    m_SuccessText[2]->SetPriority(2);

    Reset();
	
	return false;
}

void P2_Success::Reset()
{
    m_SuccessRect->SetOriginCenter();
    m_SuccessRect->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);

    m_SuccessText[0]->SetOriginCenter();
    m_SuccessText[0]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 270);
    m_SuccessText[1]->SetOriginCenter();
    m_SuccessText[1]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 80);
    m_SuccessText[2]->SetOriginCenter();
    m_SuccessText[2]->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 + 80);

    m_SuccessText[0]->SetFillColor(sf::Color::Red);
    m_SuccessText[1]->SetFillColor(sf::Color::Black);
    m_SuccessText[2]->SetFillColor(sf::Color::Black);
}

void P2_Success::Update(float dt)
{
    if (IM->GetKeyDown(sf::Keyboard::M))
    {
        SM->ChangeScene("Lobby");
    }
}

void P2_Success::FadeOutBackGround(float speed)
{
}
