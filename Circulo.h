#pragma once
#include "raylib/raylib.h"
#include <vector>
#define RADIOY
class Circulo
{
public:
	Circulo(Vector2 pos);
	void Update(float elapsedTime);
	void Draw();
	//Vector2 positionCirculo;
	Vector2 GetPosition() { return positionCircle; };
	float GetRadio() { return radioCircle; };
	//float getRadio() { return RADIOCIRCLE; }
private:
	Vector2 positionCircle;
	Texture2D mtexture;
	float radioCircle;
};

