#pragma once

#pragma once

class Vector2 // Une portion d'une texture
{
public:
	float pos_x;
	float pos_y;

	Vector2(float x, float y);
	Vector2();

#pragma region operator

	Vector2& operator+(const Vector2& vec)
	{
		Vector2 result = *this;
		pos_x = pos_x + vec.pos_x;
		pos_y = pos_y + vec.pos_y;
		return result;
	}

	Vector2& operator-(const Vector2& vec)
	{
		Vector2 result = *this;
		pos_x = pos_x - vec.pos_x;
		pos_y = pos_y - vec.pos_y;
		return result;
	}

	Vector2& operator+=(const Vector2& vec)
	{
		Vector2 result = *this;
		result.pos_x += vec.pos_x;
		result.pos_y += vec.pos_y;
		return result;
	}

	Vector2& operator-=(const Vector2& vec)
	{
		Vector2 result = *this;
		pos_x -= vec.pos_x;
		pos_y -= vec.pos_y;
		return result;
	}

	Vector2& operator*(int scal)
	{
		Vector2 result = *this;
		pos_x = pos_x * scal;
		pos_y = pos_y * scal;
		return result;
	}

	Vector2& operator/(int scal)
	{
		Vector2 result = *this;
		pos_x = pos_x / scal;
		pos_y = pos_y / scal;
		return result;
	}

	Vector2& operator*=(int scal)
	{
		Vector2 result = *this;
		pos_x *= scal;
		pos_y *= scal;
		return result;
	}

	Vector2& operator/=(int scal)
	{
		Vector2 result = *this;
		pos_x /= scal;
		pos_y /= scal;
		return result;
	}

#pragma endregion
};

class Tranform
{
public:
	Vector2 pos;
	float rota;
	Vector2 scale;

	void SetPosition(Vector2&);
};