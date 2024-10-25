#include "pch.h"
#include "Scene_P1_GameOver.h"
#include "P1_GameOver.h"
#include "Button.h"
#include "MouseCursor.h"

Scene_P1_GameOver::Scene_P1_GameOver()
	:SceneBase("P1_GameOver")
{
}

Scene_P1_GameOver::~Scene_P1_GameOver()
{
}

bool Scene_P1_GameOver::Initialize()
{
	m_GameObjects.push_back(new MouseCursor());
	m_GameOverUI = new P1_GameOver();
	m_GameObjects.push_back(m_GameOverUI);
	m_Button[0] = new Button();
	m_Button[1] = new Button();
	m_GameObjects.push_back(m_Button[0]);
	m_GameObjects.push_back(m_Button[1]);
	return false;
}

void Scene_P1_GameOver::Reset()
{
	m_FadeSpeed = 30.f;
	m_Button[0]->SetButtonText("ReStart(R)");
	m_Button[0]->SetButtonColor(sf::Color(220, 180, 0), sf::Color(200, 150, 0));
	m_Button[1]->SetButtonText("Go Main(M)");
	m_Button[1]->SetButtonColor(sf::Color(220, 180, 0), sf::Color(200, 150, 0));
	m_Button[0]->SetButtonPosition(sf::Vector2f(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 80));
	m_Button[1]->SetButtonPosition(sf::Vector2f(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 + 80));
}

void Scene_P1_GameOver::Update(float dt)
{
	if (IM->GetKeyDown(sf::Keyboard::R)||m_Button[0]->GetIsClicked())
	{
		SM->ChangeScene("Play1");
	}

	if (IM->GetKeyDown(sf::Keyboard::M)||m_Button[1]->GetIsClicked())
	{
		SM->ChangeScene("Lobby");
	}
}

void Scene_P1_GameOver::Release()
{
}
