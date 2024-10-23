#pragma once
#include "SceneBase.h"

class Character;
class Monster;
class Score;
class Scene_Test 
	:public SceneBase
{
public:
	Scene_Test();
	~Scene_Test();

	bool Initialize() override;
	void Update(float dt)override;

	Character* m_Player;
	std::vector<Monster*> m_Monsters;
	Score* m_Score;
};

