#include "pch.h"
#include "Scene_Test.h"
#include "GameObject.h"
#include "DSprite.h"
#include "DAnimation.h"
#include "DRectangle.h"
#include "DCircle.h"
#include "DText.h"
#include "DLine.h"
#include "Character.h"
#include "Monster.h"
#include "Score.h"

float Scene_Test::m_XPosSet[5] = { 55, 163, 271, 379, 487 };
float Scene_Test::m_YPos;

Scene_Test::Scene_Test()
{
	m_YPos = GM->GetWindow()->getSize().y / 2 - 400;
}

Scene_Test::~Scene_Test()
{
}

bool Scene_Test::Initialize()
{
	m_Player = new Character();
	m_Monsters.resize(5);
	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_Monsters[i] = new Monster();
	}
	m_Score = new Score();
	m_Player->getMonster(&m_Monsters);


	m_GameObjects.push_back(m_Player);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		m_GameObjects.push_back(m_Monsters[i]);
	}
	m_GameObjects.push_back(m_Score);
	return true;
}

void Scene_Test::Update(float dt)
{
	if(m_Monsters[0]->m_monster->Transform()->getPosition().y > 1100)
	{
		Reset();
	}

	if (IM->GetKeyDown(sf::Keyboard::Num1))
	{
		Reset();
	}

	m_ResetPoint.y += m_MonsterSpeed * dt;

}

void Scene_Test::Reset()
{
	m_SpawnPos = (Position)(rand() % 4);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (i== (int)m_SpawnPos || i == (int)m_SpawnPos+1)
		{
			std::cout << i << "번째 몬스터 안스폰\n";
			m_Monsters[i]->SetIsValid(false);
		}
		else
		{
			std::cout << i << "번째 몬스터 스폰\n";
			m_Monsters[i]->SetIsValid(true);
			m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_YPos }, { 0.5f, 0.5f });
		}
	}
	m_ResetPoint.y = m_YPos;
}
