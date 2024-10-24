#include "pch.h"
#include "Scene_P1_GameOver.h"
#include "P1_GameOver.h"



Scene_P1_GameOver::Scene_P1_GameOver()
    :SceneBase("P1_GameOver")
{
}

Scene_P1_GameOver::~Scene_P1_GameOver()
{
}

bool Scene_P1_GameOver::Initialize()
{
    m_GameOverUI = new P1_GameOver();
    m_GameObjects.push_back(m_GameOverUI);
    return false;
}

void Scene_P1_GameOver::Reset()
{
    m_FadeSpeed = 30.f;
}

void Scene_P1_GameOver::Update(float dt)
{
}

void Scene_P1_GameOver::Release()
{
}
