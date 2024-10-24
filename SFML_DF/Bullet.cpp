#include "pch.h"
#include "Bullet.h"
#include "DSprite.h"
#include "DRectangle.h"
#include "Monster.h"
#include "P2_Score.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

bool Bullet::Initialize()
{
	m_Bullet = new DSprite("character/bullet_01.png");
	SetDrawable(m_Bullet);
	m_HitBox = new DRectangle(sf::FloatRect(m_Bullet->GetFloatRect()), sf::Color::Green, 1, sf::Color::Transparent, DrawType::Debug);
	SetDrawable(m_HitBox);

	Reset();
	return false;
}

void Bullet::Reset()
{
	m_Speed = 200;
	m_Bullet->SetOriginCenter();
	m_HitBox->SetFloatRect(m_Bullet->GetFloatRect());

	SetIsValid(false);
}

void Bullet::Update(float dt)
{
	m_Bullet->Transform()->setPosition(m_Bullet->Transform()->getPosition().x, m_Bullet->Transform()->getPosition().y - m_Speed * dt);
	sf::Vector2f p(m_Bullet->Transform()->getPosition().x - 16, m_Bullet->Transform()->getPosition().y - 22);
	m_HitBox->SetFloatRect(sf::FloatRect(p.x, p.y, 32, 38));


	if (m_Bullet->Transform()->getPosition().y < -20)
	{
		Reset();
	}

	if (BulletRectCheck() == true)
	{
		SetIsValid(false);
	}
}

void Bullet::Shoot(const sf::Vector2f& shootPoint)
{
	SetIsValid(true);
	m_Bullet->Transform()->setPosition(shootPoint);
}

bool Bullet::BulletRectCheck()
{
	bool rectcheck = false;
	for (int i = 0; i < m_Enemy->size(); i++)
	{
		if ((*m_Enemy)[i]->GetIsValid())
		{
			if (m_Bullet->GetFloatRect().intersects((*m_Enemy)[i]->m_monster->GetFloatRect()))
			{
				rectcheck = true;
				m_HitBox->SetOutlineColor(sf::Color::Red);
				(*m_Enemy)[i]->SetIsValid(false);
				m_Score->m_IncreaseScore += 100;
				return rectcheck;
			}
		}
	}
	if (!rectcheck)
	{
		m_HitBox->SetOutlineColor(sf::Color::Green);
	}
	return false;
}

void Bullet::getMonster(std::vector<Monster*>* mons)
{
	m_Enemy = mons;
}

void Bullet::getScore(P2_Score* score)
{
	m_Score = score;
}

