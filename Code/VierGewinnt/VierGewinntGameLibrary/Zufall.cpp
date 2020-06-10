#include "Zufall.h"

Zufall::Zufall(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Zufall::~Zufall()
{
}

std::string Zufall::getName()
{
	return m_name;
}

void Zufall::playStep(Spielfeld& spielfeld)
{
}
