#pragma once
#include <memory>
#include <vector>
#include "ConsolePrinter.h"
#include "Regelwerk.h"
//#include "pch.h"

class Team;
class Spieler;

class GameController
{
public:
	GameController(std::vector<std::shared_ptr<Spieler>> spieler);
	~GameController();

	void playGame();
	bool playStep();
protected:
	void spielerwechsel();
	
	
	std::vector<std::shared_ptr<Team>> m_teams;
	std::vector<std::shared_ptr<Spieler>> m_spieler;

	CoordAndSuccess m_coordAndSuccess;

	int m_teamDran;
	Spielfeld m_spielfeld;
	const Spielfeld& constFeld = m_spielfeld;
	std::shared_ptr<Spieler> m_spielerDran;
};