#include "Zufall.h"
#include "pch.h"
Zufall::Zufall(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Zufall::~Zufall()
{
}

int Zufall::chooseRow(Spielfeld& spielfeld)
{
	return 0;
}
