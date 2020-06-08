#pragma once
#include "Spieler.h"

class Zufall :
    public Spieler
{
public:
    Zufall(std::shared_ptr<Team> team, std::string name = "Luna Lovegood");
    ~Zufall() override;
    std::string getName();
};

