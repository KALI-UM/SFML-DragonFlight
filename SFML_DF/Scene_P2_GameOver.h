#pragma once
#include "SceneBase.h"

class P2_GameOver;
class Scene_P2_GameOver : public SceneBase
{
public:
	Scene_P2_GameOver();
	~Scene_P2_GameOver();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	P2_GameOver* m_GameOverUI;
	bool m_Start = false;
	float m_FadeSpeed;

};

