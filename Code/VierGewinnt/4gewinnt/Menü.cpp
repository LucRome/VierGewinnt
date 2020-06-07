#include "Menü.h"
#include "Spieler.h"
#include "Horizontal.h"
#include "Vertikal.h"
#include "Mensch.h"
#include "Zufall.h"
#include "Schlau.h"

Menü::Menü()
{
}

Menü::~Menü()
{
}

void Menü::Spielbeginn()
{
	std::cout << "Wieviele Spieler spielen?" << std::endl;
	std::cin >> Spieleranzahl;
	std::cout << "wieviele Teams soll es geben?" << std::endl;
	std::cin >> Teamanzahl;
	for (int i = 0; i < Spieleranzahl; i++)
	{
		std::cout << "Welche Art Spieler soll Spieler" << i << " sein" << std::endl;
		std::cout << "1=Mensch; 2=Vertikal Bot; 3=Horizontal Bot; 4=Schlauer Bot; 5=Zufalls Bot" << std::endl;
		std::cin >> m_SpielerArt;

		switch (m_SpielerArt)
		{
		case 1:
		{
			std::cout << "Wie soll Spieler" << i << " heißen" << std::endl;
			std::cin >> m_Spielername;
			std::cout << "Wie soll dein Team heißen?" << std::endl;
			std::cin >> m_Teamname;
			m_Team[i] = std::make_shared<Team>(m_Teamname);
			m_Spieler[i] = std::make_shared<Mensch>(m_Team[i], m_Spielername);
			break;
		}
		case 2:
		{
			m_Team[i] = std::make_shared<Team>("Vertikale Loser");
			m_Spieler[i] = std::make_shared<Vertikal>(m_Team[i]);
			break;
		}
		case 3:
		{
			m_Team[i] = std::make_shared<Team>("Horizontale Kleindenker");
			m_Spieler[i] = std::make_shared<Horizontal>(m_Team[i]);
			break;
		}
		case 4:
		{
			m_Team[i] = std::make_shared<Team>("Die Planlosen");
			m_Spieler[i] = std::make_shared<Zufall>(m_Team[i]);
			break;
		}
		case 5:
		{
			m_Team[i] = std::make_shared<Team>("Die Genialen");
			m_Spieler[i] = std::make_shared<Schlau>(m_Team[i]);
			break;
		}
		default:
		{
			std::cout << "Wer zu dumm ist die richtige Zahl einzugeben hat es nicht verdient das Spiel zu spielen" << std::endl;
		}
		}
		//Teambeitreten(m_Spieler[i], m_Team[i]);
	}
}

void Menü::Teamausgeben(std::shared_ptr<Team> Team)
{
	std::cout << Team->getName() << std::endl;
}

void Menü::horizontalAusgeben(std::shared_ptr<Horizontal> horizon)
{
	std::cout << horizon->getName() << std::endl;
}
//gitignore