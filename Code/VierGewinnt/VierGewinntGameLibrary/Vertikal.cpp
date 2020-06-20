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
	for (int i = 0; i < spielfeld.getSize(); i++) { // getSize auf getSpalte() ändern
		spalte = i;
		msg = spielfeld.possiblePlacement(spalte);
		if (msg == setStoneMsg::success) {
			return spalte;
		}
	}
}
