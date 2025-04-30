#include "Ball.h"
//#include "Circulo.cpp"
#include <random>
#define PKGRAVITY 30.F
#define RADIOY 10.F

Ball::Ball() 
	:v0{ 100.f, -30.f }, p0{ 15.f,55.f }
	, velocity{ 0.f }, position{ 0.f }
{
	mTexture = LoadTexture("resources/mia.png");
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> distx(80.f,200.f );
	std::uniform_real_distribution<float> disty(-200.f, -60.f);
	v0.x = distx(mt);
	v0.y = distx(mt);
}

void Ball::Update(float elapsedTime) {
	accTime += elapsedTime;
	velocity.x = v0.x * accTime;
	velocity.y = (.2f * PKGRAVITY * (accTime * accTime)) + (v0.y * accTime);
	position.x = (v0.x * accTime) + p0.x;
	position.y = (1.f * PKGRAVITY * (accTime * accTime)) + (v0.y * accTime) + p0.y;

}

void Ball::Draw() {
//	DrawCircleV(Vector2{ position.x,position.y }, RADIOY, LIGHTGRAY);
	float txtw = mTexture.width;
	float txth = mTexture.height;
	DrawTexturePro(mTexture, Rectangle{ 0,0,txtw,txth }, Rectangle{ position.x,position.y,txtw,txth }, Vector2{ txtw / 2.f,txth / 2.f }, 0.f, WHITE);
	//DrawTexture(mTexture, position.x, position.y, WHITE);
}

bool Ball::HasCollision(std::vector<Pin>& pines)
{
	for (Pin& pinl:pines) 
	{
		Vector2 pinpos = pinl.GetPosition();
		float cmpX = pinpos.x - position.x;
		float cmpY = pinpos.y - position.y;
		float sqrX = cmpX * cmpX;
		float sqrY = cmpY * cmpY;
		if (sqrX+sqrY <= (RADIOY*RADIOY))
		{
			float modir = sqrt(sqrX + sqrY);
			float dirbX = -cmpX / modir; float dirbY = -cmpY / modir;
			float modvel = sqrtf((velocity.x * velocity.x) + (velocity.y * velocity.y));

			v0.x = modvel*dirbX/2;
			v0.y = modvel * dirbY/2;
			p0.x = position.x;
			p0.y = position.y;
			accTime = 0.f;

			return true;
		}
	} 
	return false;
	
}

bool Ball::HasCollision(std::vector<Paredes>& muros)
{
	for (Paredes& murol : muros) {
		Vector2 muroini = murol.GetInicio();
		Vector2 murofin = murol.GetFinal();

		if (CheckCollisionCircleLine(position, RADIOY, muroini, murofin)) {
			Vector2 dirpm{ muroini.y - murofin.y, murofin.x - muroini.x };
			float modir = sqrtf((dirpm.x * dirpm.x) + (dirpm.y * dirpm.y));
			float dirbX = dirpm.x / modir;  float dirbY = dirpm.y / modir;
			float modvel = sqrtf((velocity.x * velocity.x) + (velocity.y * velocity.y));

			v0.x = modvel * dirbX/2;
			v0.y = modvel * dirbY;
			p0.x = position.x;
			p0.y = position.y;
			accTime = 0.f;
		}

		return true;
	}
	return false;
}
bool Ball::HasCollision(std::vector<FinishLine>& points)
{
	for (FinishLine& scorol : points) {
		Vector2 scoreini = scorol.GetInicioLine();
		Vector2 scorefin = scorol.GetFinalLine();

		if (CheckCollisionCircleLine(position, RADIOY, scoreini, scorefin)) {
			
			return true;
		}

		//return true;
	}
	return false;
}

bool Ball::HasCollision(std::vector<Circulo>& circulos) {
	for (Circulo& circol : circulos) 
	{
		if (CheckCollisionCircles(position, RADIOY, circol.GetPosition(), circol.GetRadio()))
		{
			Vector2 cirPos = circol.GetPosition();

			float cmpX = cirPos.x - position.x;
			float cmpY = cirPos.y - position.y;
			float sqrX = cmpX * cmpX;
			float sqrY = cmpY * cmpY;

			float modir = sqrt(sqrX + sqrY);
			float dirbX = -cmpX / modir; float dirbY = -cmpY / modir;
			float modvel = sqrtf((velocity.x * velocity.x) + (velocity.y * velocity.y));

			v0.x = modvel * dirbX;
			v0.y = modvel * dirbY/2;
			p0.x = position.x;
			p0.y = position.y;
			accTime = 0.f;
			return true;
		}
	
		//if(CheckCollisionCircles(position,RADIOY,posi,RADIOCIRCLE))
	}
	return false;
	
}