#include "pch.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"

int GameObject::m_GameObjectsCount = 1;
int GameObject::m_IdNumber = 0;

GameObject::GameObject()
	:m_Id(m_IdNumber++), m_IsValid(true)
{
	m_GameObjectsCount++;
}

GameObject::GameObject(const GameObject& other)
	:m_Id(m_IdNumber++), m_IsValid(other.m_IsValid)
{
	m_GameObjectsCount++;
}

GameObject::GameObject(GameObject&& other)noexcept
	:m_Id(other.m_Id), m_IsValid(other.m_IsValid), m_Drawable(other.m_Drawable)
{
	//미완
	other.m_Drawable.clear();
	other.SetIsValid(false);
}

GameObject::~GameObject()
{
	m_GameObjectsCount--;
	for (auto& drawable : m_Drawable)
		delete drawable;
}

bool GameObject::Initialize()
{
	return false;
}

void GameObject::Reset()
{
}

void GameObject::Update(float dt)
{

}

void GameObject::SetIsValid(bool value)
{
	m_IsValid = value;
}

bool GameObject::GetIsValid() const
{
	return m_IsValid;
}

bool GameObject::GetIsVisible() const
{
	//0번째가 보이면 보이는거다..? 좀 이상해짐..ㅠ
	return GetIsValid() && GetDrawable() && GetDrawable()->GetIsVisible();
}

DrawableObject* GameObject::GetDrawable(size_t index)const
{
	if (index >= m_Drawable.size())return nullptr;
	return m_Drawable[index];
}

DrawableObject* GameObject::GetDrawable(const std::string& name) const
{
	for (auto& drawable : m_Drawable)
	{
		if (drawable->GetName() == name)
			return drawable;
	}
	return nullptr;
}

void GameObject::SetDrawable(DrawableObject* dobj)
{
	m_Drawable.push_back(dobj);
}

int GameObject::GetDrawbleCount() const
{
	return m_Drawable.size();
}

