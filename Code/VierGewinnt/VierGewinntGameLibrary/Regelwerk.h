#pragma once
#include <memory>
#include "Team.h"
//#include "pch.h"
class Spielfeld;
class Spielsteine;

class Regelwerk
{
public:
	Regelwerk();
	~Regelwerk();
	/*vielleicht alle als static?*/
	static std::shared_ptr<Spielsteine> waagerechtCheck(Spielfeld& spielfeld, Team& team); //meinStein -> Beispielstein für den Verwendeten?
	static std::shared_ptr<Spielsteine> senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);  //Eher über Übergabe des Teams?
	static std::shared_ptr<Spielsteine> diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);
};