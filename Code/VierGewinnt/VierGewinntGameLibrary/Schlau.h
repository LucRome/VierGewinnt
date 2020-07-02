#pragma once
#include "Spieler.h"
//#include "pch.h"
class Schlau :
    public Spieler
{
public:
    Schlau(const std::shared_ptr<const Team> team, const std::string name = "Severus Snape");
    ~Schlau() override;
    int chooseRow(const Spielfeld& spielfeld) const override;
};

