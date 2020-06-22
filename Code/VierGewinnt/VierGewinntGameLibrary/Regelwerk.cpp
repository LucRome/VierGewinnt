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


std::shared_ptr<Spielsteine> Regelwerk::waagerechtCheck(Spielfeld& spielfeld, Team& team)
{
	int zähler = 0;	//keine Umlaute!!!
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = m_Spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 1, 0).m_counter == 3)
			{
				jetztDa = Umgebung(i, j, 1, 0, team);
				return jetztDa;
			}
		}
	}
	return 0;
}

std::shared_ptr<Spielsteine> Regelwerk::senkrechtCheck(Spielfeld& spielfeld, Team& team)
{
	int zähler = 0;
	int max_zähler = 0;
	int size = m_Spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, 0, +1).m_counter == 3)
			{
				jetztDa = Umgebung(i, j, 0, 1, team);
				return jetztDa;
			}
		}
	}
	return 0;
}

std::shared_ptr<Spielsteine> Regelwerk::diagonalCheck(Spielfeld& spielfeld, Team& team)
{
	int zähler = 0;
	int max_zähler = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, +1, +1).m_counter == 3)
			{
				jetztDa = Umgebung(i, j, -1, 1, team);
				return jetztDa;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Umgebung(i, j, -1, -1).m_counter == 3)
			{
				jetztDa = Umgebung(i, j, -1, -1, team);
				return jetztDa;
			}
		}
	}

	return 0;
}


int Umgebung(x, y, zähler1, zähler2, Spielfeld& spielfeld, Team& team)
{
	int Zähler;
	int j = x;
	int i = y;
	int Umgebung1 = zähler1;
	int Umgebung2 = zähler2;
	if (ImSpielfeld(Umgebung1, Umgebung2))
	{
		if ((team->getSymbol()) == (m_Spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
			Umgebung1 += Umgebung1;
			Umgebung2 += Umgebung2;
			zähler++;
			if (ImSpielfeld(Umgebung1, Umgebung2))
			{
				if ((team->getSymbol()) == (m_Spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
					Umgebung1 += Umgebung1;
					Umgebung2 += Umgebung2;
					zähler++;
					if (ImSpielfeld(Umgebung1, Umgebung2))
					{
						if ((team->getSymbol()) == (m_Spielfeld.getPosition(j + Umgebung1, i + Umgebung2))->getSymbol()) {
							Umgebung1 += Umgebung1;
							Umgebung2 += Umgebung2;
							zähler++;
						}
					}
				}
			}
		}
	}
	if (zähler == 3) {
		m_Spielfeld.getPosition(j, i)->setZähler(zähler);
		return m_Spielfeld.getPosition(j, i);
	}
	else if (ImSpielfeld(Umgebung1, Umgebung2))
	{
		if ((team->getSymbol()) == (m_Spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
			Umgebung1 += Umgebung1;
			Umgebung2 += Umgebung2;
			zähler++;
			if (ImSpielfeld(Umgebung1, Umgebung2))
			{
				if ((team->getSymbol()) == (m_Spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
					Umgebung1 += Umgebung1;
					Umgebung2 += Umgebung2;
					zähler++;
					if (ImSpielfeld(Umgebung1, Umgebung2))
					{
						if ((team->getSymbol()) == (m_Spielfeld.getPosition(j - Umgebung1, i - Umgebung2))->getSymbol()) {
							Umgebung1 += Umgebung1;
							Umgebung2 += Umgebung2;
							zähler++;
						}
					}
				}
			}
		}
	}
	if (zähler == 3) {
		m_Spielfeld.getPosition(j, i)->setZähler(zähler);
		return m_Spielfeld.getPosition(j, i);
	}
	else if (max_zähler < zähler) {
		m_Spielfeld.getPosition(j, i)->setZähler(zähler);
		max_zähler = zähler;
		jetztDa = m_Spielfeld.getPosition(j, i);
		return 0;
	}
}

bool ImSpielfeld(int Umgebung1, int Umgebung2)
{
	if (Spielfeld.weight + (i + Umgebung1) >= 0 && Spielfeld.weight > (i + Umgebung1) && Spielfeld.high+(j+Umgebung2)>=0 && Spielfeld.high>(j+Umgebung))           
	{
		return true;
	}
	else
	{
		return false;
	}
}