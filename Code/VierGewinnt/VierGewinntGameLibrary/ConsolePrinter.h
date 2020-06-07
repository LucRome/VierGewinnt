#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Spielfeld.h"
#include "Spielsteine.h"

class ConsolePrinter
{
public: 
	static void printField(std::shared_ptr<Spielfeld> spielfeld);
	static void printError(std::string message);
	template<typename T> static void askValue(std::string varName);
};

template<typename T>
inline void ConsolePrinter::askValue(std::string varName)
{
	T value;
	std::cout << varName << " (" << T << "): ";
	std::cin >> value;

}