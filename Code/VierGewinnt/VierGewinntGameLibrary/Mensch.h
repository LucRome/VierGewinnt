#pragma once
#include "Spieler.h"
#include "Spielfeld.h"
#include <memory>
//#include "pch.h"
class Mensch :
    public Spieler
{
public:
    Mensch(const std::shared_ptr<const Team> team, const std::string name);
    ~Mensch() override;
    int chooseRow(const Spielfeld& spielfeld) const override;

private:
    int io(const Spielfeld& spielfeld) const;
};

