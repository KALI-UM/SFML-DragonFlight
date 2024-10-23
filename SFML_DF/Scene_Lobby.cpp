#include "pch.h"
#include "Scene_Lobby.h"
#include "Background_Lobby.h"

Scene_Lobby::Scene_Lobby()
    :SceneBase("Lobby")
{
}

Scene_Lobby::~Scene_Lobby()
{
}

bool Scene_Lobby::Initialize()
{
    m_LobbyImage = new Background_Lobby();
    m_GameObjects.push_back(m_LobbyImage);
    return false;
}

void Scene_Lobby::Reset()
{
    m_Start = false;
    m_FadeSpeed = 30.0f;
}

void Scene_Lobby::Update(float dt)
{
    if (IM->GetMouseDown(sf::Mouse::Left)||IM->GetKeyDown(sf::Keyboard::Enter))
    {
        m_LobbyImage->FadeOutBackGround(m_FadeSpeed);
    }
    
}

void Scene_Lobby::Release()
{
}
