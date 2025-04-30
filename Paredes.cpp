#include "Paredes.h"

Paredes::Paredes(Vector2 ini, Vector2 fin)
	:mIni{ ini }, mFin{ fin }
{

}

void Paredes::Draw(){
	DrawLineEx(mIni, mFin, 2.f, BLUE);
}
