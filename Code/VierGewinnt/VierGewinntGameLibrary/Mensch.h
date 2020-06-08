#pragma once
#include "Spieler.h"
#include "Spielfeld.h"
#include <memory>

class Mensch :
    public Spieler
{
public:
    Mensch(std::shared_ptr<Team> team, std::string name);
    ~Mensch() override;
    std::string getName();
    void playStep(Spielfeld& spielfeld) override;

protected:
    std::string m_name;
    const std::shared_ptr<Team> m_team;
};

