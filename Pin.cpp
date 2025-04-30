#include "game/Pin.h"
#include <random>
Pin::Pin()
	:
	 position{ 0.f }
{
	/*std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> distx(100.f, 500.f);
	std::uniform_real_distribution<float> disty(100.f, 700.f);
	position.x = distx(mt);
	position.y = disty(mt);*/
	//mTexture = LoadTexture("resources/pikachu.png");
}



void Pin::Draw() {
	DrawCircleV(Vector2{ position.x,position.y }, 2.f, BLACK);
	float txtw = mTexture.width;
	float txth = mTexture.height;
	//DrawTexturePro(mTexture, Rectangle{ 0,0,txtw,txth }, Rectangle{ position.x,position.y,txtw,txth }, Vector2{ txtw / 2.f,txth / 2.f }, 0.f, WHITE);
	
}
void Pin::Update(float elapsedTime) {

}