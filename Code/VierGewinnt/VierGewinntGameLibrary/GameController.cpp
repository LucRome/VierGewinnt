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
	bool win;
	do {
		win = playStep();
	} while (!m_spielfeld.isVoll() && !win);
	ConsolePrinter::printField(m_spielfeld);
	if (win) {
		ConsolePrinter::printMessage(m_spielerDran->getName());
		ConsolePrinter::printMessage("hat gewonnen");
	}
	else {
		ConsolePrinter::printMessage("Feld voll");
	}
}

bool GameController::playStep()
{
	bool win;
	int spalte = 0;
	
	ConsolePrinter::printField(constFeld);
	ConsolePrinter::printMessage("Spieler: ");
	ConsolePrinter::printMessage(m_spielerDran->getName());
	
	spalte = m_spielerDran->chooseRow(constFeld);
	m_coordAndSuccess = m_spielfeld.placeStone(*m_spielerDran->getTeam(), spalte);
	
	win = Regelwerk::gewonnen(m_coordAndSuccess.coordinates, constFeld, *m_spielerDran->getTeam());
	if (win == true) {
		return win;
	}
	else {
		spielerwechsel();
		return win;
	}
}

void GameController::spielerwechsel()
{
	m_teamDran = (m_teamDran + 1) % (int)m_spieler.size();
	m_spielerDran = m_spieler[m_teamDran];
}