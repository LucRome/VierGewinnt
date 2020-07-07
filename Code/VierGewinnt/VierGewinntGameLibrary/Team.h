#pragma once
#include <string>
#include <vector>
#include <memory>
//#include "pch.h"
class Spielsteine;

class Team
{
public:
	Team(const std::string name, const char symbol);
	~Team();

	std::string getName() const;
	char getSymbol() const;

protected:
	const std::string m_name;
	const char m_symbol;
};

 