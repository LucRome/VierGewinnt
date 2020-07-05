#include "pch.h"
#include "BotHelper.h"
#include "Spielfeld.h"
#include "Team.h"
#include "Horizontal.h"
#include "Spielsteine.h"
#include <memory>

BotHelper::BotHelper()
{
}

BotHelper::~BotHelper()
{
}

Spielfeld BotHelper::setSpielfeld()
{
	Spielfeld spielfeld = Spielfeld();
	Team team1 = Team("team1", 'x');
	Team team2 = Team("team2", 'o');
	std::shared_ptr<Spielsteine> x = std::make_shared<Spielsteine>(team1);
	std::shared_ptr<Spielsteine> o = std::make_shared<Spielsteine>(team2);
	std::array<std::array<std::shared_ptr<Spielsteine>, 6>, 5> horizontalFeld; //Spalte, Zeile
	horizontalFeld = {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		x,		 o,		  x,	   o,		x,		 o
	};
	spielfeld.setSpielfeldfuerTests(horizontalFeld);
	return spielfeld;
}

int BotHelper::spalteHorizontal()
{
	std::shared_ptr<Team> team = std::make_shared<Team>("Test", 't');
	Horizontal boti = Horizontal(team);
	Spielfeld spielfeld = setSpielfeld();
	int spalte = boti.chooseRow(spielfeld);
	return spalte;
}