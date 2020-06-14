#include "Spieler.h"
#include "pch.h"

Spieler::Spieler(std::shared_ptr<Team> team, std::string name)
	:m_name(name)
	,m_team(team)
{
}

Spieler::~Spieler()
{
}

std::shared_ptr<Team> Spieler::getTeam()
{
	return m_team;
}

std::string Spieler::getName()
{
	return m_name;
}
