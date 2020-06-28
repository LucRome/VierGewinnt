#include "Vertikal.h"
#include "Enum.h"
#include "Spielfeld.h"
//#include "pch.h"

Vertikal::Vertikal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Vertikal::~Vertikal()
{
}

int Vertikal::chooseRow(Spielfeld& spielfeld)
{
	int spalte = 0;
	setStoneMsg msg;
	Coord size = spielfeld.getSize();
	for (int zeile = 0; zeile < size.zeile; zeile++) { // getSize auf getSpalte() ändern
		spalte = zeile;
		msg = spielfeld.possiblePlacement(spalte);
		if (msg == setStoneMsg::success) {
			return spalte;
		}
	}
}
