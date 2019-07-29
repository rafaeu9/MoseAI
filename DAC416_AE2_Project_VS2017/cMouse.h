#pragma once
#include "cMaze.h"
#include "cTimer.h"
#include "cVector2.h"
#include "cCostummaze.h"

class cMouse
{
public:	
	
	void			checkCheese(bool check) { hasFoundCheese = check; }
	bool			FoundCheese() { return hasFoundCheese; }

private:

	bool			hasFoundCheese{ false };
};

