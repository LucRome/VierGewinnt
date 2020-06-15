// ProgramVierGewinnt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include <string.h>
#include <memory>
#include <iostream>
#include <Horizontal.h>
#include <Mensch.h>
#include <Schlau.h>
#include <Spieler.h>
#include <Team.h>
#include <Vertikal.h>
#include <Zufall.h>
#include "Menue.h"

int main() {
	/*auto menü1 = std::make_unique<Menue>();
	auto team1 = std::make_shared<Team>("Harald", 'b');
	auto horizontal1 = std::make_shared<Horizontal>(team1);
	menü1->horizontalAusgeben(horizontal1);
	menü1->Spielbeginn();*/
	auto menu1 = Menue();
	menu1.Spielbeginn();

}
