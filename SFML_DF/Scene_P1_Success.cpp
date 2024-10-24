#include "pch.h"
#include "Scene_P1_Success.h"
#include "P1_Success.h"

Scene_P1_Success::Scene_P1_Success()
	:SceneBase("P1_Success")
{
}

Scene_P1_Success::~Scene_P1_Success()
{
}

bool Scene_P1_Success::Initialize()
{
	m_SuccessUI = new P1_Success();
	m_GameObjects.push_back(m_SuccessUI);
	return false;
}

void Scene_P1_Success::Reset()
{
	m_FadeSpeed = 30.f;
}

void Scene_P1_Success::Update(float dt)
{
}

void Scene_P1_Success::Release()
{
}
