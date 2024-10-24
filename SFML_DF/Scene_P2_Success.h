#pragma once
#include "SceneBase.h"

class P2_Success;
class Scene_P2_Success : public SceneBase
{
public:
	Scene_P2_Success();
	~Scene_P2_Success();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	P2_Success* m_SuccessUI;
	bool m_Start = false;
	float m_FadeSpeed;
};

