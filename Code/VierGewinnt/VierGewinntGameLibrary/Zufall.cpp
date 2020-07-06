#include "Zufall.h"
#include "ConsolePrinter.h"
#include "Enum.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
//#include "pch.h"



Zufall::Zufall(const std::shared_ptr<const Team> team, const std::string name)
	:Spieler(team, name)
{
	srand(time(NULL)); //eventuell muss der Seed wo anders gesetzt werden.. glaube aber hier ist gut

}

Zufall::~Zufall()
{
}

int Zufall::chooseRow(const Spielfeld& spielfeld)
{
	int spalte=2;
	setStoneMsg msg;
	Coord size = spielfeld.getSize();
	do {
		int min = 0, max = (size.spalte - 1); //hier dann später ändern auf getSpalte!!!
		spalte = min + rand() % (max - min + 1);
		msg = spielfeld.possiblePlacement(spalte); 
	} while (msg != setStoneMsg::success);

	return spalte;
}
