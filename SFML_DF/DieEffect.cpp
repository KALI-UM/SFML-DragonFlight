#include "pch.h"
#include "DieEffect.h"
#include "DSprite.h"

DieEffect::DieEffect()
{
}

DieEffect::~DieEffect()
{
}

bool DieEffect::Initialize()
{
	m_Dusts.resize(5);
	for (auto& sprite : m_Dusts)
	{
		sprite = new DSprite("monster/dust.png", DrawType::Effect);
		sprite->SetOriginCenter();
		SetDrawable(sprite);
	}
	m_Dusts[0]->Transform()->rotate(60);
	m_Dusts[1]->Transform()->rotate(120);
	m_Dusts[2]->Transform()->rotate(180);
	m_Dusts[3]->Transform()->rotate(210);
	return true;
}

void DieEffect::Reset()
{
	SetIsValid(false);
	m_Speed = 10.f;
	m_Offset = 15.f;
	m_Dusts[0]->Transform()->setScale(0.8, 0.8);
	m_Dusts[1]->Transform()->setScale(0.6, 0.6);
	m_Dusts[2]->Transform()->setScale(1, 1);
	m_Dusts[3]->Transform()->setScale(0.2, 0.2);
	m_Dusts[4]->Transform()->setScale(1, 1);

}

void DieEffect::Update(float dt)
{
	for (auto& sprite : m_Dusts)
	{
		//sprite->SetFillColor(255, 255, 255, sprite->GetFillColor().a - (dt * m_Speed));
		sf::Vector2f scale = sprite->Transform()->getScale();
		scale *= 1 - (dt * m_Speed);
		sprite->Transform()->setScale(scale);
	}

	if (m_Dusts[0]->Transform()->getScale().x < 0)
	{
		SetIsValid(false);
	}
}

void DieEffect::Effect(const sf::Vector2f& point)
{
	SetIsValid(true);
	m_Dusts[0]->Transform()->setPosition({ point.x - m_Offset * 0.2f, point.y - m_Offset * 0.7f });
	m_Dusts[1]->Transform()->setPosition({ point.x + m_Offset * 0.8f, point.y + m_Offset });
	m_Dusts[2]->Transform()->setPosition({ point.x + m_Offset * 1.2f, point.y - m_Offset });
	m_Dusts[3]->Transform()->setPosition({ point.x - m_Offset, point.y + m_Offset * 0.5f });
	m_Dusts[4]->Transform()->setPosition({ point.x, point.y });
}
