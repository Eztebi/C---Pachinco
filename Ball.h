#pragma once
#include "raylib/raylib.h"
#include "game/Pin.h"
#include "Paredes.h"
#include "Circulo.h"
#include "FinishLine.h"
#include <vector>
class Pin;
class Paredes;
class Ball
{
public:
	Ball();
	void Update(float elapsedTime);
	void Draw();
	
	bool HasCollision(std::vector<Pin>& pines);
	bool HasCollision(std::vector<Paredes>& paredes);
	bool HasCollision(std::vector<FinishLine>& points);
	bool HasCollision(std::vector<Circulo>& circulos);
protected:
	Vector2 v0, p0;
	Vector2 velocity;
	Vector2 position;
	Texture2D mTexture;


	float accTime = 0.f;
};

