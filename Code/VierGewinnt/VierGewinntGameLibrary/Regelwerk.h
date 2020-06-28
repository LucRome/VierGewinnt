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
	static bool gewonnen(Spielfeld& m_spielfeld, Team& team);
	static bool gewonnen(Coord coordinates, Spielfeld& m_spielfeld, Team& team);

private:
	static bool waagerechtCheck(Spielfeld& m_spielfeld, Team& team); //meinStein -> Beispielstein für den Verwendeten?
	static bool senkrechtCheck(Spielfeld& m_spielfeld, Team& team);  //Eher über Übergabe des Teams?
	static bool diagonalCheck(Spielfeld& m_spielfeld, Team& team);

	static bool waagerechtCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team);
	static bool senkrechtCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team);
	static bool diagonalCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team);

	static bool Umgebung(Coord coordinates, Coord deltas, Spielfeld& m_spielfeld, Team& team);
	static bool ImSpielfeld(Coord coordinates, Spielfeld& m_spielfeld);

private:
	static const Coord d_waagerecht, d_senkrecht, d_diagonal1, d_diagonal2;
};