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
#include "ConsolePrinter.h"

int main() {
	auto menu1 = Menue();
	menu1.Spielbeginn();

}
