#pragma once
#include "raylib/raylib.h"
#include <string>
class fondo
{
public:
	fondo(std::string imgname);
	void Draw();
private:
	Vector2 position;
	Texture2D mTexture;

};

