#include "pch.h"
#include "Scene_Loading.h"
#include "Character.h"

Scene_Loading::~Scene_Loading()
{
}

bool Scene_Loading::Initialize()
{
    m_Player = new Character();
    m_GameObjects.push_back(m_Player);
    return true;
}

void Scene_Loading::Reset()
{
    m_StartTime = -1;
    m_PauseTime = 5;
}

void Scene_Loading::Update(float dt)
{
    if (m_StartTime < 0)
    {
        m_StartTime = FM->GetRealTime();
    }
    else if (m_StartTime + m_PauseTime > FM->GetRealTime())
    {

    }
}

void Scene_Loading::Release()
{
}
