#pragma once

class GameObject;

class SceneBase
{
public:
	SceneBase(const std::string& name);
	//SceneBase(const SceneBase& other);
	//SceneBase(SceneBase&& other);
	virtual ~SceneBase();

	bool INITIALIZE();
	void RESET();
	void UPDATE(float dt);
	void EXIT();
	void RELEASE();

	void PushToDrawQue();
	std::string GetName()const;

protected:
	virtual bool Initialize();
	virtual void Reset();
	virtual void Update(float dt);
	virtual void Exit();
	virtual void Release();

	std::vector<GameObject*> m_GameObjects;
	const std::string m_Name;
};

