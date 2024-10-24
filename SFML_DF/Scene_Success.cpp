#include "pch.h"
#include "Scene_Success.h"
#include "Success.h"

Scene_Success::Scene_Success()
	:SceneBase("Success")
{
}

Scene_Success::~Scene_Success()
{
}

bool Scene_Success::Initialize()
{
	m_SuccessUI = new Success();
	m_GameObjects.push_back(m_SuccessUI);
	return false;
}

void Scene_Success::Reset()
{
	m_FadeSpeed = 30.f;
}

void Scene_Success::Update(float dt)
{
}

void Scene_Success::Release()
{
}
