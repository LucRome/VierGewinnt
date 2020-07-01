//#include "pch.h"
#include <iostream>
#include <memory>
#include <string.h>
#include "Regelwerk.h"
#include "Spielfeld.h"
#include "Spielsteine.h"
//#include "pch.h"


Regelwerk::Regelwerk() {

}

Regelwerk::~Regelwerk()
{
}

//std::shared_ptr<Spielsteine> Regelwerk::waagerechtCheck(Spielfeld& spielfeld, Team& team)
//{
//	int zähler = 0;	//keine Umlaute!!!
//	int max_zähler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((team.getSymbol()) == (spielfeld.getPosition(j - 1, i))->getSymbol()) {
//				zähler++;
//				if ((team.getSymbol()) == (spielfeld.getPosition(j - 2, i))->getSymbol()) {
//					zähler++;
//					if ((team.getSymbol()) == (spielfeld.getPosition(j - 3, i))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((team.getSymbol()) == (spielfeld.getPosition(j + 1, i))->getSymbol()) {
//				zähler++;
//				if ((team.getSymbol()) == (spielfeld.getPosition(j + 2, i))->getSymbol()) {
//					zähler++;
//					if ((team.getSymbol()) == (spielfeld.getPosition(j + 3, i))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_zähler < zähler) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				max_zähler = zähler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//	return jetztDa;
//}

//std::shared_ptr<Spielsteine> Regelwerk::senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
//{
//	int zähler = 0;
//	int max_zähler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_zähler < zähler) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				max_zähler = zähler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//	return jetztDa;
//}

//std::shared_ptr<Spielsteine> Regelwerk::diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
//{
//	int zähler = 0;
//	int max_zähler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i - 1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i - 2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i - 3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i + 1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i + 2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i + 3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_zähler < zähler) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				max_zähler = zähler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i - 1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i - 2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i - 3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i + 1))->getSymbol()) {
//				zähler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i + 2))->getSymbol()) {
//					zähler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i + 3))->getSymbol()) {
//						zähler++;
//					}
//				}
//			}
//			if (zähler == 3) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_zähler < zähler) {
//				spielfeld.getPosition(j, i)->setZähler(zähler);
//				max_zähler = zähler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//	return jetztDa;
//	
//}


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

bool Regelwerk::gewonnen(int zeile, int spalte, Spielfeld& m_spielfeld, Team& team)
{
	if (waagerechtCheck(zeile, spalte, m_spielfeld, team)) {
		return true;
	}
	if (senkrechtCheck(zeile, spalte, m_spielfeld, team)) {
		return true;
	}
	if (diagonalCheck(zeile, spalte, m_spielfeld, team)) {
		return true;
	}
	return false;
}

bool Regelwerk::waagerechtCheck(Spielfeld& m_spielfeld, Team& team)
{
	int zähler = 0;	//keine Umlaute!!!
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = m_spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 1, 0,m_spielfeld, team)==true)
			{
				std::cout << "Team"<< team.getName()  <<"hat gewonnen" << std::endl;
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
	int size = m_spielfeld.getSize();
	std::shared_ptr<Spielsteine> jetztDa;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 0, 1,m_spielfeld,team)==true)
			{
				std::cout << "Team" << team.getName() << "hat gewonnen" << std::endl;
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
	std::shared_ptr<Spielsteine> jetztDa;
	for (int i = 0; i < m_spielfeld.getSize(); i++) {
		for (int j = 0; j < m_spielfeld.getSize(); j++) {
			if (Umgebung(i, j, +1, +1, m_spielfeld, team)==true)
			{
				std::cout << "Team" << team.getName() << "hat gewonnen" << std::endl;
				return true;
			}
		}
	}

	for (int i = 0; i <m_spielfeld.getSize(); i++) {
		for (int j = 0; j < m_spielfeld.getSize(); j++) {
			if (Umgebung(i, j, -1, -1, m_spielfeld, team)==true)
			{
				std::cout << "Team" << team.getName() << "hat gewonnen" << std::endl;
				return true;
			}
		}
	}

	return false;
}

bool Regelwerk::waagerechtCheck(int zeile, int spalte, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(spalte, zeile, 1, 0, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::senkrechtCheck(int zeile, int spalte, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(spalte, zeile, 0, 1, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}
}

bool Regelwerk::diagonalCheck(int zeile, int spalte, Spielfeld& m_spielfeld, Team& team)
{
	if (Umgebung(spalte, zeile, 1, 1, m_spielfeld, team) || Umgebung(spalte, zeile, -1,-1, m_spielfeld, team)) {
		return true;
	}
	else {
		return false;
	}return false;
}


bool Regelwerk:: Umgebung(int x, int y,int zähler1,int zähler2, Spielfeld& m_spielfeld, Team& team)
{
	std::shared_ptr<Spielsteine> jetztDa;
	int Zähler=0;
	int j = x;
	int i = y;
	int Umgebung1 = zähler1;
	int Umgebung2 = zähler2;
	int max_zähler=0;
	if (ImSpielfeld(j + Umgebung1, i + Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2)))
		//immer prüfen ob Zielfeld noch im Spielfeld und ob Ziehlfeld != nullptr
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2)->getSymbol()))
		{
			Umgebung1 += zähler1;
			Umgebung2 += zähler2;
			Zähler++;
			if (ImSpielfeld(j + Umgebung1, i + Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
					Umgebung1 += zähler1;
					Umgebung2 += zähler2;
					Zähler++;
					if (ImSpielfeld(j + Umgebung1, i + Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
							Umgebung1 += zähler1;
							Umgebung2 += zähler2;
							Zähler++;
						}
					}
				}
			}
		}
	}
	Umgebung1 = zähler1;
	Umgebung2 = zähler2;
	if (Zähler == 3) {
		m_spielfeld.getPosition(j, i)->setZähler(Zähler);
		return true;
	}
	else if (ImSpielfeld(j - Umgebung1, i - Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2)))
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
			Umgebung1 += zähler1;
			Umgebung2 += zähler2;
			Zähler++;
			if (ImSpielfeld(j - Umgebung1, i - Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2)))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
					Umgebung1 += zähler1;
					Umgebung2 += zähler2;
					Zähler++;
					if (ImSpielfeld(j - Umgebung1, i - Umgebung2, m_spielfeld) && (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2)))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
							Umgebung1 += zähler1;
							Umgebung2 += zähler2;
							Zähler++;
						}
					}
				}
			}
		}
	}
	if (Zähler == 3) {
		m_spielfeld.getPosition(j, i)->setZähler(Zähler);
		return true;
	}
	else if (max_zähler < Zähler) {
		m_spielfeld.getPosition(j, i)->setZähler(Zähler);
		max_zähler = Zähler;
		jetztDa = m_spielfeld.getPosition(j, i);
		return false;
	}
	return false;
}

bool Regelwerk::ImSpielfeld(int zeile, int spalte, Spielfeld& m_spielfeld)
{
	int size = m_spielfeld.getSize();
	if (zeile < size && zeile >= 0 && spalte < size && spalte >= 0){
		return true;
	}
	else
	{
		return false;
	}
}

