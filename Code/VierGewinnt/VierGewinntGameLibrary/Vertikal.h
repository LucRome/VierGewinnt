#pragma once
#include "Spieler.h"

class Vertikal :
    public Spieler
{
public:
    Vertikal(std::shared_ptr<Team> team, std::string name = "Gilderoy Lockhart");
    ~Vertikal() override;
    std::string getName();
    int chooseRow(Spielfeld& spielfeld) override;
};

