#pragma once
#include "SceneBase.h"

class Character;
class Scene_Test 
	:public SceneBase
{
public:
	Scene_Test();
	~Scene_Test();

	bool Initialize() override;
	void Update(float dt)override;

	Character* m_Player;
};

