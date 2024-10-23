#pragma once
#include "SceneBase.h"

class GameOver;
class Scene_GameOver : public SceneBase
{
public:
	Scene_GameOver();
	~Scene_GameOver();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;

private:
	GameOver* m_GameOverUI;
	bool m_Start = false;
	float m_FadeSpeed;
};

