#pragma once

class Vector2 // Une portion d'une texture
{
public:
	float x;
	float y;

	inline Vector2(float x, float y);
	inline Vector2();

#pragma region operator

	Vector2& operator+(const Vector2& vec)
	{
		Vector2 result = *this;
		x = x + vec.x;
		y = y + vec.y;
		return result;
	}

	Vector2& operator-(const Vector2& vec)
	{
		Vector2 result = *this;
		x = x - vec.x;
		y = y - vec.y;
		return result;
	}

	Vector2& operator+=(const Vector2& vec)
	{
		Vector2 result = *this;
		result.x += vec.x;
		result.y += vec.y;
		return result;
	}

	Vector2& operator-=(const Vector2& vec)
	{
		Vector2 result = *this;
		x -= vec.x;
		y -= vec.y;
		return result;
	}

	Vector2& operator*(float scal)
	{
		Vector2 result = *this;
		x = x * scal;
		y = y * scal;
		return result;
	}

	Vector2& operator/(float scal)
	{
		Vector2 result = *this;
		x = x / scal;
		y = y / scal;
		return result;
	}

	Vector2& operator*=(float scal)
	{
		Vector2 result = *this;
		x *= scal;
		y *= scal;
		return result;
	}

	Vector2& operator/=(float scal)
	{
		Vector2 result = *this;
		x /= scal;
		y /= scal;
		return result;
	}

#pragma endregion
};

Vector2::Vector2(float x, float y) :x(x), y(y) {};
Vector2::Vector2() :x(0), y(0) {};