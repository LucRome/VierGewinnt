#pragma once
#include "Spieler.h"
//#include "pch.h"
class Zufall :
    public Spieler
{
public:
    Zufall(const std::shared_ptr<const Team> team, const std::string name = "Luna Lovegood");
    ~Zufall() override;
    int chooseRow(const Spielfeld& spielfeld) override;
};

