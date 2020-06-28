#pragma once
#include "Enum.h"

struct Coord //Coord: {zeile, spalte}
{
	int zeile;
	int spalte;

public:
	//Coord& operator+(Coord& b); //nicht verwendet
	Coord& operator+=(Coord& b);
	Coord& operator-=(Coord& b);
};

struct CoordAndSuccess {
	Coord coordinates;
	setStoneMsg success;
};