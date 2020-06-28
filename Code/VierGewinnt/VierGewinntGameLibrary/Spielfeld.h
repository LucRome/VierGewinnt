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
	CoordAndSuccess placeStone(Team& team, int x); //noch sichergehen, dass ein Team nur 1x setzt
	setStoneMsg possiblePlacement(int spalte);
	std::shared_ptr<Spielsteine> getPosition(Coord coordinates) const; //Coord: {zeile, spalte}
	int getLowestLevel(int spalte);

	

protected:
	static const int m_sizeSpalten = 6;
	static const int m_sizeZeilen = 5;
	Coord m_size = {m_sizeZeilen, m_sizeSpalten};
	//static const int m_size = 4;
	std::array<std::array<std::shared_ptr<Spielsteine>, m_sizeSpalten>, m_sizeZeilen> m_spielfeld = { nullptr };
};



 