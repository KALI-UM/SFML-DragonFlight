#pragma once
#include "SceneBase.h"

enum class Position
{
	EmptyBox1,
	EmptyBox2,
	EmptyBox3,
	EmptyBox4,
};

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
	void Reset() override;

	Character* m_Player;
	std::vector<Monster*> m_Monsters;
	Score* m_Score;

	Position m_SpawnPos;
	sf::Vector2f m_ResetPoint;

private:
	float m_MonsterSpeed = 200;
	static float m_XPosSet[5];
	static float m_YPos;
};

