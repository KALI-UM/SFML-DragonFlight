#pragma once

class AABB
{
public:
	AABB();
	~AABB();



	bool AABBCheck();

protected:
	sf::Vector2f minPos;
	sf::Vector2f maxPos;

};

