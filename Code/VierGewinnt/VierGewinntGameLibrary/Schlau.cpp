#include "Schlau.h"
#include "Spielfeld.h"
//#include "pch.h"

Schlau::Schlau(const std::shared_ptr<const Team> team, const std::string name)
	:Spieler(team, name)
{
}

Schlau::~Schlau()
{
}


int Schlau::chooseRow(const Spielfeld& spielfeld)
{
	//testen ob GegnerTeam herausgefunden werden muss
	if (m_enemyTeamSymbol == ' ') {
		setEnemyTeam(spielfeld);
	}
	return 0;
}

void Schlau::setEnemyTeam(const Spielfeld& spielfeld)
{
	const Coord size = spielfeld.getSize();
	for (int zeile = 0; zeile < size.zeile; zeile++) {

	}
}
