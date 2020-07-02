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
	GameController(const std::vector<const std::shared_ptr<const Spieler>> spieler);
	~GameController();

	void playGame();
	bool playStep();
protected:
	void spielerwechsel();
	
	
	const std::vector<const std::shared_ptr<const Team>> m_teams;
	const std::vector<const std::shared_ptr<const Spieler>> m_spieler;

	CoordAndSuccess m_coordAndSuccess;

	int m_teamDran;
	Spielfeld m_spielfeld;
	std::shared_ptr<Spieler> m_spielerDran;
};