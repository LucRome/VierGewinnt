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

	void getName() const;
	void getSymbol() const;



protected:
	const std::string m_name;
	const char symbol;
};

 