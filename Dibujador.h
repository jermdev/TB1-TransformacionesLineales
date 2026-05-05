#pragma once
#include "Figura.h"
#include "Punto.h"
#include <cmath>

using namespace System::Drawing;
using namespace System;

class Dibujador {
public:
    void DibujarFigura(Graphics^ g, Figura* figura) {
        auto puntosLista = figura->getPuntos();
        Pen^ pen = gcnew Pen(Color::DarkRed, 2);

        if (puntosLista.size() < 2) return;

        // Convertimos a int al crear los Point, redondeando para conservar precisión visual.
        for (size_t i = 0; i < puntosLista.size() - 1; i++)
        {
            int x1 = (int)std::round(puntosLista[i]->getX() + figura->getX());
            int y1 = (int)std::round(puntosLista[i]->getY() + figura->getY());
            int x2 = (int)std::round(puntosLista[i + 1]->getX() + figura->getX());
            int y2 = (int)std::round(puntosLista[i + 1]->getY() + figura->getY());

            g->DrawLine(pen, Point(x1, y1), Point(x2, y2));
        }

        // Cierra la figura
        int lastIndex = (int)puntosLista.size() - 1;
        int xLast = (int)std::round(puntosLista[lastIndex]->getX() + figura->getX());
        int yLast = (int)std::round(puntosLista[lastIndex]->getY() + figura->getY());
        int x0 = (int)std::round(puntosLista[0]->getX() + figura->getX());
        int y0 = (int)std::round(puntosLista[0]->getY() + figura->getY());

        g->DrawLine(pen, Point(xLast, yLast), Point(x0, y0));
    }
};