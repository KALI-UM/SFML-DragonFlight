#include "pch.h"
#include "SceneManager.h"
#include "SceneBase.h"

bool SceneManager::Initialize()
{
    return false;
}

void SceneManager::Update(float dt)
{
    m_Scenes[m_CurrSceneIndex]->UPDATE(dt);
}

void SceneManager::PushToDrawQue()
{
    m_Scenes[m_CurrSceneIndex]->PushToDrawQue();
}

void SceneManager::Release()
{
    for (auto& scene : m_Scenes)
    {
        scene->RELEASE();
    }
}

int SceneManager::GetCurrentSceneIndex() const
{
    return m_CurrSceneIndex;
}

void SceneManager::SetCurrentSceneIndex(int index)
{
    m_CurrSceneIndex = index;
}

void SceneManager::PushScene(SceneBase* scene)
{
    scene->INITIALIZE();
    m_Scenes.push_back(scene);
}
