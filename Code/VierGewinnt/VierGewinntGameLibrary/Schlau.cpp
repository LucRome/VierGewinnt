#include "Schlau.h"
//#include "pch.h"

Schlau::Schlau(const std::shared_ptr<const Team> team, const std::string name)
	:Spieler(team, name)
{
}

Schlau::~Schlau()
{
}


int Schlau::chooseRow(const Spielfeld& spielfeld) const
{
	return 0;
}
