#include "pch.h"
#include "Background.h"
#include "DSprite.h"

float Background::m_XPos = 540 / 2;
float Background::m_YTopPos = 0;

Background::Background()
{
}

Background::~Background()
{
}

bool Background::Initialize()
{
	m_background1 = new DSprite("background/001.png", DrawType::Background);
	m_background2 = new DSprite("background/001.png", DrawType::Background);
	SetDrawable(m_background1);
	SetDrawable(m_background2);
	Reset();
	return false;
}

void Background::Reset()
{
	m_background1->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_background1->Transform()->setPosition(m_XPos, m_YTopPos);
	m_background2->Transform()->setOrigin(m_XPos, m_YTopPos);
	m_background2->Transform()->setPosition(m_XPos, m_YTopPos - 720);
	m_speed = 200;
}

void Background::Update(float dt)
{
	m_background1->Transform()->setPosition(m_background1->Transform()->getPosition().x, m_background1->Transform()->getPosition().y + m_speed * dt);
	m_background2->Transform()->setPosition(m_background2->Transform()->getPosition().x, m_background2->Transform()->getPosition().y + m_speed * dt);
}

void Background::SetStopBackground()
{
	m_speed = 0;
}

void Background::Set1(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_speed = speed;
	m_background1->Transform()->setPosition(pos);
	m_background1->Transform()->setScale(scale);
}

void Background::Set2(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale)
{
	m_speed = speed;
	m_background2->Transform()->setPosition(pos);
	m_background2->Transform()->setScale(scale);
}