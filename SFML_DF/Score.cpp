#include "pch.h"
#include "Score.h"
#include "DText.h"

Score::Score()
{
}

Score::~Score()
{
}

bool Score::Initialize()
{
    m_scoreText = new DText("resource/CookieRun Bold.ttf", "Score : ", 50, DrawType::UI);
    SetDrawable(m_scoreText);
    return false;
}

void Score::Reset()
{
    m_scoreText->SetFillColor(sf::Color::White);
    m_scoreText->Transform()->setPosition(0.f, 0.f);
}

void Score::Update(float dt)
{
    m_scoreText->SetString("Score : " + std::to_string((int)m_Score));
    m_Score += 1000 * dt;

    if (m_Score >= 40000)
    {
        SM->ChangeScene("Success");
    }
}
