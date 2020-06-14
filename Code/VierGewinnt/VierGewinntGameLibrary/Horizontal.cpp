#include "Horizontal.h"
//#include "pch.h"

Horizontal::Horizontal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Horizontal::~Horizontal()
{
}

int Horizontal::chooseRow(Spielfeld& spielfeld)
{
	return 0;
}
