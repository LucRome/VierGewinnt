#include "Spielfeld.h"
#include <memory>
//#include "pch.h"

Spielfeld::Spielfeld()
{
}

Spielfeld::~Spielfeld()
{
}

bool Spielfeld::isVoll() const
{
    for (int zeile = 0; zeile < m_size.zeile; zeile++) {
        for (int spalte = 0; spalte < m_size.spalte; spalte++) {
            if (!getPosition({ zeile, spalte })) {
                return false;
            }
        }
    }
    return true;
}

Coord Spielfeld::getSize() const
{
    return m_size;
}


CoordAndSuccess Spielfeld::placeStone(const Team& team, const int spalte)
{
    CoordAndSuccess msg;
    msg.success = possiblePlacement(spalte);
    if (msg.success == setStoneMsg::success) {    //wenn = nullptr; angenommen: 0 =: oben
        int zeile = m_size.zeile - 1;
        while (getPosition({ zeile, spalte })) {    //"Von unten nach oben"
            zeile--;
        }
        m_spielfeld[zeile][spalte] = std::make_shared<Spielsteine>(team);
        msg.coordinates.spalte = spalte;
        msg.coordinates.zeile = zeile;
    }
    return msg;
}

setStoneMsg Spielfeld::possiblePlacement(const int spalte) const
{
    setStoneMsg msg;
    msg = setStoneMsg::success;
    if (spalte < m_size.spalte) {
        if (m_spielfeld[0][spalte]) {
            msg = setStoneMsg::rowFull;
        }
    }
    else {
        msg = setStoneMsg::outOfBounds;
    }
    return msg;
}

std::shared_ptr<Spielsteine> Spielfeld::getPosition(const Coord coordinates) const
{
    return m_spielfeld[coordinates.zeile][coordinates.spalte];
}

int Spielfeld::getLowestLevel(const int spalte) const
{
    for (int i = (m_size.zeile - 1); i >=0; i--) { //hier austauschen gegen Zeilenanzahl
        if (!getPosition({ i, spalte })) {
            return i;
        }
    }
}

void Spielfeld::setSpielfeldfuerTests(std::array<std::array<std::shared_ptr<Spielsteine>, 6>, 5> feld)
{
    m_spielfeld = feld;
}
