#include "fondo.h"
fondo::fondo(std::string imgname) 
{
	mTexture = LoadTexture(imgname.c_str());
}

void fondo::Draw()
{
	float txtw = mTexture.width;
	float txth = mTexture.height;
	DrawTexture(mTexture,0.f,0.f,WHITE);
}
