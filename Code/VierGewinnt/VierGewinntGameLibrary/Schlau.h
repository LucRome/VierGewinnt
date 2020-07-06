#pragma once
#include "Spieler.h"
#include "Team.h"
#include <array>
#include "CoordAndSuccess.h"
//#include "pch.h"
class Schlau :
    public Spieler
{
public:
    Schlau(const std::shared_ptr<const Team> team, const std::string name = "Severus Snape");
    ~Schlau() override;
    int chooseRow(const Spielfeld& spielfeld) override;

private:
    void setEnemyTeam(const Spielfeld& spielfeld);

    char m_enemyTeamSymbol = ' ';

    static const int spielfeldSizeZeile; //muss verändert werden wenn Spielfeld größe Ändert
    //6 ersetzen durch Spaltenzahl des Spielfelds
    std::array<int, 6> heights = { 0 };
    std::array<int, 6> streaksFriendly = { 0 };
    std::array<int, 6> streaksEnemy = { 0 };
};