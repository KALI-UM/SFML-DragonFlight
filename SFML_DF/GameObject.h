#pragma once

class DrawableObject;
class GameObject
{
public:
	GameObject();
	GameObject(const GameObject& other);
	GameObject(GameObject&& other) noexcept;
	virtual ~GameObject();
	bool operator==(const GameObject& rhs);

	bool INITIALIZE();
	void RESET();
	void UPDATE(float dt);
	void RELEASE();

	void SetIsValid(bool value);
	bool GetIsValid()const;
	bool GetIsVisible(size_t index = 0)const;


	DrawableObject* GetDrawable(size_t index = 0) const;
	DrawableObject* GetDrawable(const std::string& name) const;
	void SetDrawable(DrawableObject* dobj);

	int GetDrawbleCount()const;

protected:
	virtual bool Initialize();
	virtual void Reset();
	virtual void Update(float dt);

private:
	const int	m_Id;
	bool		m_IsValid;

	std::vector<DrawableObject*> m_Drawable;

	static int m_GameObjectsCount;
	static int m_IdNumber;
};

