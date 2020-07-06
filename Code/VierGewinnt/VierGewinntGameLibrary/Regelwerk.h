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

	static int highestStreak(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
private:

	//Checks die true (gewonnen) oder false (nicht gewonnen) zur�ckgeben
	//evtl. �berfl�ssig
	//start �berfl�ssig
	static bool waagerechtCheck(const Spielfeld& m_spielfeld, const Team& team); //meinStein -> Beispielstein f�r den Verwendeten?
	static bool senkrechtCheck(const Spielfeld& m_spielfeld, const Team& team);  //Eher �ber �bergabe des Teams?
	static bool diagonalCheck(const Spielfeld& m_spielfeld, const Team& team);

	static bool waagerechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
	static bool senkrechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
	static bool diagonalCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team);
	//end �berfl�ssig
	//checks die dei h�chste Anzahl an Nachbarn in eine Richtung zur�ckgben
	static int umgebungInt(const Coord coordinates, Coord deltas, const Spielfeld& m_spielfeld, const Team& team);
	//auch �berfl�ssig
	static bool umgebungBool(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team);
	static bool ImSpielfeld(const Coord coordinates, const Spielfeld& m_spielfeld);

	static int countNeighbours(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team);

private:
	static const Coord d_waagerecht, d_senkrecht, d_diagonal1, d_diagonal2;
	static const int winNr = 4;
};