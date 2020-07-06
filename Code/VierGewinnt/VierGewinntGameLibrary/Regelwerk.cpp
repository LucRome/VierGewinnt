//#include "pch.h"
#include "Regelwerk.h"
#include "Spielfeld.h"
#include "Spielsteine.h"

#include <array>
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
	/*if (waagerechtCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	if (senkrechtCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	if (diagonalCheck(coordinates, m_spielfeld, team)) {
		return true;
	}
	return false;*/
	if (highestStreak(coordinates, m_spielfeld, team) == 3) {
		return true;
	}
	else {
		return false;
	}
}

int Regelwerk::highestStreak(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	int waagerecht, senkrecht, diagonal1, diagonal2;
	int max = 0;
	waagerecht = umgebungInt(coordinates, d_waagerecht, m_spielfeld, team);
	senkrecht = umgebungInt(coordinates, d_senkrecht, m_spielfeld, team);
	diagonal1 = umgebungInt(coordinates, d_diagonal1, m_spielfeld, team);
	diagonal2 = umgebungInt(coordinates, d_diagonal2, m_spielfeld, team);

	if (waagerecht > max) {
		max = waagerecht;
	}
	if (senkrecht > max) {
		max = senkrecht;
	}
	if (diagonal1 > max) {
		max = diagonal1;
	}
	if (diagonal2 > max) {
		max = diagonal2;
	}
	return max;
}

bool Regelwerk::waagerechtCheck(const Spielfeld& m_spielfeld, const Team& team)
{
	int zähler = 0;	//keine Umlaute!!!
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	Coord size = m_spielfeld.getSize();
	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (umgebungBool({ zeile, spalte }, d_waagerecht, m_spielfeld, team) == true)
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
			if (umgebungBool({ zeile, spalte }, d_senkrecht, m_spielfeld, team) == true)
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
			if (umgebungBool({ zeile, spalte }, d_diagonal1, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}

	for (int zeile = 0; zeile < size.zeile; zeile++) {
		for (int spalte = 0; spalte < size.spalte; spalte++) {
			if (umgebungBool({ zeile, spalte }, d_diagonal2, m_spielfeld, team) == true)
			{
				return true;
			}
		}
	}

	return false;
}

bool Regelwerk::waagerechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (umgebungBool(coordinates, d_waagerecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::senkrechtCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (umgebungBool(coordinates, d_senkrecht, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::diagonalCheck(const Coord coordinates, const Spielfeld& m_spielfeld, const Team& team)
{
	if (umgebungBool(coordinates, d_diagonal1, m_spielfeld, team) || umgebungBool(coordinates, d_diagonal2, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

int Regelwerk::umgebungInt(const Coord coordinates, Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	int cnt1, cnt2;
	cnt1 = countNeighbours(coordinates, deltas, m_spielfeld, team);
	deltas.spalte = -deltas.spalte;
	deltas.zeile = -deltas.zeile;
	cnt2 = countNeighbours(coordinates, deltas, m_spielfeld, team);

	if (cnt1 < cnt2) {
		return cnt2;
	}
	else {
		return cnt1;
	}
}


bool Regelwerk:: umgebungBool(const Coord coordinates, Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	std::shared_ptr<Spielsteine> jetztDa;
	int counter=0;
	int max_counter=0;
	counter = countNeighbours(coordinates, deltas, m_spielfeld, team);
	if (counter == 3) {
		m_spielfeld.getPosition(coordinates)->setZähler(counter);
		return true;
	}
	deltas.spalte = -deltas.spalte;
	deltas.zeile = -deltas.zeile;
	counter = countNeighbours(coordinates, deltas, m_spielfeld, team);
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

int Regelwerk::countNeighbours(Coord coordinates, const Coord deltas, const Spielfeld& m_spielfeld, const Team& team)
{
	int counter = 0;
	coordinates += deltas;
	/*for (int i = 0; i < winNr; i++) {
		if (ImSpielfeld(coordinates += deltas, m_spielfeld) && m_spielfeld.getPosition(coordinates) 
			&& (team.getSymbol()) == (m_spielfeld.getPosition(coordinates))->getSymbol()) {

			counter++;
			coordinates += deltas;
		}
		else {
			break;
		}
	}*/
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
	return counter;
}


