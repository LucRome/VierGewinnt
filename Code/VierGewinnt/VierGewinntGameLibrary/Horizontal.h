#pragma once
#include "Spieler.h"

class Horizontal :
    public Spieler
{
public:
    Horizontal(std::shared_ptr<Team> team, std::string name = "Ernie Macmillan");
    ~Horizontal() override;
    std::string getName();
    int playStep(Spielfeld& spielfeld) override;
};

