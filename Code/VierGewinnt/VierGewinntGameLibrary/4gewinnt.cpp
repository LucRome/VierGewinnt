#include <string.h>
#include <memory>
#include <iostream>
#include "Horizontal.h"
#include "Mensch.h"
#include "Men�.h"
#include "Schlau.h"
#include "Spieler.h"
#include "Team.h"
#include "Vertikal.h"
#include "Zufall.h"

int main() {
	auto men�1 = std::make_unique<Men�>();
	auto team1 = std::make_shared<Team>("Harald");
	auto horizontal1 = std::make_shared<Horizontal>(team1);
	men�1->horizontalAusgeben(horizontal1);
}