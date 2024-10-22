#include "pch.h"
#include "Character.h"
#include "DSprite.h"

Character::Character()
{
}

Character::~Character()
{
}

bool Character::Initialize()
{
    m_CharSprite = new DSprite("resource/ex.png");
    SetDrawable(m_CharSprite);
    Reset();
    return false;
}

void Character::Reset()
{
    m_CharSprite->SetOriginCenter();
    m_CharSprite->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y-150);
    m_CharSprite->Transform()->setScale(0.5f, 0.5f);
    m_speed = 300;
}

void Character::Update(float dt)
{
    if (IM->GetKey(sf::Keyboard::Left))
    {
        GetDrawable()->Transform()->setPosition(GetDrawable()->Transform()->getPosition().x-m_speed*dt, GetDrawable()->Transform()->getPosition().y);
    }
    if (IM->GetKey(sf::Keyboard::Right))
    {
        GetDrawable()->Transform()->setPosition(GetDrawable()->Transform()->getPosition().x + m_speed * dt, GetDrawable()->Transform()->getPosition().y);
    }
}

void Character::getMonster(Monster* mons)
{
    
}
