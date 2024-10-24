#include "pch.h"
#include "Scene_Play1.h"
#include "GameObject.h"
#include "DSprite.h"
#include "DAnimation.h"
#include "DRectangle.h"
#include "DCircle.h"
#include "DText.h"
#include "DLine.h"
#include "Character.h"
#include "Monster.h"
#include "P1_Score.h"
#include "P1_Background.h"
#include "SoundPlayer.h"
#include "DustEffect.h"

float Scene_Play1::m_XPosSet[5] = { 55, 163, 271, 379, 487 };
float Scene_Play1::m_YPos;

float Scene_Play1::m_BG_XPos;
float Scene_Play1::m_BG_YPos = -720;
float Scene_Play1::m_BG_YTopPos = 0;
float Scene_Play1::m_SpeedVariable = 25;

Scene_Play1::Scene_Play1()
	:SceneBase("Play1")
{
	m_YPos = GM->GetWindow()->getSize().y / 2 - 360;
	m_BG_XPos = GM->GetWindow()->getSize().x / 2;
}

Scene_Play1::~Scene_Play1()
{
}

bool Scene_Play1::Initialize()
{
	m_Background = new P1_Backgound();
	m_Player = new Character();
	m_Monsters.resize(5);
	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_Monsters[i] = new Monster();
	}
	m_Score = new Score();
	m_Player->getMonster(&m_Monsters);

	m_GameObjects.push_back(m_Background);
	m_GameObjects.push_back(m_Player);
	for (int i = 0; i < m_Monsters.size(); i++)
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

	return true;
}

void Scene_Play1::Update(float dt)
{
	if (!m_Start)
	{
		if (m_StartTime < 0)
		{
			m_StartTime = FM->GetRealTime();
			m_SoundPlayer->PlayEffect("sound/NextScene.wav");
			return;
		}
		else if (m_StartTime + m_StartPause > FM->GetRealTime())
		{
			FM->SetTimeScale(0);
			return;
		}
		else
		{
			FM->SetTimeScale(1);
			m_SoundPlayer->PlayBGM("sound/dragon_flight.mp3");
			m_Start = true;
		}
	}


	if (m_ResetPoint.y > 1100)
	{
		MonsterReset();
	}

	m_ResetPoint.y += m_MonsterSpeed * dt;
	if (m_Background->m_P1_Background1->Transform()->getPosition().y > GM->GetWindow()->getSize().y)
	{
		m_Background->Set1(m_BackgoundSpeed, { m_BG_XPos , m_BG_YTopPos }, { 1 , 1 });
		m_Background->Set2(m_BackgoundSpeed, { m_BG_XPos , m_BG_YPos }, { 1, 1 });
	}

	int collidedWith = m_Player->RectCheck();
	if (m_EndTime < 0 && collidedWith != -1)
	{
		m_EndTime = FM->GetRealTime();
		m_SoundPlayer->PlayEffect("sound/mon_die.wav");
		m_SoundPlayer->FadeOutBGM("sound/dragon_flight.mp3", 2);

		m_Player->SetStopCharacter();
		m_Monsters[collidedWith]->SetStopMonster();
		FM->SetTimeScale(0.1f);
		m_Monsters[collidedWith]->GetDrawable()->Transform()->getPosition();
		for (auto& eff : m_Effects)
		{
			if (!eff->GetIsValid())
			{
				eff->Effect(1.f, m_Monsters[collidedWith]->GetDrawable()->Transform()->getPosition(), 10.f);
				break;
			}
		}
		m_Background->SetStopBackground();
	}
	else if (m_EndTime > 0 && m_EndTime + m_EndPause < FM->GetRealTime())
	{
		SM->ChangeScene("P1_GameOver");
	}
}

void Scene_Play1::Reset()
{
	m_StartTime = -1;
	m_StartPause = 2.5f;
	m_EndTime = -1;
	m_EndPause = 2.5f;
	m_Start = false;

	m_MonsterSpeed = 200;
	m_BackgoundSpeed = 200;
	m_ResetPoint.y = m_BG_YTopPos;

	m_SpawnPos = (Position)(rand() % 4);
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
	}
}

void Scene_Play1::MonsterReset()
{
	m_SpawnPos = (Position)(rand() % 4);
	for (int i = 0; i < m_Monsters.size(); i++)
	{
		if (i == (int)m_SpawnPos || i == (int)m_SpawnPos + 1)
		{
			std::cout << i << "��° ���� �Ƚ���\n";
			m_Monsters[i]->SetIsValid(false);
		}
		else
		{
			std::cout << i << "��° ���� ����\n";
			m_Monsters[i]->SetIsValid(true);
			m_Monsters[i]->Set(m_MonsterSpeed, { m_XPosSet[i], m_YPos - 20 }, { 0.6f, 0.6f });
		}
	}
	m_ResetPoint.y = m_YPos;

	m_MonsterSpeed += m_SpeedVariable;
	m_BackgoundSpeed += m_SpeedVariable;
}
