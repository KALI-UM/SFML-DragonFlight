#include "pch.h"
#include "Scene_GameOver.h"
#include "GameOver.h"

Scene_GameOver::Scene_GameOver()
    :SceneBase("GameOver")
{
}

Scene_GameOver::~Scene_GameOver()
{
}

bool Scene_GameOver::Initialize()
{
    m_GameOverUI = new GameOver();
    m_GameObjects.push_back(m_GameOverUI);
    return false;
}

void Scene_GameOver::Reset()
{
}

void Scene_GameOver::Update(float dt)
{
}

void Scene_GameOver::Release()
{
}
