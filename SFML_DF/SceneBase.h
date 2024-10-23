#pragma once

class GameObject;

class SceneBase
{
public:
	SceneBase();
	//SceneBase(const SceneBase& other);
	//SceneBase(SceneBase&& other);
	virtual ~SceneBase();

	bool INITIALIZE();
	void RESET();
	void UPDATE(float dt);
	void PushToDrawQue();

protected:
	virtual bool Initialize();
	virtual void Reset();
	virtual void Update(float dt);


	std::vector<GameObject*> m_GameObjects;
	std::string m_Name;
};

