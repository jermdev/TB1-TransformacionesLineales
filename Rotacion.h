#pragma once
#include "Trasformacion.h"
#include <cmath>
#include <vector>

class Rotacion : public Trasformacion {
private:
    double angulo; // ángulo en grados (puede ser fraccionario)

public:
    Rotacion(Figura* figuraActual, double anguloRotacion) : Trasformacion(figuraActual) {
        this->angulo = anguloRotacion;
    }

    ~Rotacion() {}

    void setAngulo(double nuevoAngulo) {
        this->angulo = nuevoAngulo;
    }

    double getAngulo() {
        return this->angulo;
    }

    void trasformacion() override {
        Figura* figuraObjetivo = getFigura();
        if (figuraObjetivo == nullptr) return;

        const double pi = 3.14159265358979323846;
        double radianes = angulo * pi / 180.0;
        double coseno = cos(radianes);
        double seno = sin(radianes);

        std::vector<Punto*> puntosFigura = figuraObjetivo->getPuntos();

        for (size_t i = 0; i < puntosFigura.size(); i++) {
            Punto* puntoActual = puntosFigura[i];
            double posicionX = puntoActual->getX();
            double posicionY = puntoActual->getY();

            double nuevoX = posicionX * coseno - posicionY * seno;
            double nuevoY = posicionX * seno + posicionY * coseno;

            puntoActual->setX(nuevoX);
            puntoActual->setY(nuevoY);
        }
    }
};
