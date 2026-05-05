#pragma once
#include "Trasformacion.h"
#include <vector>

class Reflexion : public Trasformacion {
private:
    int tipoEje;

public:
    Reflexion(Figura* figuraActual, int tipo) : Trasformacion(figuraActual) {
        this->tipoEje = tipo;
    }

    void trasformacion() override {
        Figura* figuraObjetivo = getFigura();
        if (figuraObjetivo == nullptr) return;

        std::vector<Punto*> puntos = figuraObjetivo->getPuntos();
        for (size_t i = 0; i < puntos.size(); i++) {
            if (this->tipoEje == 0) { // Eje X
                puntos[i]->setY(puntos[i]->getY() * -1);
            }
            else if (this->tipoEje == 1) { // Eje Y
                puntos[i]->setX(puntos[i]->getX() * -1);
            }
        }
    }
};