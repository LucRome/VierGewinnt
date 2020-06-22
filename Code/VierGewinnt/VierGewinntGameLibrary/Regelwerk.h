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
	static std::shared_ptr<Spielsteine> waagerechtCheck(Spielfeld& spielfeld, Team& team); //meinStein -> Beispielstein f�r den Verwendeten?
	static std::shared_ptr<Spielsteine> senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);  //Eher �ber �bergabe des Teams?
	static std::shared_ptr<Spielsteine> diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);
	bool ImSpielfeld(int Umgebung1, int Umgebung2);
};