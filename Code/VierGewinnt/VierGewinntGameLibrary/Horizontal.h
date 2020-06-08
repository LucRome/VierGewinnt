#pragma once
#include "Spieler.h"

class Horizontal :
    public Spieler
{
public:
    Horizontal(std::shared_ptr<Team> team, std::string name = "Ernie Macmillan");
    ~Horizontal() override;
    std::string getName();
    void playStep(Spielfeld& spielfeld) override;

protected:
    std::string m_name;
    std::shared_ptr<Team> m_team;
};

