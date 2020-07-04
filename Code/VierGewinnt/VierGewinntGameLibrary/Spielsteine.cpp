//#include "pch.h"
#include "Spielsteine.h"

Spielsteine::Spielsteine(const Team& team)
	:m_team(team) 
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
