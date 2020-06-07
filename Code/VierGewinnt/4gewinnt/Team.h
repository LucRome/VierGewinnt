#pragma once
#include <iostream>
#include <string.h>
#include <memory>

class Team
{
public:
	Team(std::string Name);
	~Team();
	std::string getName();
	char getSymbol();
private:
	std::string m_Name;
	char m_symbol;
};

