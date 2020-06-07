#include "Spielfeld.h"
#include <memory>

Spielfeld::Spielfeld()
{
}

int Spielfeld::getSize() const
{
    return m_size;
}

std::shared_ptr<Spielsteine> Spielfeld::getPosition(int spalte, int zeile) const
{
    return std::make_shared<Spielsteine>(m_spielfeld[zeile][spalte]);
}
