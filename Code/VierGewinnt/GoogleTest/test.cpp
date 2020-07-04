#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//Testabdeckung für den Horizontal-Bot:
	//leeres Spielfeld -> Erwartung: 0
	//Objekt in erster Spalte-> Erwartung: 1
	//Erste Zeile komplett gefüllt -> Erwartung: 0
	//In letzter Zeile fehlt genau ein Stein -> Erwartung: legt dort wo ein Stein fehlt

//Testabdeckung für den Vertikalen-Bot:
	//leeres Spielfeld -> Erwartung: 0
	//Objekt in erster Splate -> Erwartung: 0
	//erste Spalte gefüllt -> Erwartung: 1
	//in letzter Zeile fehlt genau ein Stein -> Erwartung: legt dort wo ein Stein fehlt

//Testabdeckung für den Zufalls-Bot:
	//! Random Funktion muss gemockt werden 
		//leeres Spielfeld -> Erwartung: gemockter Random Wert
		//in letzter Zeile fehlt genau ein Stein -> Erwartung: legt dort wo ein Stein fehlt

//Testabdeckung für den Menschen:
	//! io Funktion muss gemockt werden
		//Spaltenzahl in der io entspricht return-Wert der Funktion
		//Zahlen<0 werden abgefangen --> Bug
		//Zahlen>Spaltenanzahl werden abgefangen -->ja
		//Strings werden abgefangen --> Bug