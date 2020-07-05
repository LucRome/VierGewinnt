//#include "pch.h"
#include "Team.h"

Team::Team(const std::string name, const char symbol)
	:m_symbol(symbol)
	,m_name(name)
{
}

Team::~Team()
{
}

std::string Team::getName() const
{
	return m_name;
}

char Team::getSymbol() const
{
	return m_symbol;
}