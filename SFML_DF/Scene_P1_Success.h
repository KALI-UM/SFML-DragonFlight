#pragma once
#include "SceneBase.h"

class P1_Success;
class Button;
class Scene_P1_Success : public SceneBase
{
public:
	Scene_P1_Success();
	~Scene_P1_Success();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	P1_Success* m_SuccessUI;
	bool m_Start = false;
	float m_FadeSpeed;
	Button* m_Button[2];
};

