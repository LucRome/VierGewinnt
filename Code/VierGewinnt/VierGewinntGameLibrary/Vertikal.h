#pragma once
#include "Spieler.h"
#include "pch.h"
class Vertikal :
    public Spieler
{
public:
    Vertikal(std::shared_ptr<Team> team, std::string name = "Gilderoy Lockhart");
    ~Vertikal() override;
    int chooseRow(Spielfeld& spielfeld) override;
};

