#include "Horizontal.h"

Horizontal::Horizontal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	m_name = name;
	m_team = team;
}

Horizontal::~Horizontal()
{
}

std::string Horizontal::getName()
{
	return m_name;
}
