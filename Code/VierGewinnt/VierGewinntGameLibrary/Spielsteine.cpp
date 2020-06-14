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

void Spielsteine::setZähler(int zähler)
{
	m_counter = zähler;
}
