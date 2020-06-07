#include <string.h>
#include <memory>
#include <iostream>
#include "Horizontal.h"
#include "Mensch.h"
#include "Menü.h"
#include "Schlau.h"
#include "Spieler.h"
#include "Team.h"
#include "Vertikal.h"
#include "Zufall.h"

int main() {
	auto menü1 = std::make_unique<Menü>();
	auto team1 = std::make_shared<Team>("Harald");
	auto horizontal1 = std::make_shared<Horizontal>(team1);
	menü1->horizontalAusgeben(horizontal1);
}