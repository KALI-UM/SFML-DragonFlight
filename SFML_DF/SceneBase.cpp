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

bool SceneBase::INITIALIZE()
{
	bool result = Initialize();
	for (auto& gobj : m_GameObjects)
	{
		result &= gobj->Initialize();
	}
	RESET();
	return result;
}

void SceneBase::RESET()
{
	Reset();
}

void SceneBase::UPDATE(float dt)
{
	Update(dt);
	for (auto& gobj : m_GameObjects)
	{
		gobj->Update(dt);
	}
}

bool SceneBase::Initialize()
{
	return true;
}

void SceneBase::Reset()
{
}

void SceneBase::Update(float dt)
{
}

void SceneBase::PushToDrawQue()
{
	for (GameObject*& gobj : m_GameObjects)
	{
		if (gobj->GetIsValid())
		{
			for (int i = 0; i < gobj->GetDrawbleCount(); i++)
			{
				if (gobj->GetIsVisible(i))
					GameManager::GetInstance()->PushDrawableObject(gobj->GetDrawable(i));
			}
		}
	}
}
