#include "Mensch.h"

Mensch::Mensch(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	m_name = name;
	m_team = team;
}

Mensch::~Mensch()
{
}

std::string Mensch::getName()
{
	return m_name;
}
