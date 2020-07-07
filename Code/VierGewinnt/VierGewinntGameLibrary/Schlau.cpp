#include "Schlau.h"
#include "Spielfeld.h"
#include "Regelwerk.h"
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
	int spalte;
	const Coord size = spielfeld.getSize();

	//testen ob GegnerTeam herausgefunden werden muss
	if (!m_enemyTeamModel) {
		setEnemyTeam(spielfeld);
	}

	//Alle Arrays auffüllen:
	//1. für jede Spalte die Zeile in die geworfen werden würde ermitteln und die freundliche und feindliche Streak für dieses Feld ermitteln
	for (int spalte = 0; spalte < size.spalte; spalte++) {
		heights[spalte] = spielfeld.getLowestLevel(spalte);
		streaksFriendly.push({ spalte, Regelwerk::highestStreak({ heights[spalte], spalte }, spielfeld, *m_team) });
		streaksEnemy.push({ spalte, Regelwerk::highestStreak({heights[spalte], spalte}, spielfeld, *m_enemyTeamModel) });
	}

	if (streaksEnemy.top().streak == m_maxEnemyStreak) { //wenn Gegner unterbrochen werden MUSS -> unterbrechen
		spalte = streaksEnemy.top().spalte;
	}
	else { //sonst: eigenes Spiel weiter machen
		spalte = streaksFriendly.top().spalte;
	}

	//Priority Queues wieder leeren
	while (!streaksEnemy.empty())
	{
		streaksEnemy.pop();
	}
	while (!streaksFriendly.empty()) {
		streaksFriendly.pop();
	}
	return spalte;
}

void Schlau::setEnemyTeam(const Spielfeld& spielfeld)
{
	const Coord size = spielfeld.getSize();
	for (int zeile = size.zeile-1; zeile >= 0; zeile--) { //von unten nach oben
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			std::shared_ptr<Spielsteine> stein = spielfeld.getPosition({ zeile, spalte });
			if (stein && stein->getSymbol() != m_team->getSymbol()) {
				m_enemyTeamModel = std::make_shared<Team>("", stein->getSymbol());
				return;
			}
		}
	}
}

bool Schlau::cmpSpalteAndStreakGreaterStreak(const SpalteAndStreak& a, const SpalteAndStreak& b)
{
	return a.streak > b.streak;
}
