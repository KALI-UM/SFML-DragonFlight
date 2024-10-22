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
	return false;
}

void SceneBase::Update(float dt)
{
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
