#include "pch.h"
#include "Scene_P2_Success.h"
#include "P2_Success.h"

Scene_P2_Success::Scene_P2_Success()
	:SceneBase("P2_Successe")
{
}

Scene_P2_Success::~Scene_P2_Success()
{
}

bool Scene_P2_Success::Initialize()
{
	m_SuccessUI = new P2_Success();
	m_GameObjects.push_back(m_SuccessUI);
	return false;
}

void Scene_P2_Success::Reset()
{
	m_FadeSpeed = 30.f;
}

void Scene_P2_Success::Update(float dt)
{
}

void Scene_P2_Success::Release()
{
}
