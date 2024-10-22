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
    m_score = new DText("resource/KOMIKAP_.ttf", "Score : ", 30, DrawType::UI);
    SetDrawable(m_score);
    return false;
}

void Score::Reset()
{
    m_score->SetFillColor(sf::Color::White);
    m_score->Transform()->setPosition(0.f, 0.f);
}

void Score::Update(float dt)
{
}
