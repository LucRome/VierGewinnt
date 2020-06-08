#include "Vertikal.h"

Vertikal::Vertikal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	m_name = name;
	m_team = team;
}

Vertikal::~Vertikal()
{
}

std::string Vertikal::getName()
{
	return m_name;
}

void Vertikal::playStep(Spielfeld& spielfeld)
{
}
