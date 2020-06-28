//#include "pch.h"
#include "Regelwerk.h"
#include "Spielfeld.h"
#include "Spielsteine.h"
//#include "pch.h"
const Coord Regelwerk::d_waagerecht = { 0, 1 }; 
const Coord Regelwerk::d_senkrecht = { 1, 0 };
const Coord Regelwerk::d_diagonal1 = { 1, 1 };
const Coord Regelwerk::d_diagonal2 = { -1, 1 };


Regelwerk::Regelwerk() {

}

Regelwerk::~Regelwerk()
{
}


bool Regelwerk::gewonnen(Spielfeld& m_spielfeld, Team& team)
{
	bool gewinnen = false;
	if (waagerechtCheck(m_spielfeld, team) != 0)
	{
		return !gewinnen;
	}
	if (senkrechtCheck(m_spielfeld, team) != 0)
	{
		return !gewinnen;
	}
	if (diagonalCheck(m_spielfeld, team) != 0)
	{
		return !gewinnen;
	}
	return gewinnen;
}

bool Regelwerk::gewonnen(Coord coordinates, Spielfeld& m_spielfeld, Team& team)
{
	if (waagerechtCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	if (senkrechtCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	if (diagonalCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	return false;
}

bool Regelwerk::waagerechtCheck(Spielfeld& m_spielfeld, Team& team)
{
	int zähler = 0;	//keine Umlaute!!!
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	Coord size = m_spielfeld.getSize();
	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (Umgebung({ zeile, spalte }, d_waagerecht, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}
	return false;
}

bool Regelwerk::senkrechtCheck(Spielfeld& m_spielfeld, Team& team)
{
	int zähler = 0;
	int max_zähler = 0;
	Coord size = m_spielfeld.getSize();
	std::shared_ptr<Spielsteine> jetztDa;
	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (Umgebung({ zeile, spalte }, d_senkrecht, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}
	return false;
}

bool Regelwerk::diagonalCheck(Spielfeld& m_spielfeld, Team& team)
{
	int zähler = 0;
	int max_zähler = 0;
	Coord size = m_spielfeld.getSize();
	std::shared_ptr<Spielsteine> jetztDa;
	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (Umgebung({ zeile, spalte }, d_diagonal1, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}

	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (Umgebung({ zeile, spalte }, d_diagonal2, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}

	return false;
}

bool Regelwerk::waagerechtCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(coordinates, d_waagerecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::senkrechtCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(coordinates, d_senkrecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::diagonalCheck(Coord coordinates, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(coordinates, d_diagonal1, m_spielfeld, team) || Umgebung(coordinates, d_diagonal2, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}


bool Regelwerk:: Umgebung(Coord coordinates, Coord deltas, Spielfeld& m_spielfeld, Team& team)
{
	std::shared_ptr<Spielsteine> jetztDa;
	const Coord save = coordinates;
	int counter=0;
	int max_counter=0;
	coordinates += deltas;
	if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
		//immer prüfen ob Zielfeld noch im Spielfeld und ob Ziehlfeld != nullptr
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates)->getSymbol()))
		{
			coordinates += deltas;
			counter++;
			if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
					coordinates += deltas;
					counter++;
					if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
							/*Umgebung1 += zähler1;
							Umgebung2 += zähler2;*/
							counter++;
						}
					}
				}
			}
		}
	}
	coordinates = save;
	if (counter == 3) {
		m_spielfeld.getPosition(coordinates)->setZähler(counter);
		return true;
	}
	else if (ImSpielfeld(coordinates -= deltas, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
			coordinates -= deltas;
			counter++;
			if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
					coordinates -= deltas;
					counter++;
					if (ImSpielfeld(coordinates, m_spielfeld) && (m_spielfeld.getPosition(coordinates)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {
							/*coordinates -= deltas;*/
							counter++;
						}
					}
				}
			}
		}
	}
	coordinates = save;
	if (counter == 3) {
		m_spielfeld.getPosition(coordinates)->setZähler(counter);
		return true;
	}
	else if (max_counter < counter) {
		m_spielfeld.getPosition(coordinates)->setZähler(counter);
		max_counter = counter;
		jetztDa = m_spielfeld.getPosition(coordinates);
		return false;
	}
	return false;
}

bool Regelwerk::ImSpielfeld(Coord coordinates, Spielfeld& m_spielfeld)
{
	Coord size = m_spielfeld.getSize();
	if (coordinates.zeile < size.zeile && coordinates.zeile >= 0 && coordinates.spalte < size.spalte && coordinates.spalte >= 0){
		return true;
	}
	else
	{
		return false;
	}
}

