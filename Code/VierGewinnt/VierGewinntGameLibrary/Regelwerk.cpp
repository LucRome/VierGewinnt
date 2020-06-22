//#include "pch.h"
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
//	int z�hler = 0;	//keine Umlaute!!!
//	int max_z�hler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((team.getSymbol()) == (spielfeld.getPosition(j - 1, i))->getSymbol()) {
//				z�hler++;
//				if ((team.getSymbol()) == (spielfeld.getPosition(j - 2, i))->getSymbol()) {
//					z�hler++;
//					if ((team.getSymbol()) == (spielfeld.getPosition(j - 3, i))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((team.getSymbol()) == (spielfeld.getPosition(j + 1, i))->getSymbol()) {
//				z�hler++;
//				if ((team.getSymbol()) == (spielfeld.getPosition(j + 2, i))->getSymbol()) {
//					z�hler++;
//					if ((team.getSymbol()) == (spielfeld.getPosition(j + 3, i))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_z�hler < z�hler) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				max_z�hler = z�hler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//	return jetztDa;
//}

//std::shared_ptr<Spielsteine> Regelwerk::senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
//{
//	int z�hler = 0;
//	int max_z�hler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_z�hler < z�hler) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				max_z�hler = z�hler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//	return jetztDa;
//}

//std::shared_ptr<Spielsteine> Regelwerk::diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
//{
//	int z�hler = 0;
//	int max_z�hler = 0;
//	std::shared_ptr<Spielsteine> jetztDa;
//	int size = spielfeld.getSize();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i - 1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i - 2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i - 3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i + 1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i + 2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i + 3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_z�hler < z�hler) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				max_z�hler = z�hler;
//				jetztDa = spielfeld.getPosition(j, i);
//			}
//		}
//	}
//
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i - 1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i - 2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i - 3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i + 1))->getSymbol()) {
//				z�hler++;
//				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i + 2))->getSymbol()) {
//					z�hler++;
//					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i + 3))->getSymbol()) {
//						z�hler++;
//					}
//				}
//			}
//			if (z�hler == 3) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				return spielfeld.getPosition(j, i);
//			}
//			else if (max_z�hler < z�hler) {
//				spielfeld.getPosition(j, i)->setZ�hler(z�hler);
//				max_z�hler = z�hler;
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

bool Regelwerk::waagerechtCheck(Spielfeld& m_spielfeld, Team& team)
{
	int z�hler = 0;	//keine Umlaute!!!
	int max_z�hler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = m_spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 1, 0,m_spielfeld, team)==true)
			{
				return true;
			}
		}
	}
	return false;
}

bool Regelwerk::senkrechtCheck(Spielfeld& m_spielfeld, Team& team)
{
	int z�hler = 0;
	int max_z�hler = 0;
	int size = m_spielfeld.getSize();
	std::shared_ptr<Spielsteine> jetztDa;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 0, +1,m_spielfeld,team)==true)
			{
				return true;
			}
		}
	}
	return false;
}

bool Regelwerk::diagonalCheck(Spielfeld& m_spielfeld, Team& team)
{
	int z�hler = 0;
	int max_z�hler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	for (int i = 0; i < m_spielfeld.getSize(); i++) {
		for (int j = 0; j < m_spielfeld.getSize(); j++) {
			if (Umgebung(i, j, +1, +1, m_spielfeld, team)==true)
			{
				return true;
			}
		}
	}

	for (int i = 0; i <m_spielfeld.getSize(); i++) {
		for (int j = 0; j < m_spielfeld.getSize(); j++) {
			if (Umgebung(i, j, -1, -1, m_spielfeld, team)==true)
			{
				return true;
			}
		}
	}

	return false;
}


bool Regelwerk:: Umgebung(int x, int y,int z�hler1,int z�hler2, Spielfeld& m_spielfeld, Team& team)
{
	std::shared_ptr<Spielsteine> jetztDa;
	int Z�hler=0;
	int j = x;
	int i = y;
	int Umgebung1 = z�hler1;
	int Umgebung2 = z�hler2;
	int max_z�hler=0;
	if (ImSpielfeld(i, j, Umgebung1, Umgebung2, m_spielfeld))
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2)->getSymbol())) 
		{
			Umgebung1 += Umgebung1;
			Umgebung2 += Umgebung2;
			Z�hler++;
			if (ImSpielfeld(i,j,Umgebung1, Umgebung2, m_spielfeld))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
					Umgebung1 += Umgebung1;
					Umgebung2 += Umgebung2;
					Z�hler++;
					if (ImSpielfeld(i,j,Umgebung1, Umgebung2, m_spielfeld))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
							Umgebung1 += Umgebung1;
							Umgebung2 += Umgebung2;
							Z�hler++;
						}
					}
				}
			}
		}
	}
	if (Z�hler == 3) {
		m_spielfeld.getPosition(j, i)->setZ�hler(Z�hler);
		return true;
	}
	else if (ImSpielfeld(i,j,Umgebung1, Umgebung2, m_spielfeld))
	{
		if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
			Umgebung1 += Umgebung1;
			Umgebung2 += Umgebung2;
			Z�hler++;
			if (ImSpielfeld(i,j,Umgebung1, Umgebung2, m_spielfeld))
			{
				if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
					Umgebung1 += Umgebung1;
					Umgebung2 += Umgebung2;
					Z�hler++;
					if (ImSpielfeld(i,j,Umgebung1, Umgebung2, m_spielfeld))
					{
						if ((team.getSymbol()) == (m_spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
							Umgebung1 += Umgebung1;
							Umgebung2 += Umgebung2;
							Z�hler++;
						}
					}
				}
			}
		}
	}
	if (Z�hler == 3) {
		m_spielfeld.getPosition(j, i)->setZ�hler(Z�hler);
		return true;
	}
	else if (max_z�hler < Z�hler) {
		m_spielfeld.getPosition(j, i)->setZ�hler(Z�hler);
		max_z�hler = Z�hler;
		jetztDa = m_spielfeld.getPosition(j, i);
		return false;
	}
}

bool Regelwerk::ImSpielfeld(int i, int j, int Umgebung1, int Umgebung2, Spielfeld& m_spielfeld)
{
	if (m_spielfeld.getSize() + (i + Umgebung1) >= 0 && m_spielfeld.getSize() > (i + Umgebung1) && m_spielfeld.getSize()+(j+Umgebung2)>=0 && m_spielfeld.getSize()>(j+Umgebung2))           
	{
		return true;
	}
	else
	{
		return false;
	}
}