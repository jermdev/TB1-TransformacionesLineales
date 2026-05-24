#pragma once
#include "Trasformacion.h"
#include <vector>
#include <cmath>

class Reflexion : public Trasformacion {
private:
    int tipoEje; 
    double m;      
    double b;       

public:
    
    Reflexion(Figura* figuraActual, int tipo) 
        : Trasformacion(figuraActual), tipoEje(tipo), m(0.0), b(0.0) {}

    
    Reflexion(Figura* figuraActual, double pendiente, double ordenadaOrigenEnPixeles)
        : Trasformacion(figuraActual), tipoEje(2), m(pendiente), b(ordenadaOrigenEnPixeles) {}

    void trasformacion() override {
        Figura* figuraObjetivo = getFigura();
        if (figuraObjetivo == nullptr) return;

        std::vector<Punto*> puntos = figuraObjetivo->getPuntos();
        for (size_t i = 0; i < puntos.size(); i++) {
            double x = puntos[i]->getX();
            double y = puntos[i]->getY();

            if (this->tipoEje == 0) { 
                puntos[i]->setY(y * -1);
            }
            else if (this->tipoEje == 1) { 
                puntos[i]->setX(x * -1);
            }
            else if (this->tipoEje == 2) { 
                
                
                double A = m;
                double B = -1.0;
                double C = b;

               double denom = A * A + B * B;

                double dist =
                    (A * x + B * y + C) / denom;

                double xr = x - 2.0 * A * dist;
                double yr = y - 2.0 * B * dist;

                puntos[i]->setX(xr);
                puntos[i]->setY(yr);
            }
        }
    }
};