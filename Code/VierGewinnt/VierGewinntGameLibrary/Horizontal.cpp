#include "Horizontal.h"

Horizontal::Horizontal(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Horizontal::~Horizontal()
{
}

std::string Horizontal::getName()
{
	return m_name;
}

void Horizontal::playStep(Spielfeld& spielfeld)
{
}
