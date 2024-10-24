#include "pch.h"
#include "Scene_P2_GameOver.h"
#include "P2_GameOver.h"

Scene_P2_GameOver::Scene_P2_GameOver()
	:SceneBase("P2_GameOver")
{
}

Scene_P2_GameOver::~Scene_P2_GameOver()
{
}

bool Scene_P2_GameOver::Initialize()
{
	m_GameOverUI = new P2_GameOver();
	m_GameObjects.push_back(m_GameOverUI);
	return false;
}

void Scene_P2_GameOver::Reset()
{
	m_FadeSpeed = 30.f;
}

void Scene_P2_GameOver::Update(float dt)
{
}

void Scene_P2_GameOver::Release()
{
}
