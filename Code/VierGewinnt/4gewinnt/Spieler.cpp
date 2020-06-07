#include "Spieler.h"


Spieler::Spieler(std::shared_ptr<Team> team, std::string name)
{
	m_name = name;
	m_team = team;
}

Spieler::~Spieler()
{
}
