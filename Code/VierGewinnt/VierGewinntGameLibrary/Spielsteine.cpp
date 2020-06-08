#include "pch.h"
#include "Spielsteine.h"

Spielsteine::Spielsteine(Team& team)
	:m_team(team)
	, m_counter(0) //nehme mal an 0 passt
{
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
