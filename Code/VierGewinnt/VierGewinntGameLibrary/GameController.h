#pragma once
#include <memory>
#include <vector>
#include "ConsolePrinter.h"

class Team;
class Spieler;

class GameController
{
public:
	GameController(std::vector<std::shared_ptr<Spieler>> spieler);
	~GameController();

	void playGame();
	void playStep();
protected:
	void spielerwechsel();
	
	
	std::vector<std::shared_ptr<Team>> m_teams;
	std::vector<std::shared_ptr<Spieler>> m_spieler;

	int m_teamDran;
	std::shared_ptr<Spielfeld> m_spielfeld = std::make_shared<Spielfeld>(); //muss des überhaupt n Pointer sein?
	std::shared_ptr<Spieler> m_spielerDran;
	
	
};