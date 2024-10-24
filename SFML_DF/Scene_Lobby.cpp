#include "pch.h"
#include "Scene_Lobby.h"
#include "Background_Lobby.h"
#include "MouseCursor.h"
#include "DustEffect.h"
#include "SoundObject.h"
#include "GameStart.h"

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
	m_SoundObject = new SoundObject();
	m_GameObjects.push_back(m_LobbyImage);
	m_GameObjects.push_back(m_SoundObject);
	m_GameObjects.push_back(new MouseCursor());
	m_Effects.resize(5);
	for (auto& eff : m_Effects)
	{
		eff = new DustEffect();
		m_GameObjects.push_back(eff);
	}
	return true;
	m_LobbyImage = new Background_Lobby();
	m_GameStart = new GameStart();
	m_GameObjects.push_back(m_LobbyImage);
	m_GameObjects.push_back(m_GameStart);
	return false;
}

void Scene_Lobby::Reset()
{
	m_FadeSpeed = 30.0f;
}

void Scene_Lobby::Update(float dt)
{
	if (IM->GetMouseDown(sf::Mouse::Left) || IM->GetKeyDown(sf::Keyboard::Enter))
	{
		m_LobbyImage->FadeOutBackGround(m_FadeSpeed);
		m_SoundObject->PlayEffect(SoundEffect::Click);

		for (auto& eff : m_Effects)
		{
			if (!eff->GetIsValid())
			{
				eff->Effect(1.f, { (float)MOUSEPOS.x,(float)MOUSEPOS.y }, 10.f);
				break;
			}
		}
	}
}

void Scene_Lobby::Release()
{
}
