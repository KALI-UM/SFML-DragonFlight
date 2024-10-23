#pragma once

class DSprite;
class Background
{
public:
	Background();
	~Background();

	bool Initialize();
	void Reset();
	void Update(float dt);

	DSprite* m_Background;

protected:
	float m_speed;
};

