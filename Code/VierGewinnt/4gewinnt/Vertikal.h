#pragma once
#include "Spieler.h"

class Vertikal :
    public Spieler
{
public:
    Vertikal(std::shared_ptr<Team> team, std::string name = "Gilderoy Lockhart");
    ~Vertikal() override;
    std::string getName();

protected:
    std::string m_name;
    std::shared_ptr<Team> m_team;
};

