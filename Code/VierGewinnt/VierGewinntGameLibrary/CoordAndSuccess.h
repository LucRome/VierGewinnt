#pragma once
#include "Enum.h"

struct Coord //Coord: {zeile, spalte}
{
	int zeile;
	int spalte;

public:
	//Coord& operator+(Coord& b); //nicht verwendet
	Coord& operator+=(const Coord& b);
	Coord& operator-=(const Coord& b);
};

struct CoordAndSuccess {
	Coord coordinates;
	setStoneMsg success;
};