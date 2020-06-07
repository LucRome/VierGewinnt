#include "pch.h"
#include "GameController.h"


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
	ConsolePrinter::printField();
}

void GameController::spielerwechsel()
{
	m_teamDran = (m_teamDran + 1) % (int)m_teams.size();
	m_spielerDran = m_spieler[m_teamDran];
}
