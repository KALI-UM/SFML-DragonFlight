#include "pch.h"
#include "Character.h"
#include "DSprite.h"
#include "DRectangle.h"
#include "Monster.h"

Character::Character()
{
}

Character::~Character()
{
}

bool Character::Initialize()
{
	m_CharSprite = new DSprite("resource/ex.png");
	m_HitBox = new DRectangle(sf::FloatRect(m_CharSprite->GetFloatRect()), sf::Color::Green, 1,sf::Color::Transparent, DrawType::Debug);
	SetDrawable(m_CharSprite);
	SetDrawable(m_HitBox);
	Reset();
	return false;
}

void Character::Reset()
{
	m_CharSprite->SetOriginCenter();
	m_CharSprite->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 150);
	m_CharSprite->Transform()->setScale(0.5f, 0.5f);
	m_HitBox->SetFRect(m_CharSprite->GetFloatRect());
	m_speed = 300;
}

void Character::Update(float dt)
{
	if (IM->GetKey(sf::Keyboard::Left))
	{
		m_CharSprite->Transform()->setPosition(m_CharSprite->Transform()->getPosition().x - m_speed * dt, m_CharSprite->Transform()->getPosition().y);
		m_HitBox->SetFRect(m_CharSprite->GetFloatRect());

	}
	if (IM->GetKey(sf::Keyboard::Right))
	{
		m_CharSprite->Transform()->setPosition(m_CharSprite->Transform()->getPosition().x + m_speed * dt, m_CharSprite->Transform()->getPosition().y);
		m_HitBox->SetFRect(m_CharSprite->GetFloatRect());
	}

	if (m_CharSprite->GetFloatRect().intersects(m_Enemy->m_monster->GetFloatRect()))
	{
		m_HitBox->SetOutlineColor(sf::Color::Red);
	}
}

void Character::getMonster(Monster* mons)
{
	m_Enemy = mons;
}
