#include "pch.h"
#include "P2_Background.h"
#include "DSprite.h"

float P2_Background::m_XPos = 540 / 2;
float P2_Background::m_YTopPos = 0;

P2_Background::P2_Background()
{
}

P2_Background::~P2_Background()
{
}

bool P2_Background::Initialize()
{
	m_P2_Background1 = new DSprite("background/003.png", DrawType::Background);
	m_P2_Background2 = new DSprite("background/003.png", DrawType::Background);
	SetDrawable(m_P2_Background1);
	SetDrawable(m_P2_Background2);
	Reset();
    return false;
}

void P2_Background::Reset()
{
	m_P2_Background1->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_P2_Background1->Transform()->setPosition(m_XPos, m_YTopPos);
	m_P2_Background2->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_P2_Background2->Transform()->setPosition(m_XPos, m_YTopPos - 720);
	m_Speed = 200;
}

void P2_Background::Update(float dt)
{
	m_P2_Background1->Transform()->setPosition(m_P2_Background1->Transform()->getPosition().x, m_P2_Background1->Transform()->getPosition().y + m_Speed * dt);
	m_P2_Background2->Transform()->setPosition(m_P2_Background2->Transform()->getPosition().x, m_P2_Background2->Transform()->getPosition().y + m_Speed * dt);
}

void P2_Background::SetStopBackground()
{
	m_Speed = 0;
}

void P2_Background::Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_Speed = speed;
	m_P2_Background1->Transform()->setPosition(pos);
	m_P2_Background1->Transform()->setScale(scale);
}

void P2_Background::Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_Speed = speed;
	m_P2_Background2->Transform()->setPosition(pos);
	m_P2_Background2->Transform()->setScale(scale);
}
