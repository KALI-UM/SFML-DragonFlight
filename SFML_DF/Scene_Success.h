#pragma once
#include "SceneBase.h"

class Success;
class Scene_Success : public SceneBase
{
public:
	Scene_Success();
	~Scene_Success();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	Success* m_SuccessUI;
	bool m_Start = false;
	float m_FadeSpeed;
};

