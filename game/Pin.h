#pragma once
#include "raylib/raylib.h"

class Pin
{
public:
	Pin();
	void Update(float elapsedTime);
	void Draw();

	void SetPosition(Vector2 pos) { position = pos; }
	Vector2 GetPosition() { return position; }
private:
	//Vector2 v0, p0;
	//Vector2 velocity;
	Vector2 position;
	Texture2D mTexture;

	//float accTime = 0.f;
};
