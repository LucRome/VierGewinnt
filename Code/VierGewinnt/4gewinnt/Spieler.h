#pragma once
#include <string>
#include <memory>

class Team;

class Spieler
{
public:
	Spieler(std::shared_ptr<Team> team, std::string name);
	virtual ~Spieler();

protected:
	std::string m_name;
	std::shared_ptr<Team> m_team;


};

