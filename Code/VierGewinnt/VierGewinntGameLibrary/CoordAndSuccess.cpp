#include "CoordAndSuccess.h"

//Coord& Coord::operator+(Coord& b)
//{
//	Coord c;
//	c.spalte = this->spalte + b.spalte;
//	c.zeile = this->zeile + b.zeile;
//	return c;
//}

Coord& Coord::operator+=(const Coord& b)
{
	this->spalte += b.spalte;
	this->zeile += b.zeile;

	return *this;
}

Coord& Coord::operator-=(const Coord& b)
{
	this->spalte -= b.spalte;
	this->zeile -= b.zeile;

	return *this;
}

bool SpalteAndStreak::operator>(const SpalteAndStreak& b)
{
	return this->streak > b.streak;
}

bool SpalteAndStreak::operator<(const SpalteAndStreak& b) const
{
	return this->streak < b.streak;
}
