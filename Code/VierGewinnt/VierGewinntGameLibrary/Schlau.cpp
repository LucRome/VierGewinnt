#include "Schlau.h"
#include "pch.h"

Schlau::Schlau(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Schlau::~Schlau()
{
}


int Schlau::chooseRow(Spielfeld& spielfeld)
{
	return 0;
}
