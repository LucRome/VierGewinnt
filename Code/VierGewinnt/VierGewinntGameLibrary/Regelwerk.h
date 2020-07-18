#pragma once
#include <memory>
#include "Team.h"
#include "CoordAndSuccess.h"

class Spielfeld;
class Spielsteine;

class Regelwerk
{
public:
	Regelwerk();
	~Regelwerk();
	/*vielleicht alle als static?*/
	static bool gewonnen(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);

	static int highestStreak(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
private:
	//checks die dei höchste Anzahl an Nachbarn in eine Richtung zurückgben
	static int umgebungInt(const Coord coordinates, Coord deltas, const Spielfeld& m_spielfeld, const Team& team);
	//auch Überflüssig
	//static bool umgebungBool(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team);
	static bool ImSpielfeld(const Coord coordinates, const Spielfeld& m_spielfeld);

	static int countNeighbours(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team);

private:
	static const Coord d_waagerecht, d_senkrecht, d_diagonal1, d_diagonal2;
	static const int winNr = 4;
};