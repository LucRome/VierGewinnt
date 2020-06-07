#include "Spielfeld.h"

std::weak_ptr<Spielsteine> Spielfeld::getPosition(int x, int y) const
{

    return m_spielfeld[x][y];
}
