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
    m_score = new DText();
    m_score->SetString("Score : ");
    return false;
}

void Score::Reset()
{
    m_score->Transform()->setPosition(0.f, 0.f);
}

void Score::Update(float dt)
{
}
