#include "pch.h"
#include "Scene_P1_Success.h"
#include "P1_Success.h"
#include "Button.h"
#include "MouseCursor.h"

Scene_P1_Success::Scene_P1_Success()
	:SceneBase("P1_Success")
{
}

Scene_P1_Success::~Scene_P1_Success()
{
}

bool Scene_P1_Success::Initialize()
{
	m_GameObjects.push_back(new MouseCursor());
	m_SuccessUI = new P1_Success();
	m_GameObjects.push_back(m_SuccessUI);
	m_Button[0] = new Button();
	m_Button[1] = new Button();
	m_GameObjects.push_back(m_Button[0]);
	m_GameObjects.push_back(m_Button[1]);
	return false;
}

void Scene_P1_Success::Reset()
{
	m_FadeSpeed = 30.f;
	m_Button[0]->SetButtonText("Go Stage2(G)");
	m_Button[0]->SetButtonColor(sf::Color(220, 180, 0), sf::Color(200, 150, 0));
	m_Button[1]->SetButtonText("Go Main(M)");
	m_Button[1]->SetButtonColor(sf::Color(220, 180, 0), sf::Color(200, 150, 0));
	m_Button[0]->SetButtonPosition(sf::Vector2f(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 - 80));
	m_Button[1]->SetButtonPosition(sf::Vector2f(GM->GetWindow()->getSize().x / 2, GM->GetWindow()->getSize().y / 2 + 80));
}

void Scene_P1_Success::Update(float dt)
{
	if (IM->GetKeyDown(sf::Keyboard::G) || m_Button[0]->GetIsClicked())
	{
		SM->ChangeScene("Play2");
	}

	if (IM->GetKeyDown(sf::Keyboard::M) || m_Button[1]->GetIsClicked())
	{
		SM->ChangeScene("Lobby");
	}
}

void Scene_P1_Success::Release()
{
}
