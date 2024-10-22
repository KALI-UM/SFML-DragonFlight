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
<<<<<<< HEAD

=======
	m_Player = new Character();
	m_Monster = new Monster();
	m_Score = new Score();
	m_GameObjects.push_back(m_Player);
	m_GameObjects.push_back(m_Monster);
	m_GameObjects.push_back(m_Score);
	
	SceneBase::Initialize();
>>>>>>> origin/master
	return true;
}

void Scene_Test::Update(float dt)
{
<<<<<<< HEAD
	
=======
	SceneBase::Update(dt);
>>>>>>> origin/master
}
