#include <iostream>
#include "Transform.h"
#include "EngineMath.h"

Tranform::Tranform()
{
	pos = Vector2(0, 0);
	rota = 0;
	scale = Vector2(0, 0);
}

void Tranform::SetPosition(Vector2 nextPos)
{
	pos = nextPos;
}

void Tranform::SetRotation(float nextRota)
{
	rota = nextRota;
}

void Tranform::SetScale(Vector2 nextScale)
{
	scale = nextScale;
}

Vector2 Tranform::TransformPoint(const Vector2& localVec)
{
	Vector2 worldVec;
	worldVec.x = localVec.x * scale.x;
	worldVec.y = localVec.y * scale.y;
	worldVec.x = localVec.x * std::cos(rota * EngineMath::DEG2RAD) - localVec.y * std::sin(rota * EngineMath::DEG2RAD) + pos.x;
	worldVec.y = localVec.x * std::sin(rota * EngineMath::DEG2RAD) + localVec.y * std::cos(rota * EngineMath::DEG2RAD) + pos.y;
	return worldVec;
}
