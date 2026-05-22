#pragma once
#include "Trasformacion.h"
#include <vector>

class Homotecia : public Trasformacion {
private:
    double factor;
    int tipo;

public:
    Homotecia(Figura* figuraActual, double factorEscala, int tipoHomotecia)
        : Trasformacion(figuraActual) {
        this->factor = factorEscala;
        this->tipo = tipoHomotecia;
    }

    ~Homotecia() {}

    void setFactor(double nuevoFactor) { this->factor = nuevoFactor; }
    double getFactor() { return this->factor; }
    void setTipo(int nuevoTipo) { this->tipo = nuevoTipo; }
    int getTipo() { return this->tipo; }

    void trasformacion() override {
        Figura* figuraObjetivo = getFigura();
        if (figuraObjetivo == nullptr) return;

        std::vector<Punto*> puntos = figuraObjetivo->getPuntos();

        for (size_t i = 0; i < puntos.size(); i++) {
            double x = puntos[i]->getX();
            double y = puntos[i]->getY();

            if (this->tipo == 0) {
                puntos[i]->setX(x * factor);
                puntos[i]->setY(y * factor);
            }
            else if (this->tipo == 1) {
                puntos[i]->setX(x * factor);
            }
            else if (this->tipo == 2) {
                puntos[i]->setY(y * factor);
            }
        }
    }
};