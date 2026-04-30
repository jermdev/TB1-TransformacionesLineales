#pragma once
#include "Figura.h"
#include "Punto.h"

using namespace System::Drawing;
using namespace System;
class Dibujador {
public:
    void DibujarFigura(Graphics^ g, Figura* figura) {
        auto puntosLista = figura->getPuntos();

        if (puntosLista.size() < 2) return;
        
 
        for (int i = 0; i < puntosLista.size() - 1; i++)
        {
            g->DrawLine(
                Pens::DarkRed,
                Point(puntosLista[i]->getX() + figura->getX(), puntosLista[i]->getY() + figura->getY()),
                Point(puntosLista[i + 1]->getX() + figura->getX(), puntosLista[i + 1]->getY() + figura->getY())
            );
        }

        g->DrawLine(
            Pens::DarkRed,
            Point(
                puntosLista[puntosLista.size() - 1]->getX() + figura->getX(),
                puntosLista[puntosLista.size() - 1]->getY() + figura->getY()
            ),
            Point(
                puntosLista[0]->getX() + figura->getX(),
                puntosLista[0]->getY() + figura->getY()
            )
        );
    }
};