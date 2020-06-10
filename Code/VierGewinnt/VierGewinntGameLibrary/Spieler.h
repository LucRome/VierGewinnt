#pragma once
#include <string>
#include <memory>

class Team;
class Spielfeld;

class Spieler
{
public:
	Spieler(std::shared_ptr<Team> team, std::string name);
	virtual ~Spieler();
	std::shared_ptr<Team> getTeam();
	virtual int chooseRow(Spielfeld& spielfeld) = 0; //Darf diese Klasse abstract sein?

protected:
	const std::string m_name;
	const std::shared_ptr<Team> m_team;


};

