#include "Spielfeld.h"
#include <memory>

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

std::shared_ptr<Spielsteine> Spielfeld::getPosition(int spalte, int zeile) const
{
    return std::make_shared<Spielsteine>(m_spielfeld[zeile][spalte]);
}
