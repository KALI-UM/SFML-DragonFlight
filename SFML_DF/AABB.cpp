#include "pch.h"
#include "AABB.h"


bool AABB::PointRectCheck(const sf::Vector2f& p, const sf::FloatRect& rect) const
{
    return ((p.x > rect.left && p.x < rect.left + rect.width) && (p.y > rect.top && p.y < rect.top + rect.height));
}

bool AABB::RectRectCheck(const sf::FloatRect& rect1, const sf::FloatRect& rect2) const
{
    bool xcheck;
    bool ycheck;

    if (rect1.left < rect2.left)
    {
        xcheck = rect2.left > rect1.left && rect2.left < rect1.left + rect1.width;
        ycheck = rect2.top > rect1.top && rect2.top < rect1.top + rect1.height;
    }

    return (xcheck&&ycheck);
}
