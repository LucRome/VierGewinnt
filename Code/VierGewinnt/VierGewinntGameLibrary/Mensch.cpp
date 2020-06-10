#include "Mensch.h"
#include "ConsolePrinter.h"
#include "Enum.h"


Mensch::Mensch(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Mensch::~Mensch()
{
}

std::string Mensch::getName()
{
	return m_name;
}

int Mensch::chooseRow(Spielfeld& spielfeld)
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
}
