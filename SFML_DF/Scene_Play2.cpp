#include "pch.h"
#include "Scene_Play2.h"
#include "GameObject.h"
#include "DSprite.h"
#include "DAnimation.h"
#include "DRectangle.h"
#include "DCircle.h"
#include "DText.h"
#include "DLine.h"
#include "Character.h"
#include "Monster.h"
#include "P2_Score.h"
#include "P2_Background.h"
#include "Bullet.h"
#include "SoundPlayer.h"
#include "DustEffect.h"

float Scene_Play2::m_XPosSet[5] = { 55, 163, 271, 379, 487 };
float Scene_Play2::m_YPos;

float Scene_Play2::m_BG_XPos;
float Scene_Play2::m_BG_YPos = -720;
float Scene_Play2::m_BG_YTopPos = 0;
float Scene_Play2::m_SpeedVariable = 25;

Scene_Play2::Scene_Play2()
	:SceneBase("Play2")
{
	m_YPos = GM->GetWindow()->getSize().y / 2 - 360;
	m_BG_XPos = GM->GetWindow()->getSize().x / 2;
}

Scene_Play2::~Scene_Play2()
{
}

bool Scene_Play2::Initialize()
{
	m_P2_Background = new P2_Background();
	m_Player = new Character();

	m_Bullet.resize(100);
	m_Score = new P2_Score();
	for (int i = 0; i < m_Bullet.size(); ++i)
	{
		m_Bullet[i] = new Bullet();
		m_Bullet[i]->getScore(m_Score);
	}

	m_Monsters.resize(5);
	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_Monsters[i] = new Monster();
	}

	m_Player->getMonster(&m_Monsters);


	m_GameObjects.push_back(m_P2_Background);
	m_GameObjects.push_back(m_Player);
	for (int i = 0; i < m_Bullet.size(); ++i)
	{
		m_GameObjects.push_back(m_Bullet[i]);
	}

	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_GameObjects.push_back(m_Monsters[i]);
	}
	m_GameObjects.push_back(m_Score);

	m_Effects.resize(5);
	for (auto& eff : m_Effects)
	{
		eff = new DustEffect();
		eff->SetUsingDeltaTime(true);
		m_GameObjects.push_back(eff);
	}

	for (int i = 0; i < m_Bullet.size(); i++)
	{
		m_Bullet[i]->getMonster(&m_Monsters);
		m_Bullet[i]->GetEffect(&m_Effects);
	}

	return true;
}

void Scene_Play2::Update(float dt)
{
	if (m_ResetPoint.y > 1100)
	{
		MonsterReset();
	}

	m_ResetPoint.y += m_MonsterSpeed * dt;
	if (m_P2_Background->m_P2_Background1->Transform()->getPosition().y > GM->GetWindow()->getSize().y)
	{
		m_P2_Background->Set1(m_BackgoundSpeed, { m_BG_XPos , m_BG_YTopPos }, { 1 , 1 });
		m_P2_Background->Set2(m_BackgoundSpeed, { m_BG_XPos , m_BG_YPos }, { 1, 1 });
	}

	if (m_Player->RectCheck() != -1)
	{
		m_Player->SetStopCharacter();
		for (int i = 0; i < m_Monsters.size(); i++)
		{
			m_Monsters[i]->SetStopMonster();
		}
		m_P2_Background->SetStopBackground();

		SM->ChangeScene("P2_GameOver");
	}

	if (IM->GetKeyDown(sf::Keyboard::Up))
	{
		for (int i = 0; i < m_Bullet.size(); i++)
		{
			if (m_Bullet[i]->GetIsValid() == false)
			{
				m_SoundPlayer->PlayEffect("sound/baby_dragon_die.wav");
				m_Bullet[i]->Shoot(m_Player->GetDrawable()->Transform()->getPosition());
				break;
			}
		}
	}

	m_Score->m_scoreText->SetString("Score : " + std::to_string((int)(m_Score->m_IncreaseScore)));

	if (m_Score->m_IncreaseScore >= 3000)
	{
		SM->ChangeScene("P2_Success");
	}
}

void Scene_Play2::Reset()
{
	m_Score->m_IncreaseScore = 0;
	m_MonsterSpeed = 200;
	m_BackgoundSpeed = 200;
	m_ResetPoint.y = m_BG_YTopPos;

	for (int i = 0; i < m_Monsters.size(); i++)
	{
		m_Monsters[i]->SetIsValid(true);
		m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_BG_YTopPos }, { 0.6f, 0.6f });
	}

	/*m_SpawnPos = (Position2)(rand() % 4);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (i == (int)m_SpawnPos || i == (int)m_SpawnPos + 1)
		{
			m_Monsters[i]->SetIsValid(false);
			m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_BG_YTopPos }, { 0.6f, 0.6f });
		}
		else
		{
			m_Monsters[i]->SetIsValid(true);
			m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_BG_YTopPos }, { 0.6f, 0.6f });
		}
	}*/
}

void Scene_Play2::MonsterReset()
{
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		m_Monsters[i]->SetIsValid(true);
		m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_BG_YTopPos - 20 }, { 0.6f, 0.6f });
	}
	m_ResetPoint.y = m_YPos;

	m_MonsterSpeed += m_SpeedVariable;
	m_BackgoundSpeed += m_SpeedVariable;
}
