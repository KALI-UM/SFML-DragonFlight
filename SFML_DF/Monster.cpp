#include "pch.h"
#include "Monster.h"
#include "DSprite.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

bool Monster::Initialize()
{
	m_monster = new DSprite("resource/ex.png");
	SetDrawable(m_monster);
	Reset();
	return false;
}

void Monster::Reset()
{
	m_monster->SetOriginCenter();
	m_monster->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2);
	m_speed = 150;
}

void Monster::Update(float dt)
{
	GetDrawable()->Transform()->setPosition(GetDrawable()->Transform()->getPosition().x, GetDrawable()->Transform()->getPosition().y + m_speed * dt);
}
