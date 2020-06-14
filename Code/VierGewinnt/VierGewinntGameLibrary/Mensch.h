#pragma once
#include "Spieler.h"
#include "Spielfeld.h"
#include <memory>
#include "pch.h"
class Mensch :
    public Spieler
{
public:
    Mensch(std::shared_ptr<Team> team, std::string name);
    ~Mensch() override;
    int chooseRow(Spielfeld& spielfeld) override;
};

