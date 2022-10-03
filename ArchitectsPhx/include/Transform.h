#pragma once
#include "Vector2.h"

class Tranform
{
public:
	Vector2 pos;
	float rota;
	Vector2 scale;

	Tranform();

	void SetPosition(Vector2);
	void SetRotation(float);
	void SetScale(Vector2);
	Vector2 TransformPoint(const Vector2&);
};