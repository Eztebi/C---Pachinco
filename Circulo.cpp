#include "Circulo.h"
#define RADIOCIRCLE

Circulo::Circulo(Vector2 pos)
:positionCircle{pos},radioCircle{35.f}
{
	mtexture = LoadTexture("resources/pokebola.png");
	
}

void Circulo::Update(float elapsedTime)
{
}

void Circulo::Draw()
{

	float txtw = mtexture.width;
	float txth = mtexture.height;
	radioCircle= txtw / 2;
	DrawTexturePro(mtexture, Rectangle{ 0,0,txtw,txth }, Rectangle{ positionCircle.x,positionCircle.y,txtw,txth }, Vector2{ txtw / 2.f,txth / 2.f }, 0.f, WHITE);
}
