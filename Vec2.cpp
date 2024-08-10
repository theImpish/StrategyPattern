#include "Vec2.h"
#include <math.h>

Vec2::Vec2()
{
}

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin)
{
}

bool Vec2::operator == (const Vec2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

bool Vec2::operator != (const Vec2& rhs) const
{
	return (x != rhs.x || y != rhs.y);
}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator - (const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator / (const float val) const
{
	return Vec2(x / val, y / val);
}

Vec2 Vec2::operator * (const float val) const
{
	return Vec2(x * val, y * val);
}

void Vec2::operator += (const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vec2::operator -= (const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

void Vec2::operator /= (const float val)
{
	x /= val;
	y /= val;
}

void Vec2::operator *= (const float val)
{
	x *= val;
	y *= val;
}

float Vec2::dist(const Vec2& rhs) const
{
	return sqrt((rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y));
}

float Vec2::distSq(const Vec2& rhs) const
{
	return (rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y);
}

float Vec2::ang(const Vec2& rhs) const
{
	return 0.0f;
}

Vec2 Vec2::unitVec(const Vec2& rhs) const
{
	return Vec2(cosf(atan2f((rhs.y - y), (rhs.x - x))), sinf(atan2f((rhs.y - y), (rhs.x - x))));
}
