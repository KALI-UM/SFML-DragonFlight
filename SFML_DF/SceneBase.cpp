#include "pch.h"
#include "SceneBase.h"
#include "GameObject.h"

SceneBase::SceneBase(const std::string& name)
	:m_Name(name)
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
		result &= gobj->INITIALIZE();
	}
	RESET();
	return result;
}

void SceneBase::RESET()
{
	for (auto& gobj : m_GameObjects)
	{
		gobj->RESET();
	}
	Reset();
}

void SceneBase::UPDATE(float dt)
{
	Update(dt);
	for (auto& gobj : m_GameObjects)
	{
		if (gobj->GetIsValid())
			gobj->UPDATE(dt);
	}
}

void SceneBase::EXIT()
{
	Exit();
}

void SceneBase::RELEASE()
{
	Release();
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

void SceneBase::Exit()
{
}

void SceneBase::Release()
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

std::string SceneBase::GetName() const
{
	return m_Name;
}
