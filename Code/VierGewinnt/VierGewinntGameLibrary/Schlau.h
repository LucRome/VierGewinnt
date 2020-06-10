#pragma once
#include "Spieler.h"

class Schlau :
    public Spieler
{
public:
    Schlau(std::shared_ptr<Team> team, std::string name = "Severus Snape");
    ~Schlau() override;
    std::string getName();
    int chooseRow(Spielfeld& spielfeld) override;
};

