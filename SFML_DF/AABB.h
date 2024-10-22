#pragma once

class AABB
{
public:

	bool PointRectCheck(const sf::Vector2f& p, const sf::FloatRect& rect) const;
	bool RectRectCheck(const sf::FloatRect& rect1, const sf::FloatRect& rect2) const;

protected:
	sf::Vector2f minPos;
	sf::Vector2f maxPos;

};

