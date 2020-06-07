#pragma once
#include <memory>
#include "Team.h"


class Spielsteine
{
public:
	Spielsteine(Team& team);
	~Spielsteine();
	char getSymbol() const;
	
protected:
	const Team& m_team;	//Spielstein wird von Team erstellt -> Team ist vorhanden, gibt auch keinen Grund Team zu ändern
};

 