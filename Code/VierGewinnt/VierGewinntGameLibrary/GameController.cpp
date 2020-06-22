//#include "pch.h"
#include "GameController.h"
#include "Spieler.h"


GameController::GameController(std::vector<std::shared_ptr<Spieler>> spieler)
{
	m_spieler = spieler;
	m_spielerDran = spieler[0];
	m_teamDran = 0;
}

GameController::~GameController()
{
}

void GameController::playGame() //Erstmal: spielen bis Feld voll
{
	while ((!m_spielfeld.isVoll()) && (!m_Regelwerk.gewonnen(m_spielfeld, *m_spielerDran->getTeam()))) {
		playStep();
	}
	ConsolePrinter::printField(m_spielfeld);
	ConsolePrinter::printMessage("Feld voll");
}

void GameController::playStep()
{
	int spalte = 0;
	ConsolePrinter::printField(m_spielfeld);
	ConsolePrinter::printMessage("Spieler: ");
	ConsolePrinter::printMessage(m_spielerDran->getName());
	spalte = m_spielerDran->chooseRow(m_spielfeld);
	m_spielfeld.placeStone(*m_spielerDran->getTeam(), spalte);
	spielerwechsel();
}

void GameController::spielerwechsel()
{
	m_teamDran = (m_teamDran + 1) % (int)m_spieler.size();
	m_spielerDran = m_spieler[m_teamDran];
}