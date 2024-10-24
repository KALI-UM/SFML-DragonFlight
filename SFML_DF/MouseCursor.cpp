#include "pch.h"
#include "MouseCursor.h"
#include "DSprite.h"

MouseCursor::MouseCursor()
{
}

MouseCursor::~MouseCursor()
{
}

bool MouseCursor::Initialize()
{
    m_Cursor = new DSprite("ui/push.png", DrawType::UI);
    SetDrawable(m_Cursor);
    m_Cursor->SetPriority(100);
    return true;
}

void MouseCursor::Reset()
{
}

void MouseCursor::Update(float dt)
{
    m_Cursor->Transform()->setPosition({ (float)MOUSEPOS.x,(float)MOUSEPOS.y });
}
