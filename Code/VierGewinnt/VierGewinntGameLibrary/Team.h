#pragma once
#include <string>
#include <vector>
#include <memory>

class Spielsteine;

class Team
{
public:
	Team(std::string name, char symbol);
	~Team();

	std::string getName() const;
	char getSymbol() const;



protected:
	const std::string m_name;
	const char m_symbol;
};

 