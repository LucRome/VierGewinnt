#include "Spielfeld.h"
#include <memory>

Spielfeld::Spielfeld()
{
}

Spielfeld::~Spielfeld()
{
}



int Spielfeld::getSize() const
{
    return m_size;
}


setStoneMsg Spielfeld::placeStone(Team& team, int spalte)
{
    setStoneMsg msg = setStoneMsg::success;
    if (spalte < m_size) {
        if (!m_spielfeld[0][spalte]) {    //wenn = nullptr; angenommen: 0 =: oben
            int zeile = m_size - 1;
            while (m_spielfeld[zeile][spalte]) {    //"Von unten nach oben"
                zeile--;
            }
            m_spielfeld[zeile][spalte] = std::make_unique<Spielsteine>(new Spielsteine(team));
        }
        else {
            msg = setStoneMsg::rowFull;
        }
    }
    else {
        msg = setStoneMsg::outOfBounds;
    }
    return msg;
}

std::shared_ptr<Spielsteine> Spielfeld::getPosition(int spalte, int zeile) const
{
    return std::make_shared<Spielsteine>(m_spielfeld[zeile][spalte]);
}
