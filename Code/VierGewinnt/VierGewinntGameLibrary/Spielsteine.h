#pragma once
#include <memory>
#include "Team.h"
//#include "pch.h"

class Spielsteine
{
public:
	Spielsteine(Team& team);
	~Spielsteine();
	char getSymbol() const;
	void setZähler(int zähler);

	
protected:
	Team& m_team;	//Spielstein wird von Team erstellt -> Team ist vorhanden, gibt auch keinen Grund Team zu ändern
	int m_counter;
};

 