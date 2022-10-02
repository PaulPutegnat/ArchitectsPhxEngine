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
		pos_x = pos_x + vec.pos_x;
		pos_y = pos_y + vec.pos_y;
	}

	Vector2& operator-(const Vector2& vec)
	{
		pos_x = pos_x - vec.pos_x;
		pos_y = pos_y - vec.pos_y;
	}

	Vector2& operator+=(const Vector2& vec)
	{
		Vector2 result = *this;
		result.pos_x += vec.pos_x;
		result.pos_y += vec.pos_y;
		return *this;
	}

	Vector2& operator-=(const Vector2& vec)
	{
		pos_x -= vec.pos_x;
		pos_y -= vec.pos_y;
	}

	Vector2& operator*(int scal) 
	{
		pos_x = pos_x * scal;
		pos_y = pos_y * scal;
	}

	Vector2& operator/(int scal)
	{
		pos_x = pos_x / scal;
		pos_y = pos_y / scal;
	}

	Vector2& operator*=(int scal)
	{
		pos_x *= scal;
		pos_y *= scal;
	}

	Vector2& operator/=(int scal)
	{
		pos_x /= scal;
		pos_y /= scal;
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