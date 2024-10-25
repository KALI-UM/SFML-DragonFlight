#pragma once
#include "SceneBase.h"

enum class Position2
{
	EmptyBox1,
	EmptyBox2,
	EmptyBox3,
	EmptyBox4,
};
class Character;
class Monster;
class P2_Background;
class GameStart;
class Bullet;
class P2_Score;
class DustEffect;

class Scene_Play2
	:public SceneBase
{
public:
	Scene_Play2();
	~Scene_Play2();

	bool Initialize() override;
	void Update(float dt)override;
	void Reset() override;
	void MonsterReset();

	Character* m_Player;
	std::vector<Monster*> m_Monsters;
	P2_Score* m_Score;
	P2_Background* m_P2_Background;
	std::vector<Bullet*> m_Bullet;

	Position2 m_SpawnPos;
	sf::Vector2f m_ResetPoint;

private:
	float m_MonsterSpeed = 200;
	float m_BackgoundSpeed = 200;
	float m_CharacterSpeed = 500;
	static float m_XPosSet[5];
	static float m_YPos;
	static float m_BG_XPos;
	static float m_BG_YPos;
	static float m_BG_YTopPos;
	static float m_SpeedVariable;
	std::vector<DustEffect*> m_Effects;
};

   

