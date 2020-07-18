#pragma once
#include "Spieler.h"
//#include "pch.h"
class Vertikal :
    public Spieler
{
public:
    Vertikal(const std::shared_ptr<const Team> team, const std::string name = "Gilderoy Lockhart");
    ~Vertikal() override;
    int chooseRow(const Spielfeld& spielfeld) override;
};

