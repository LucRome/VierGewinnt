#include "Schlau.h"

Schlau::Schlau(std::shared_ptr<Team> team, std::string name)
	:Spieler(team, name)
{
}

Schlau::~Schlau()
{
}

std::string Schlau::getName()
{
	return m_name;
}

int Schlau::chooseRow(Spielfeld& spielfeld)
{
}
