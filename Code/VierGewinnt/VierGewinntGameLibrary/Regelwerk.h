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
	static bool gewonnen(const Spielfeld& m_spielfeld, const Team& team);
	static bool gewonnen(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);

private:
	static bool waagerechtCheck(const Spielfeld& m_spielfeld, const Team& team); //meinStein -> Beispielstein für den Verwendeten?
	static bool senkrechtCheck(const Spielfeld& m_spielfeld, const Team& team);  //Eher über Übergabe des Teams?
	static bool diagonalCheck(const Spielfeld& m_spielfeld, const Team& team);

	static bool waagerechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
	static bool senkrechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
	static bool diagonalCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);

	static bool Umgebung(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team);
	static bool ImSpielfeld(const Coord coordinates, const Spielfeld& m_spielfeld);

private:
	static const Coord d_waagerecht, d_senkrecht, d_diagonal1, d_diagonal2;
};