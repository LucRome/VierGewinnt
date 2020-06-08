#include "pch.h"
#include "GameController.h"
#include "Spieler.h"


GameController::GameController(std::vector<std::shared_ptr<Spieler>> spieler)
{
	m_spieler = spieler;
	m_teamDran = 0;
}

GameController::~GameController()
{
}

void GameController::playStep()
{
	ConsolePrinter::printField(m_spielfeld);
	m_spielerDran->playStep(*m_spielfeld);
	spielerwechsel();
}

void GameController::spielerwechsel()
{
	m_teamDran = (m_teamDran + 1) % (int)m_teams.size();
	m_spielerDran = m_spieler[m_teamDran];
}
