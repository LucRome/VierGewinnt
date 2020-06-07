#pragma once
#include <memory>

class Spielsteine;


class Spielfeld
{
public:
	Spielfeld();
	~Spielfeld();
	bool isVoll() const;
	int getSize() const;
	std::unique_ptr<Spielsteine> getPosition(int x, int y) const;
	

protected:
	static constexpr int m_size = 4;
	std::unique_ptr<Spielsteine> m_spielfeld[m_size][m_size] = { nullptr };
};



 