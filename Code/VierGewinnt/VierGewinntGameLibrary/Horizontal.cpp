#include "Horizontal.h"
#include "Enum.h"
#include "Spielfeld.h"
//#include "pch.h"

Horizontal::Horizontal(const std::shared_ptr<const Team> team, const std::string name)
	:Spieler(team, name)
{
}

Horizontal::~Horizontal()
{
}

int Horizontal::chooseRow(const Spielfeld& spielfeld)
{ //immer in die niedrigst m�gliche Zeile
	Coord size = spielfeld.getSize();
	for (int zeile = size.zeile; zeile >= 0; zeile--) { //austauschen gegen Zeilenanzahl
		for (int spalte = 0; spalte < size.spalte; spalte++) { //austauschen gegen Spaltenanzahl
			if (spielfeld.getLowestLevel(spalte) == zeile) {
				return spalte;
			}
		}
	}
}
