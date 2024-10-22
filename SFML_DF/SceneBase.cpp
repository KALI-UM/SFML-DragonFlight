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
		if (gobj->GetIsValid())//visible수정 나중에 다시
		{
			for(int i=0; i< gobj->GetDrawbleCount(); i++)
			GameManager::GetInstance()->PushDrawableObject(gobj->GetDrawable(i));
		}
	}
}
