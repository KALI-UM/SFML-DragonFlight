#include "pch.h"
#include "P1_Background.h"
#include "DSprite.h"

float P1_Backgound::m_XPos = 540 / 2;
float P1_Backgound::m_YTopPos = 0;

P1_Backgound::P1_Backgound()
{
}

P1_Backgound::~P1_Backgound()
{
}

bool P1_Backgound::Initialize()
{
	m_P1_Background1 = new DSprite("background/001.png", DrawType::Background);
	m_P1_Background2 = new DSprite("background/001.png", DrawType::Background);
	SetDrawable(m_P1_Background1);
	SetDrawable(m_P1_Background2);
	Reset();
	return false;
}

void P1_Backgound::Reset()
{
	m_P1_Background1->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_P1_Background1->Transform()->setPosition(m_XPos, m_YTopPos);
	m_P1_Background2->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_P1_Background2->Transform()->setPosition(m_XPos, m_YTopPos - 720);
	m_Speed = 200;
}

void P1_Backgound::Update(float dt)
{
	m_P1_Background1->Transform()->setPosition(m_P1_Background1->Transform()->getPosition().x, m_P1_Background1->Transform()->getPosition().y + m_Speed * dt);
	m_P1_Background2->Transform()->setPosition(m_P1_Background2->Transform()->getPosition().x, m_P1_Background2->Transform()->getPosition().y + m_Speed * dt);
}

void P1_Backgound::SetStopBackground()
{
	m_Speed = 0;
}

void P1_Backgound::Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_Speed = speed;
	m_P1_Background1->Transform()->setPosition(pos);
	m_P1_Background1->Transform()->setScale(scale);
}

void P1_Backgound::Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_Speed = speed;
	m_P1_Background2->Transform()->setPosition(pos);
	m_P1_Background2->Transform()->setScale(scale);
}