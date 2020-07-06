#pragma once
#include "CoordAndSuccess.h"
#include <memory>
#include <array>
#include "Team.h"
#include "Spielsteine.h"
//#include "pch.h"

class Spielsteine;


class Spielfeld
{
public:
	Spielfeld();
	~Spielfeld();
	bool isVoll() const;

	Coord getSize() const;
	static Coord getSizeStatic();

	CoordAndSuccess placeStone(const Team& team, const int x); //noch sichergehen, dass ein Team nur 1x setzt
	setStoneMsg possiblePlacement(const int spalte) const;
	std::shared_ptr<Spielsteine> getPosition(const Coord coordinates) const; //Coord: {zeile, spalte}
	int getLowestLevel(const int spalte) const;


protected:
	static const int m_sizeSpalten = 5;
	static const int m_sizeZeilen = 6;
	Coord m_size = {m_sizeZeilen, m_sizeSpalten};
	//static const int m_size = 4;
	std::array<std::array<std::shared_ptr<Spielsteine>, m_sizeSpalten>, m_sizeZeilen> m_spielfeld = { nullptr };
};



 