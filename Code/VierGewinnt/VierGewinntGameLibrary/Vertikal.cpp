#include "Vertikal.h"

Vertikal::Vertikal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Vertikal::~Vertikal()
{
}

std::string Vertikal::getName()
{
	return m_name;
}

int Vertikal::playStep(Spielfeld& spielfeld)
{
}
