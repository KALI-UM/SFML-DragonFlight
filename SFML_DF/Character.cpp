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
	m_CharSprite = new DSprite("character/sunny.png");
	m_HitBox = new DRectangle(sf::FloatRect(m_CharSprite->GetFloatRect()), sf::Color::Green, 1, sf::Color::Transparent, DrawType::Debug);
	SetDrawable(m_CharSprite);
	SetDrawable(m_HitBox);
	Reset();
	return false;
}

void Character::Reset()
{
	m_CharSprite->SetOriginCenter();
	m_CharSprite->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 100);
	m_HitBox->SetFloatRect(m_CharSprite->GetFloatRect());
	m_CharSprite->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y - 150);
	m_HitBox->SetFloatRect(m_CharSprite->GetFloatRect());
	m_speed = 400;
}

void Character::Update(float dt)
{
	if (IM->GetKey(sf::Keyboard::Left))
	{
		if (m_CharSprite->Transform()->getPosition().x - 72.5 > 0)
		{
			m_CharSprite->Transform()->setPosition(m_CharSprite->Transform()->getPosition().x - m_speed * dt, m_CharSprite->Transform()->getPosition().y);
			m_HitBox->SetFloatRect(m_CharSprite->GetFloatRect());
		}

	}
	if (IM->GetKey(sf::Keyboard::Right))
	{
		if (m_CharSprite->Transform()->getPosition().x + 72.5 < 540)
		{
			m_CharSprite->Transform()->setPosition(m_CharSprite->Transform()->getPosition().x + m_speed * dt, m_CharSprite->Transform()->getPosition().y);
			m_HitBox->SetFloatRect(m_CharSprite->GetFloatRect());
		}
	}
}

bool Character::RectCheck()
{
	bool rectcheck = false;
	for (int i = 0; i < m_Enemy->size(); i++)
	{
		if (m_CharSprite->GetFloatRect().intersects((*m_Enemy)[i]->m_monster->GetFloatRect()))
		{
			if((*m_Enemy)[i]->m_monster->GetIsValid() == true)
			{
				m_HitBox->SetOutlineColor(sf::Color::Red);
				std::cout << i << "번째 몬스터랑 부딫침\n";
				rectcheck = true;
				return true;
			}
		}
	}

	if (!rectcheck)
	{
		m_HitBox->SetOutlineColor(sf::Color::Green);
	}
	return false;
}

void Character::SetStopCharacter()
{
	m_speed = 0;
}

void Character::getMonster(std::vector<Monster*>* mons)
{
	m_Enemy = mons;
}
