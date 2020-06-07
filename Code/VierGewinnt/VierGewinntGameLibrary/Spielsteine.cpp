#include "pch.h"
#include "Spielsteine.h"

Spielsteine::Spielsteine(Team& team)
	:m_team(team)
{
}

Spielsteine::~Spielsteine()
{
}

char Spielsteine::getSymbol() const
{
	return m_team.getSymbol();
}

void Spielsteine::setZähler(int zähler)
{
	m_counter = zähler;
}
