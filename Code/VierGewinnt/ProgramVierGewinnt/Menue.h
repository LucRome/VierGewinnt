#pragma once
#include <iostream>
#include <memory>
#include <string.h>
#include "Spieler.h"
#include "Team.h"

class Horizontal;
class Vertikal;
class Mensch;
class Zufall;
class Schlau;

class Menue
{
public:
	Menue();
	~Menue();

	//void Teambeitreten(std::shared_ptr<Spieler> Spieler, std::shared_ptr<Team> Team);
	void Spielbeginn();
	//void Spielerausgeben(std::shared_ptr<Spieler> Spieler);
	void Teamausgeben(std::shared_ptr<Team> Team);
	void horizontalAusgeben(std::shared_ptr<Horizontal> horizon);

private:
	std::vector<std::shared_ptr<Spieler>> m_Spieler;
	int Spieleranzahl;
	int m_SpielerID;
	int m_SpielerArt;
	std::string m_Spielername;
	std::shared_ptr<Team> m_Team[100];
	int Teamanzahl;
	std::string m_Teamname;
	int m_TeamID;
};
