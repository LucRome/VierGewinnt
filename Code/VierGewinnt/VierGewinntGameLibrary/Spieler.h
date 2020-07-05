#pragma once
#include <string>
#include <memory>
//#include "pch.h"
class Team;
class Spielfeld;

class Spieler
{
public:
	Spieler(const std::shared_ptr<const Team> team, const std::string name);
	virtual ~Spieler();
	const std::shared_ptr<const Team> getTeam() const;
	const std::string getName() const;
	virtual int chooseRow(const Spielfeld& spielfeld) const = 0;

protected:
	const std::string m_name;
	const std::shared_ptr<const Team> m_team;


};

