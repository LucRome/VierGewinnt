#include "pch.h"
#include "Regelwerk.h"
#include "Spielfeld.h"
#include "Spielsteine.h"


Regelwerk::Regelwerk() {

}

Regelwerk::~Regelwerk()
{
}

std::shared_ptr<Spielsteine> Regelwerk::waagerechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
{
	int zähler = 0;	//keine Umlaute!!!
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j - 1, i))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j - 2, i))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j - 3, i))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j + 1, i))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j + 2, i))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j + 3, i))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if (max_zähler < zähler) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				max_zähler = zähler;
				jetztDa = spielfeld.getPosition(j, i);
			}
		}
	}
	return jetztDa;
}

std::shared_ptr<Spielsteine> Regelwerk::senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
{
	int zähler = 0;
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i-3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j, i+3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if (max_zähler < zähler) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				max_zähler = zähler;
				jetztDa = spielfeld.getPosition(j, i);
			}
		}
	}
	return jetztDa;
}

std::shared_ptr<Spielsteine> Regelwerk::diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein)
{
	int zähler = 0;
	int max_zähler = 0;
	std::shared_ptr<Spielsteine> jetztDa;
	int size = spielfeld.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i - 1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i - 2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i - 3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i + 1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i + 2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i + 3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if (max_zähler < zähler) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				max_zähler = zähler;
				jetztDa = spielfeld.getPosition(j, i);
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+1, i - 1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+2, i - 2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j+3, i - 3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-1, i + 1))->getSymbol()) {
				zähler++;
				if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-2, i + 2))->getSymbol()) {
					zähler++;
					if ((meinStein->getSymbol()) == (spielfeld.getPosition(j-3, i + 3))->getSymbol()) {
						zähler++;
					}
				}
			}
			if (zähler == 3) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				return spielfeld.getPosition(j, i);
			}
			else if (max_zähler < zähler) {
				spielfeld.getPosition(j, i)->setZähler(zähler);
				max_zähler = zähler;
				jetztDa = spielfeld.getPosition(j, i);
			}
		}
	}
	return jetztDa;
	
}
