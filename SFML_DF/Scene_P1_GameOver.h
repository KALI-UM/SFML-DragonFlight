#pragma once
#include "SceneBase.h"

class P1_GameOver;
class Button;
class Scene_P1_GameOver : public SceneBase
{
public:
	Scene_P1_GameOver();
	~Scene_P1_GameOver();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	P1_GameOver* m_GameOverUI;
	bool m_Start = false;
	float m_FadeSpeed;
	Button* m_Button[2];
};

