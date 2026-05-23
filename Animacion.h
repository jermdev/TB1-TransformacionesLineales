#pragma once
#include "Trasformacion.h"
#include "Dibujador.h"

using namespace System::Drawing;
using namespace System::Windows::Forms;

class Animacion
{
private:
    Trasformacion* trasformacionActual;
    Dibujador* dibujador;
    int pasosTotales;
    int pasoActual;
    int tipo;
    Figura* figInicial;
    Figura* figFinal;

public:
    Animacion(Trasformacion* trans, Dibujador* dib, int pasos, int tipoAnim) {
        this->trasformacionActual = trans;
        this->dibujador = dib;
        this->pasosTotales = pasos;
        this->pasoActual = 0;
        this->tipo = tipoAnim;

        if (this->tipo == 1) {
            figInicial = trans->getFigura()->clonarFigura();
            trans->trasformacion();
            figFinal = trans->getFigura()->clonarFigura();

            auto ptsAct = trans->getFigura()->getPuntos();
            auto ptsIni = figInicial->getPuntos();
            for (size_t i = 0; i < ptsAct.size(); i++) {
                ptsAct[i]->setX(ptsIni[i]->getX());
                ptsAct[i]->setY(ptsIni[i]->getY());
            }
        }
        else {
            figInicial = nullptr;
            figFinal = nullptr;
        }
    }

    ~Animacion() {
        if (figInicial) delete figInicial;
        if (figFinal) delete figFinal;
    }

    void animarPaso() {
        if (tipo == 0) {
            trasformacionActual->trasformacion();
            pasosTotales--;
        }
        else if (tipo == 1) {
            pasoActual++;
            double t = Math::Min(1.0, (double)pasoActual / (double)pasosTotales);

            auto ptsAct = trasformacionActual->getFigura()->getPuntos();
            auto ptsIni = figInicial->getPuntos();
            auto ptsFin = figFinal->getPuntos();

            for (size_t i = 0; i < ptsAct.size(); i++) {
                double nx = ptsIni[i]->getX() + (ptsFin[i]->getX() - ptsIni[i]->getX()) * t;
                double ny = ptsIni[i]->getY() + (ptsFin[i]->getY() - ptsIni[i]->getY()) * t;
                ptsAct[i]->setX(nx);
                ptsAct[i]->setY(ny);
            }
        }
    }

    int getPasosRestantes() {
        if (tipo == 0) return pasosTotales;
        return pasosTotales - pasoActual;
    }
};