#include "pch.h"
#include "DrawableObject.h"
#include "SFML/Window.hpp"
#include "Scene_Test.h"
#include "Scene_Lobby.h"
#include "Scene_P1_GameOver.h"
#include "Scene_P2_GameOver.h"
#include "Scene_Play1.h"
#include "Scene_Play2.h"
#include "Scene_P1_Success.h"
#include "Scene_P2_Success.h"

GameManager::GameManager()
	:m_MainWindow(nullptr),
	//m_RTextureManager(ResourceManager<sf::Texture>::GetInstance()),
	//m_RFontManager(ResourceManager<sf::Font>::GetInstance()),
	m_InputManager(InputManager::GetInstance()),
	m_SceneManager(SceneManager::GetInstance())
{
}

//ResourceManager<sf::Texture>* GameManager::GetTextureManager() const
//{
//	return m_RTextureManager;
//}
//
//ResourceManager<sf::Font>* GameManager::GetFontManager() const
//{
//	return m_RFontManager;
//}

InputManager* GameManager::GetInputManager() const
{
	return m_InputManager;
}

SceneManager* GameManager::GetSceneManager() const
{
	return m_SceneManager;
}

bool GameManager::Initialize(sf::RenderWindow* window)
{
	m_MainWindow = window;
	bool success = true;
	m_MainWindow->setMouseCursorVisible(false);
	success &= GetInputManager()->Initialize();
	success &= GetSceneManager()->Initialize();

	m_Volume = 0.8f;

	Scene_Lobby* lobby = new Scene_Lobby();
	//Scene_Test* test = new Scene_Test();
	Scene_P1_GameOver* over1 = new Scene_P1_GameOver();
	Scene_P2_GameOver* over2 = new Scene_P2_GameOver();
	Scene_Play1* play1 = new Scene_Play1();
	Scene_Play2* play2 = new Scene_Play2();
	Scene_P1_Success* suc1 = new Scene_P1_Success();
	Scene_P2_Success* suc2 = new Scene_P2_Success();
	SM->PushScene(lobby);
	//SM->PushScene(test);
	SM->PushScene(over1);
	SM->PushScene(over2);
	SM->PushScene(play1);
	SM->PushScene(play2);
	SM->PushScene(suc1);
	SM->PushScene(suc2);
	SM->SetCurrentScene(play2->GetName());
	return success;
}

void GameManager::UpdateEvent(const sf::Event& ev)
{
	GetInputManager()->Update(ev);
}

void GameManager::Update(float dt)
{
	if (IM->GetKeyDown(sf::Keyboard::F1))
	{
		std::cout << "Play Mode - Debug\n";
		m_GameMode = GameMode::Debug;
	}
	if (IM->GetKeyDown(sf::Keyboard::F2))
	{
		std::cout << "Play Mode - Normal\n";
		m_GameMode = GameMode::Normal;
	}

	GetSceneManager()->Update(dt);
	GetSceneManager()->PushToDrawQue();
}

void GameManager::Render()
{
	while (!m_DrawQue.empty())
	{
		m_MainWindow->draw(*m_DrawQue.top()->GetDrawable());
		m_DrawQue.pop();
	}
}

void GameManager::LateUpdate()
{
	GetInputManager()->Clear();
}

sf::RenderWindow* GameManager::GetWindow()
{
	return m_MainWindow;
}

void GameManager::PushDrawableObject(DrawableObject* dobj)
{
	m_DrawQue.push(dobj);
}

const GameMode& GameManager::GetGameMode() const
{
	return m_GameMode;
}

float GameManager::GetGlobalVolume() const
{
	return m_Volume;
}

void GameManager::SetGlobalVolume(float volume)
{
	m_Volume = volume;
}

bool PriorityComp::operator()(DrawableObject*& lhs, DrawableObject*& rhs)
{
	return DrawableObject::YCompare(lhs, rhs);
}
