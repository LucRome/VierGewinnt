#pragma once
#include <string>
#include <iostream>
#include <memory>

class Spielsteine;

class ConsolePrinter
{
public: 
	static void printField();
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