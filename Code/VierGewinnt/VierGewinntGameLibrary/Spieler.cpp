#include "Spieler.h"
//#include "pch.h"

Spieler::Spieler(const std::shared_ptr<const Team> team, const std::string name)
	:m_name(name)
	,m_team(team)
{
}

Spieler::~Spieler()
{
}

const std::shared_ptr<const Team> Spieler::getTeam() const
{
	return m_team;
}

const std::string Spieler::getName() const
{
	return m_name;
}
