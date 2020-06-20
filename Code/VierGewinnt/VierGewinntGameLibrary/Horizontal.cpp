#include "Horizontal.h"
#include "Enum.h"
#include "Spielfeld.h"
//#include "pch.h"

Horizontal::Horizontal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Horizontal::~Horizontal()
{
}

int Horizontal::chooseRow(Spielfeld& spielfeld)
{ //immer in die niedrigst mögliche Zeile
	for (int h = (spielfeld.getSize()); h >= 0; h--) { //austauschen gegen Zeilenanzahl
		for (int i = 0; i < spielfeld.getSize(); i++) { //austauschen gegen Spaltenanzahl
			if (spielfeld.getLowestLevel(i) == h) {
				return i;
			}
		}
	}
}
