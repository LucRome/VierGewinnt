#include "Menue.h"
#include "Spieler.h"
#include "Horizontal.h"
#include "Vertikal.h"
#include "Mensch.h"
#include "Zufall.h"
#include "Schlau.h"
#include "GameController.h"

Menue::Menue()
{
}

Menue::~Menue()
{
}

void Menue::Spielbeginn()
{
	std::shared_ptr<Spieler> gewinner;
	char symbol;
	std::cout << "Wieviele Spieler spielen?" << std::endl;
	std::cin >> Spieleranzahl;
	/*std::cout << "wieviele Teams soll es geben?" << std::endl;
	std::cin >> Teamanzahl;*/ //braucht man eigentlich nicht, momentan nicht möglich mehrere Spieler in einem Team zu haben 
	for (int i = 0; i < Spieleranzahl; i++)
	{
		std::cout << "Welche Art Spieler soll Spieler" << i << " sein" << std::endl;
		std::cout << "1=Mensch; 2=Vertikal Bot; 3=Horizontal Bot; 4= Zufalls Bot; 5=Schlauer Bot" << std::endl;
		std::cin >> m_SpielerArt;

		switch (m_SpielerArt)
		{
		case 1:
		{
			std::cout << "Symbol: ";
			std::cin >> symbol; // muss hier eingelesen werden, weil die Bots haben Standardwerte
			std::cout << "Wie soll Spieler" << i << " heißen" << std::endl;
			std::cin >> m_Spielername;
			/*std::cout << "Wie soll dein Team heißen?" << std::endl;
			std::cin >> m_Teamname;*/
			m_Team[i] = std::make_shared<Team>(m_Teamname, symbol);
			m_Spieler.push_back(std::make_shared<Mensch>(m_Team[i], m_Spielername));
			break;
		}
		case 2:
		{
			m_Team[i] = std::make_shared<Team>("Vertikale Loser", 'x');
			m_Spieler.push_back(std::make_shared<Vertikal>(m_Team[i]));
			break;
		}
		case 3:
		{
			m_Team[i] = std::make_shared<Team>("Horizontale Kleindenker", 'o');
			m_Spieler.push_back(std::make_shared<Horizontal>(m_Team[i]));
			break;
		}
		case 4:
		{
			m_Team[i] = std::make_shared<Team>("Die Planlosen", 'p');
			m_Spieler.push_back(std::make_shared<Zufall>(m_Team[i]));
			break;
		}
		case 5:
		{
			m_Team[i] = std::make_shared<Team>("Die Genialen", 'v');
			m_Spieler.push_back(std::make_shared<Schlau>(m_Team[i]));
			break;
		}
		default:
		{
			std::cout << "Wer zu dumm ist die richtige Zahl einzugeben hat es nicht verdient das Spiel zu spielen" << std::endl;
		}
		}
		//Teambeitreten(m_Spieler[i], m_Team[i]);
		
	}
	GameController gameController = GameController(m_Spieler);
	gameController.playGame();
}

void Menue::Teamausgeben(std::shared_ptr<Team> Team)
{
	std::cout << Team->getName() << std::endl;
}

void Menue::horizontalAusgeben(std::shared_ptr<Horizontal> horizon)
{
	std::cout << horizon->getName() << std::endl;
}
//gitignore