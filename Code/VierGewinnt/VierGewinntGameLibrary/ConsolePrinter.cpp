#include "pch.h"
#include "ConsolePrinter.h"


void ConsolePrinter::printField(std::shared_ptr<Spielfeld> spielfeld)
{
	std::shared_ptr<Spielsteine> spielstein;
	int size = spielfeld->getSize();
	for (int i = 0; i < size; i++) {
		std::cout <<" "<< i;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << i;
		std::cout << "|";
		for (int j = 0; j < size; j++) {
			if (spielstein = spielfeld->getPosition(j, i)) {
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
