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
class P1_Backgound;
class GameStart;
class DustEffect;

class Scene_Play1 : public SceneBase
{
public:
	Scene_Play1();
	~Scene_Play1();

	bool Initialize() override;
	void Update(float dt)override;
	void Reset() override;
	void MonsterReset();

	Character* m_Player;
	std::vector<Monster*> m_Monsters;
	Score* m_Score;
	P1_Backgound* m_Background;

	Position m_SpawnPos;
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
	
	bool m_Start = false;
	float m_StartTime;
	float m_StartPause;
	float m_EndTime;
	float m_EndPause;
	std::vector<DustEffect*> m_Effects;
};

