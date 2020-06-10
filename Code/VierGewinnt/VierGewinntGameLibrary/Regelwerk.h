#pragma once
#include <memory>

class Spielfeld;
class Spielsteine;

class Regelwerk
{
public:
	Regelwerk();
	~Regelwerk();
	std::shared_ptr<Spielsteine> waagerechtCheck(Spielfeld & spielfeld, std::shared_ptr<Spielsteine> meinStein); //meinStein -> Beispielstein f�r den Verwendeten?
	std::shared_ptr<Spielsteine> senkrechtCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);  //Eher �ber �bergabe des Teams?
	std::shared_ptr<Spielsteine> diagonalCheck(Spielfeld& spielfeld, std::shared_ptr<Spielsteine> meinStein);
};