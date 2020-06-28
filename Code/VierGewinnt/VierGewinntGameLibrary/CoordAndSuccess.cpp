#include "CoordAndSuccess.h"

//Coord& Coord::operator+(Coord& b)
//{
//	Coord c;
//	c.spalte = this->spalte + b.spalte;
//	c.zeile = this->zeile + b.zeile;
//	return c;
//}

Coord& Coord::operator+=(Coord& b)
{
	this->spalte += b.spalte;
	this->zeile += b.zeile;

	return *this;
}

Coord& Coord::operator-=(Coord& b)
{
	this->spalte -= b.spalte;
	this->zeile -= b.zeile;

	return *this;
}
