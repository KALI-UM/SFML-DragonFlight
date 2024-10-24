#include "pch.h"
#include "Bullet.h"
#include "DSprite.h"
#include "DRectangle.h"

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
	m_HitBox = new DRectangle(sf::FloatRect(m_Bullet->GetFloatRect()), sf::Color::Magenta, 1, sf::Color::Transparent, DrawType::Debug);
	SetDrawable(m_HitBox);

	Reset();
	return false;
}

void Bullet::Reset()
{
	m_Speed = 200;
	m_HitBox->SetOriginCenter();
	m_HitBox->SetFloatRect(m_Bullet->GetFloatRect());

	SetIsValid(false);
}

void Bullet::Update(float dt)
{
	m_Bullet->Transform()->setPosition(m_Bullet->Transform()->getPosition().x, m_Bullet->Transform()->getPosition().y - m_Speed * dt);
	m_HitBox->SetOriginCenter();
	m_HitBox->SetFloatRect(m_Bullet->GetFloatRect());
	//m_HitBox->SetFloatRect(sf::FloatRect(m_Bullet.);
	m_HitBox->Transform()->setScale(0.6f, 1.f);
	
	if (m_Bullet->Transform()->getPosition().y < -20)
	{
		Reset();
	}
}

void Bullet::Shoot(const sf::Vector2f& shootPoint)
{
	SetIsValid(true);
	m_Bullet->Transform()->setPosition(shootPoint);
}

bool Bullet::BulletRectCheck()
{
	return false;
}
