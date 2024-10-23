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

Scene_Test::Scene_Test()
{
}

Scene_Test::~Scene_Test()
{
}

bool Scene_Test::Initialize()
{

	m_Player = new Character();
	m_Monsters.resize(5);
	int x = 108;
	for (int i = 0; i < m_Monsters.size(); ++i)
	{
		m_Monsters[i] = new Monster();
		/*m_Monsters[i]->m_monster->Transform()->setPosition(x, 800);
		x += 108;*/
	}
	m_Score = new Score();
	m_Player->getMonster(&m_Monsters);
	m_GameObjects.push_back(m_Player);
	for(int i = 0; i < m_Monsters.size(); i++)
	{
		m_GameObjects.push_back(m_Monsters[i]);
	}
	
	m_GameObjects.push_back(m_Score);
	
	SceneBase::Initialize();

	return true;
}

void Scene_Test::Update(float dt)
{
	SceneBase::Update(dt);
}
