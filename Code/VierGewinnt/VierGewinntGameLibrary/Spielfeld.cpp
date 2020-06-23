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
    bool stillFree = false;
    int spalte = 0, zeile = 0;

    while (zeile < m_size && !stillFree) {  //sucht das Spielfeld nach und nach nach leeren Feldern ab, beendet wenn eins gefunden, oder wenn am Ende
        if (!getPosition(spalte, zeile)) {
            stillFree = true;
        }
        else {
            spalte = (spalte + 1) % m_size;
            if (spalte == 0) {
                zeile++;
            }
        }
    }


    return !stillFree;
}

int Spielfeld::getSize() const
{
    return m_size;
}


CoordAndSuccess Spielfeld::placeStone(Team& team, int spalte)
{
    CoordAndSuccess msg;
    msg.success = possiblePlacement(spalte);
    if (msg.success == setStoneMsg::success) {    //wenn = nullptr; angenommen: 0 =: oben
        int zeile = m_size - 1;
        while (m_spielfeld[zeile][spalte]) {    //"Von unten nach oben"
            zeile--;
        }
        m_spielfeld[zeile][spalte] = std::make_shared<Spielsteine>(team);
        msg.spalte = spalte;
        msg.zeile = zeile;
    }
    return msg;
}

setStoneMsg Spielfeld::possiblePlacement(int spalte)
{
    setStoneMsg msg;
    msg = setStoneMsg::success;
    if (spalte < m_size) {
        if (m_spielfeld[0][spalte]) {
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
    return m_spielfeld[zeile][spalte];
}

int Spielfeld::getLowestLevel(int spalte)
{
    for (int i = (m_size -1); i >=0; i--) { //hier austauschen gegen Zeilenanzahl
        if (m_spielfeld[i][spalte] == nullptr) {
            return i;
        }
    }
}
