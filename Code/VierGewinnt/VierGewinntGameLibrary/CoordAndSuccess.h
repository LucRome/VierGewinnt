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

struct SpalteAndStreak {
	int spalte;
	int streak;

public:
	//> & < operator für Priority Queue
	bool operator>(const SpalteAndStreak& b); //compares streaks
	bool operator<(const SpalteAndStreak& b) const; //compares streaks; const wichtig für std::priority queue

};