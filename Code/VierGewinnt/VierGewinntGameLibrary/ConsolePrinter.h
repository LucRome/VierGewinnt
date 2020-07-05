#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Spielfeld.h"
#include "Spielsteine.h"
//#include "pch.h"

class ConsolePrinter
{
public: 
	static void printField(const Spielfeld& spielfeld);
	static void printMessage(const std::string message);
	template<typename T> static T askValue(const std::string varName);
};

template<typename T>
inline T ConsolePrinter::askValue(const std::string varName)
{
	T value;
	std::cout << varName << " : ";
	std::cin >> value;

	return value;
}