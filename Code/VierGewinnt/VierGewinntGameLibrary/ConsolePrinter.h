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
	static void printMessage(std::string message);
	template<typename T> static T askValue(std::string varName);
};

template<typename T>
inline T ConsolePrinter::askValue(std::string varName)
{
	T value;
	std::cout << varName << " (" << T << "): ";
	std::cin >> value;

}