#include "FinishLine.h"

FinishLine::FinishLine(Vector2 ini, Vector2 fin)
	:sIni{ ini }, sFin{ fin }
{

}

void FinishLine::Draw() {
	DrawLineEx(sIni, sFin, 2.f, RED);
}
