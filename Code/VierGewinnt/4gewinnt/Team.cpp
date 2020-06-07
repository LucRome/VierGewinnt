#include "Team.h"


Team::Team(std::string Name)
{
	m_Name = Name;
}

Team::~Team()
{
}

std::string Team::getName()
{
	return m_Name;
}

char Team::getSymbol()
{
	return m_symbol;
}
