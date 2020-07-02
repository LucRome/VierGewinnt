//#include "pch.h"
#include "ConsolePrinter.h"


void ConsolePrinter::printField(const Spielfeld& spielfeld)
{
	std::shared_ptr<Spielsteine> spielstein;
	Coord size = spielfeld.getSize();
	std::cout << " ";
	for (int spalteNr = 0; spalteNr < size.spalte; spalteNr++) {
		std::cout <<" "<< spalteNr;
	}
	std::cout << std::endl;
	for (int zeileNr = 0; zeileNr < size.zeile; zeileNr++) {
		std::cout << zeileNr;
		std::cout << "|";
		for (int spalteNr = 0; spalteNr < size.spalte; spalteNr++) {
			if (spielstein = spielfeld.getPosition({ zeileNr, spalteNr })) {
				std::cout << spielstein->getSymbol();
			}
			else {
				std::cout << " ";
			}
			std::cout << "|";
		}
		std::cout << std::endl;
	}
}

void ConsolePrinter::printMessage(const std::string message)
{
	std::cout << message << std::endl;
}
