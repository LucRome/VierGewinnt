#pragma once
#include "Spieler.h"
#include "Team.h"
#include <array>
#include <queue>
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

    int m_maxEnemyStreak = 3;

    std::shared_ptr<Team> m_enemyTeamModel;

    static const int spielfeldSizeZeile; //muss verändert werden wenn Spielfeld größe Ändert, momentan unnütz
    //6 ersetzen durch Spaltenzahl des Spielfelds
    std::array<int, 6> heights = { 0 };

    std::priority_queue<SpalteAndStreak> streaksFriendly;
    std::priority_queue<SpalteAndStreak> streaksEnemy;

    bool cmpSpalteAndStreakGreaterStreak(const SpalteAndStreak& a, const SpalteAndStreak& b);

    //Priority Queue CPP Reference: https://en.cppreference.com/w/cpp/container/priority_queue
};