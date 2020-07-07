//#include "pch.h"
#include "Regelwerk.h"
#include "Spielfeld.h"
#include "Spielsteine.h"

#include <array>
//#include "pch.h"
const Coord Regelwerk::d_waagerecht = { 0, 1 }; 
const Coord Regelwerk::d_senkrecht = { 1, 0 };
const Coord Regelwerk::d_diagonal1 = { 1, 1 };
const Coord Regelwerk::d_diagonal2 = { -1, 1 };


Regelwerk::Regelwerk() {

}

Regelwerk::~Regelwerk()
{
}


bool Regelwerk::gewonnen(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (highestStreak(coordinates, m_spielfeld, team) == 3) {
		return true;
	}
	else {
		return false;
	}
}

int Regelwerk::highestStreak(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	int waagerecht, senkrecht, diagonal1, diagonal2;
	int max = 0;
	waagerecht = umgebungInt(coordinates, d_waagerecht, m_spielfeld, team);
	senkrecht = umgebungInt(coordinates, d_senkrecht, m_spielfeld, team);
	diagonal1 = umgebungInt(coordinates, d_diagonal1, m_spielfeld, team);
	diagonal2 = umgebungInt(coordinates, d_diagonal2, m_spielfeld, team);

	if (waagerecht > max) {
		max = waagerecht;
	}
	if (senkrecht > max) {
		max = senkrecht;
	}
	if (diagonal1 > max) {
		max = diagonal1;
	}
	if (diagonal2 > max) {
		max = diagonal2;
	}
	return max;
}


int Regelwerk::umgebungInt(const Coord coordinates, Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	int cnt1, cnt2;
	cnt1 = countNeighbours(coordinates, deltas, m_spielfeld, team);
	deltas.spalte = -deltas.spalte;
	deltas.zeile = -deltas.zeile;
	cnt2 = countNeighbours(coordinates, deltas, m_spielfeld, team);

	return cnt1 + cnt2;
}


bool Regelwerk::ImSpielfeld(const Coord coordinates, const Spielfeld& m_spielfeld)
{
	Coord size = m_spielfeld.getSize();
	if (coordinates.zeile < size.zeile && coordinates.zeile >= 0 && coordinates.spalte < size.spalte && coordinates.spalte >= 0){
		return true;
	}
	else
	{
		return false;
	}
}

int Regelwerk::countNeighbours(Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	int counter = 0;
	coordinates += deltas;
	if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
		//immer prüfen ob Zielfeld noch im Spielfeld und ob Ziehlfeld != nullptr
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates)->getSymbol()))
		{
			coordinates += deltas;
			counter++;
			if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
					coordinates += deltas;
					counter++;
					if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
							counter++;
						}
					}
				}
			}
		}
	}
	return counter;
}


