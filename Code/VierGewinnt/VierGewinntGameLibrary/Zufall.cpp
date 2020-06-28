#include "Zufall.h"
#include "ConsolePrinter.h"
#include "Enum.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
//#include "pch.h"



Zufall::Zufall(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	srand(time(NULL)); //eventuell muss der Seed wo anders gesetzt werden.. glaube aber hier ist gut

}

Zufall::~Zufall()
{
}

int Zufall::chooseRow(Spielfeld& spielfeld)
{
	int spalte=2;
	setStoneMsg msg;
	Coord size = spielfeld.getSize();
	do {
		int min = 0, max = (size.spalte - 1); //hier dann sp�ter �ndern auf getSpalte!!!
		spalte = min + rand() % (max - min + 1);
		msg = spielfeld.possiblePlacement(spalte); 
	} while (msg != setStoneMsg::success);

	return spalte;
}
