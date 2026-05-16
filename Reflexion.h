#pragma once
#include "Trasformacion.h"
#include <vector>
#include <cmath>

class Reflexion : public Trasformacion {
private:
    int tipoEje;    // 0 = Eje X, 1 = Eje Y, 2 = Recta general
    double m;       // pendiente (en unidades de píxel-coordenada compatible con puntos)
    double b;       // ordenada al origen (en píxeles)

public:
    // Constructor para ejes X/Y (compatibilidad con uso anterior)
    Reflexion(Figura* figuraActual, int tipo) 
        : Trasformacion(figuraActual), tipoEje(tipo), m(0.0), b(0.0) {}

    // Constructor para recta general y = m x + b (b DEBE estar en unidades de píxel)
    Reflexion(Figura* figuraActual, double pendiente, double ordenadaOrigenEnPixeles)
        : Trasformacion(figuraActual), tipoEje(2), m(pendiente), b(ordenadaOrigenEnPixeles) {}

    void trasformacion() override {
        Figura* figuraObjetivo = getFigura();
        if (figuraObjetivo == nullptr) return;

        std::vector<Punto*> puntos = figuraObjetivo->getPuntos();
        for (size_t i = 0; i < puntos.size(); i++) {
            double x = puntos[i]->getX();
            double y = puntos[i]->getY();

            if (this->tipoEje == 0) { // Eje X: invertir Y
                puntos[i]->setY(y * -1);
            }
            else if (this->tipoEje == 1) { // Eje Y: invertir X
                puntos[i]->setX(x * -1);
            }
            else if (this->tipoEje == 2) { // Recta y = m x + b (m en pendiente, b en píxeles)
                // Ecuación general: a x + c y + d = 0
                // Para y = m x + b -> a = m, c = -1, d = b
                
                double a = m;
                double c = -1.0;
                double d = b;
                double denom = a*a + c*c;
                if (denom == 0.0) continue; // seguridad (no debería ocurrir con c = -1)

                double discriminante = (a * x + c * y + d) / denom;
                double xr = x - 2.0 * a * discriminante;
                double yr = y - 2.0 * c * discriminante;

                puntos[i]->setX(xr);
                puntos[i]->setY(yr);
            }
        }
    }
};