#pragma once
#include <memory>

class Team;


class Spielsteine
{
public:
	Spielsteine(Team& team);
	~Spielsteine();
	
protected:
	const Team& m_team;	//Spielstein wird von Team erstellt -> Team ist vorhanden, gibt auch keinen Grund Team zu ändern
};

 