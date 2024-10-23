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
#include "Background.h"
#include "GameOver.h"

float Scene_Test::m_XPosSet[5] = { 55, 163, 271, 379, 487 };
float Scene_Test::m_YPos;

float Scene_Test::m_BG_XPos;
float Scene_Test::m_BG_YPos = -720;
float Scene_Test::m_BG_YTopPos = 0;
float Scene_Test::m_SpeedVariable = 25;

Scene_Test::Scene_Test()
	:SceneBase("Test")
{
	m_YPos = GM->GetWindow()->getSize().y / 2 - 360;
	m_BG_XPos = GM->GetWindow()->getSize().x / 2;
}

Scene_Test::~Scene_Test()
{
}

bool Scene_Test::Initialize()
{
	m_Background = new Background();
	m_Player = new Character();
	m_Monsters.resize(5);
	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_Monsters[i] = new Monster();
	}
	m_Score = new Score();
	m_Player->getMonster(&m_Monsters);
	m_GameOver = new GameOver();


	m_GameObjects.push_back(m_Background);
	m_GameObjects.push_back(m_Player);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		m_GameObjects.push_back(m_Monsters[i]);
	}
	/*if (m_Player->rectcheck == true)
	{
		std::cout << "GameOver!!" << std::endl;
		m_GameObjects.push_back(m_GameOver);
	}*/
	m_GameObjects.push_back(m_Score);
	return true;
}

void Scene_Test::Update(float dt)
{
	if(m_ResetPoint.y > 1100)
	{
		Reset();
	}

	if (IM->GetKeyDown(sf::Keyboard::Num1))
	{
		Reset();
	}

	m_ResetPoint.y += m_MonsterSpeed * dt;
	if (m_Background->m_background1->Transform()->getPosition().y > GM->GetWindow()->getSize().y)
	{
		m_Background->Set1(m_BackgoundSpeed, { m_BG_XPos , m_BG_YTopPos }, {1 , 1});
		m_Background->Set2(m_BackgoundSpeed, { m_BG_XPos , m_BG_YPos }, { 1, 1});
	}

	/*if (m_Player->m_CharSprite->Transform()->getPosition().y > GM->GetWindow()->getSize().y - 150)
	{
		m_Player->m_CharSprite->Transform()->setPosition(GM->GetWindow()->getSize().x / 2, (GM->GetWindow()->getSize().y - 100) - m_CharacterSpeed * dt);
	}*/
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
			m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_YPos }, { 0.6f, 0.6f });
		}
	}
	m_ResetPoint.y = m_YPos;

	m_MonsterSpeed += m_SpeedVariable;
	m_BackgoundSpeed += m_SpeedVariable;

}
