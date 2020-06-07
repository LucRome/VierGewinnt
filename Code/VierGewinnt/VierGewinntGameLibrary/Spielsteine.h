#pragma once
#include <memory>
#include "Team.h"


class Spielsteine
{
public:
	Spielsteine(Team& team);
	~Spielsteine();
	char getSymbol() const;
	void setZ�hler(int z�hler);

	
protected:
	const Team& m_team;	//Spielstein wird von Team erstellt -> Team ist vorhanden, gibt auch keinen Grund Team zu �ndern
	int m_counter;
};

 