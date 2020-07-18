#pragma once
#include "Spieler.h"
//#include "pch.h"

class Horizontal :
    public Spieler
{
public:
    Horizontal(const std::shared_ptr<const Team> team, const std::string name = "Ernie Macmillan");
    ~Horizontal() override;
    int chooseRow(const Spielfeld& spielfeld) override;
};

