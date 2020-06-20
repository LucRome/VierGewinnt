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
	do {
		int a=0, b= (spielfeld.getSize() - 1); //hier dann später ändern auf getSpalte!!!
		spalte = a + rand() % (b - a + 1);
		msg = spielfeld.possiblePlacement(spalte); 
	} while (msg != setStoneMsg::success);

	return spalte;
}
