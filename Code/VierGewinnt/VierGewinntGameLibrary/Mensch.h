#pragma once
#include "Spieler.h"

class Mensch :
    public Spieler
{
public:
    Mensch(std::shared_ptr<Team> team, std::string name);
    ~Mensch() override;
    std::string getName();

protected:
    std::string m_name;
    std::shared_ptr<Team> m_team;
};

