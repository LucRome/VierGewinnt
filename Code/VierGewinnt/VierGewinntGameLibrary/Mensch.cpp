#include "Mensch.h"
#include "ConsolePrinter.h"
#include "Enum.h"
//#include "pch.h"


Mensch::Mensch(const std::shared_ptr<const Team> team, const std::string name)
	:Spieler(team, name)
{
}

Mensch::~Mensch()
{
}

int Mensch::chooseRow(const Spielfeld& spielfeld) const
{
	int spalte = 0;
	setStoneMsg msg;
	do {
		spalte = ConsolePrinter::askValue<int>("Spalte");
		msg = spielfeld.possiblePlacement(spalte);
		if (msg == setStoneMsg::outOfBounds) {
			ConsolePrinter::printMessage("The value of the Row is to high!");
		}
		else if (msg == setStoneMsg::rowFull) {
			ConsolePrinter::printMessage("The row is already full!");
		}
	} while (msg != setStoneMsg::success);
	
	return spalte;
}
