#pragma once
#include "raylib/raylib.h"

class Paredes
{
public:
	Paredes(Vector2 ini, Vector2 fin);
	void Draw();

	Vector2 GetInicio() { return mIni; }
	Vector2 GetFinal() { return mFin; }

private:
	Vector2 mFin, mIni;
};

