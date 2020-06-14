#pragma once
#include "Enum.h"
#include <memory>
#include "Team.h"
#include "Spielsteine.h"
#include "pch.h"

class Spielsteine;


class Spielfeld
{
public:
	Spielfeld();
	~Spielfeld();
	bool isVoll() const;
	int getSize() const;
	setStoneMsg placeStone(Team& team, int x); //noch sichergehen, dass ein Team nur 1x setzt
	setStoneMsg possiblePlacement(int spalte);
	std::shared_ptr<Spielsteine> getPosition(int x, int y) const;

	

protected:
	static const int m_size = 4;
	std::unique_ptr<Spielsteine> m_spielfeld[m_size][m_size] = { nullptr };
};



 