#pragma once
#include <memory>

class Spielfeld;
class Spielsteine;

class Regelwerk
{
	Regelwerk();
	~Regelwerk();
	std::shared_ptr<Spielsteine> waagerechtCheck(std::shared_ptr<Spielfeld> spielfeld, std::shared_ptr<Spielsteine> meinStein);
	std::shared_ptr<Spielsteine> senkrechtCheck(std::shared_ptr<Spielfeld> spielfeld, std::shared_ptr<Spielsteine> meinStein);
	std::shared_ptr<Spielsteine> diagonalCheck(std::shared_ptr<Spielfeld> spielfeld, std::shared_ptr<Spielsteine> meinStein);


};

