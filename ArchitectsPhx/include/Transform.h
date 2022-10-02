#pragma once
#include <Vector2.h>

class Vector2;

class Tranform 
{
	public:
		Vector2 pos;
		float rota;
		Vector2 scale;

		void SetPosition(Vector2&);
};
