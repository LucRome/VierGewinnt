#include "Schlau.h"

Schlau::Schlau(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
	m_name = name;
	m_team = team;
}

Schlau::~Schlau()
{
}

std::string Schlau::getName()
{
	return m_name;
}
