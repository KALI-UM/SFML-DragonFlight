#include "pch.h"
#include "Monster.h"
#include "DSprite.h"
#include "DRectangle.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

bool Monster::Initialize()
{
	m_monster = new DSprite("monster/dragon_001.png");
	m_HitBox = new DRectangle(sf::FloatRect(m_monster->GetFloatRect()), sf::Color::Blue, 1, sf::Color::Transparent, DrawType::Debug);
	SetDrawable(m_monster);
	SetDrawable(m_HitBox);
	Reset();
	return false;
}

void Monster::Reset()
{
	m_monster->SetOriginCenter();
	m_monster->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 400);
	m_monster->Transform()->setScale(0.5f, 0.5f);
	m_HitBox->SetFRect(m_monster->GetFloatRect());
	m_speed = 50;
}

void Monster::Update(float dt)
{
	m_monster->Transform()->setPosition(m_monster->Transform()->getPosition().x, m_monster->Transform()->getPosition().y + m_speed * dt);
	m_HitBox->SetFRect(m_monster->GetFloatRect());
}
