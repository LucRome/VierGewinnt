#pragma once
#include "Spieler.h"
#include "pch.h"
class Zufall :
    public Spieler
{
public:
    Zufall(std::shared_ptr<Team> team, std::string name = "Luna Lovegood");
    ~Zufall() override;
    int chooseRow(Spielfeld& spielfeld) override;
};

