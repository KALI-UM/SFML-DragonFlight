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
	//m_monster->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 400);
	//m_monster->Transform()->setScale(0.5f, 0.5f);
	m_HitBox->SetFloatRect(m_monster->GetFloatRect());
	m_speed = 100;
}

void Monster::Update(float dt)
{
	m_monster->Transform()->setPosition(m_monster->Transform()->getPosition().x, m_monster->Transform()->getPosition().y + m_speed * dt);
	m_HitBox->SetFloatRect(m_monster->GetFloatRect());
}

void Monster::Set(float speed, const sf::Vector2f& pos, const sf::Vector2f& scale, bool origincenter)
{
	m_speed = speed;
	m_monster->Transform()->setPosition(pos);
	m_monster->Transform()->setScale(scale);
	if (origincenter)
		m_monster->SetOriginCenter();
}
