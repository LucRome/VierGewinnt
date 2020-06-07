#include "Zufall.h"

Zufall::Zufall(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	m_name = name;
	m_team = team;
}

Zufall::~Zufall()
{
}

std::string Zufall::getName()
{
	return m_name;
}
