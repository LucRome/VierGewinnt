//#include "pch.h"
#include "Spielsteine.h"

Spielsteine::Spielsteine(Team& team)
	:m_team(team) //nehme mal an 0 passt
{
	m_counter = 0;
}

Spielsteine::~Spielsteine()
{
}

char Spielsteine::getSymbol() const
{
	return m_team.getSymbol();
}

void Spielsteine::setZ�hler(int z�hler)
{
	m_counter = z�hler;
}
