#pragma once
#include "Spieler.h"
#include "Team.h"
#include <array>
//#include "pch.h"
class Schlau :
    public Spieler
{
public:
    Schlau(const std::shared_ptr<const Team> team, const std::string name = "Severus Snape");
    ~Schlau() override;
    int chooseRow(const Spielfeld& spielfeld) const override;

private:
    void setEnemyTeamSymbol(const Spielfeld& spielfeld);
    Team enemyTeamModel = Team("", ' ');
    //6 ersetzen durch Spaltenzahl des Spielfelds
    std::array<int, 6> levels
};