#pragma once
#include "Spieler.h"
//#include "pch.h"
class Schlau :
    public Spieler
{
public:
    Schlau(std::shared_ptr<Team> team, std::string name = "Severus Snape");
    ~Schlau() override;
    int chooseRow(Spielfeld& spielfeld) override;
};

