#pragma once
#include <memory>
#include "Team.h"
//#include "pch.h"
class Spielfeld;
class Spielsteine;

class Regelwerk
{
public:
	Regelwerk();
	~Regelwerk();
	/*vielleicht alle als static?*/
	static bool gewonnen(Spielfeld& m_spielfeld, Team& team);

private:
	static bool waagerechtCheck(Spielfeld& m_spielfeld, Team& team); //meinStein -> Beispielstein für den Verwendeten?
	static bool senkrechtCheck(Spielfeld& m_spielfeld, Team& team);  //Eher über Übergabe des Teams?
	static bool diagonalCheck(Spielfeld& m_spielfeld, Team& team);
	static bool Umgebung(int x, int y, int zähler1, int zähler2, Spielfeld& m_spielfeld, Team& team);
	static bool ImSpielfeld(int i, int j, int Umgebung1, int Umgebung2, Spielfeld& m_spielfeld);
};