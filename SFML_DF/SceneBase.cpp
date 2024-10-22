#include "pch.h"
#include "SceneBase.h"
#include "GameObject.h"

SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
	for (GameObject*& gobj : m_GameObjects)
	{
		delete gobj;
	}
}

bool SceneBase::Initialize()
{
	for (auto& gobj : m_GameObjects)
	{
		gobj->Initialize();
	}
	return true;
}

void SceneBase::Update(float dt)
{
	for (auto& gobj : m_GameObjects)
	{
		gobj->Update(dt);
	}
}

void SceneBase::SetInitialState()
{
}

void SceneBase::PushToDrawQue()
{
	for (GameObject*& gobj : m_GameObjects)
	{
		if (gobj->GetIsVisible())
		{
			GameManager::GetInstance()->PushDrawableObject(gobj->GetDrawable());
		}
	}
}
