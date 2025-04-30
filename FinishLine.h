#pragma once
#include "raylib/raylib.h"

class FinishLine
{
public:
	FinishLine(Vector2 ini, Vector2 fin);
	void Draw();

	Vector2 GetInicioLine() { return sIni; }
	Vector2 GetFinalLine() { return sFin; }

private:
	Vector2 sFin, sIni;
};

