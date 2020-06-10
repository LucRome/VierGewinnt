#include "Vertikal.h"

Vertikal::Vertikal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Vertikal::~Vertikal()
{
}

int Vertikal::chooseRow(Spielfeld& spielfeld)
{
}
