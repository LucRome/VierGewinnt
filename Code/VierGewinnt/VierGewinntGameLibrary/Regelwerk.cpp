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


bool Regelwerk::gewonnen(const Spielfeld& m_spielfeld, const Team& team)
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

bool Regelwerk::gewonnen(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
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

bool Regelwerk::waagerechtCheck(const Spielfeld& m_spielfeld, const Team& team)
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

bool Regelwerk::senkrechtCheck(const Spielfeld& m_spielfeld, const Team& team)
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

bool Regelwerk::diagonalCheck(const Spielfeld& m_spielfeld, const Team& team)
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

bool Regelwerk::waagerechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (Umgebung(coordinates, d_waagerecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::senkrechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (Umgebung(coordinates, d_senkrecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::diagonalCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (Umgebung(coordinates, d_diagonal1, m_spielfeld, team) || Umgebung(coordinates, d_diagonal2, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}


bool Regelwerk:: Umgebung(const Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	std::shared_ptr<Spielsteine> jetztDa;
	Coord moveCoordinates = coordinates;
	int counter=0;
	int max_counter=0;
	moveCoordinates += deltas;
	if (ImSpielfeld(moveCoordinates, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
		//immer prüfen ob Zielfeld noch im Spielfeld und ob Ziehlfeld != nullptr
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates)->getSymbol()))
		{
			moveCoordinates += deltas;
			counter++;
			if (ImSpielfeld(moveCoordinates, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates))->getSymbol()) {
					moveCoordinates += deltas;
					counter++;
					if (ImSpielfeld(moveCoordinates, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates))->getSymbol()) {
							/*Umgebung1 += zähler1;
							Umgebung2 += zähler2;*/
							counter++;
						}
					}
				}
			}
		}
	}
	moveCoordinates = coordinates;
	if (counter == 3) {
		m_spielfeld.getPosition(moveCoordinates)->setZähler(counter);
		return true;
	}
	else if (ImSpielfeld(moveCoordinates -= deltas, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates))->getSymbol()) {
			moveCoordinates -= deltas;
			counter++;
			if (ImSpielfeld(moveCoordinates, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates))->getSymbol()) {
					moveCoordinates -= deltas;
					counter++;
					if (ImSpielfeld(moveCoordinates, m_spielfeld) && (m_spielfeld.getPosition(moveCoordinates)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(moveCoordinates))->getSymbol()) {
							/*coordinates -= deltas;*/
							counter++;
						}
					}
				}
			}
		}
	}
	moveCoordinates = coordinates;
	if (counter == 3) {
		m_spielfeld.getPosition(moveCoordinates)->setZähler(counter);
		return true;
	}
	else if (max_counter < counter) {
		m_spielfeld.getPosition(moveCoordinates)->setZähler(counter);
		max_counter = counter;
		jetztDa = m_spielfeld.getPosition(moveCoordinates);
		return false;
	}
	return false;
}

bool Regelwerk::ImSpielfeld(const Coord coordinates, const Spielfeld& m_spielfeld)
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

