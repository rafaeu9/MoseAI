#pragma once
#include "cMaze.h"

class cCostummaze : public cMaze
{
public:

	char    checkPositionValue(int row, int col) { return m_strings[col][row]; }
	void    setPositionValue(cVector2 pos, char kpath) { m_strings[pos.y][pos.x] = kpath; }
	
};