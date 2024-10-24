#include "pch.h"
#include "P2_Score.h"
#include "DText.h"
#include "Bullet.h"

P2_Score::P2_Score()
{
}

P2_Score::~P2_Score()
{
}

bool P2_Score::Initialize()
{
	m_scoreText = new DText("resource/CookieRun Bold.ttf", "Score : ", 50, DrawType::UI);
	SetDrawable(m_scoreText);
	return false;
}

void P2_Score::Reset()
{
	m_scoreText->SetFillColor(sf::Color::White);
	m_scoreText->Transform()->setPosition(0.f, 0.f);
}

void P2_Score::Update(float dt)
{
	/*if (m_Bullet->BulletRectCheck() == true)
	{
		m_scoreText->SetString("Score : " + std::to_string((int)m_IncreaseScore));
		m_IncreaseScore += 100;
	}

	if (m_IncreaseScore >= 10000)
	{
		SM->ChangeScene("P2_Success");
	}*/
}
