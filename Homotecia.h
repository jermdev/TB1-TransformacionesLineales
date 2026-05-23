#pragma once
#include "Trasformacion.h"
#include <vector>

class Homotecia : public Trasformacion {
private:
	double factor;
	int tipo;
	double cx;
	double cy;

public:
	
	Homotecia(Figura* figuraActual, double factorEscala, int tipoHomotecia)
		: Trasformacion(figuraActual), factor(factorEscala), tipo(tipoHomotecia), cx(0.0), cy(0.0) {}

	// 
	Homotecia(Figura* figuraActual, double factorEscala, int tipoHomotecia, double centroX, double centroY)
		: Trasformacion(figuraActual), factor(factorEscala), tipo(tipoHomotecia), cx(centroX), cy(centroY) {}

	~Homotecia() {}

	// Setters / getters
	void setFactor(double nuevoFactor) { this->factor = nuevoFactor; }
	double getFactor() const { return this->factor; }

	void setTipo(int nuevoTipo) { this->tipo = nuevoTipo; }
	int getTipo() const { return this->tipo; }

	void setCentro(double centroX, double centroY) { this->cx = centroX; this->cy = centroY; }
	void getCentro(double &outX, double &outY) const { outX = cx; outY = cy; }

	// Apply the homothety to all points of the figura
	void trasformacion() override {
		Figura* figuraObjetivo = getFigura();
		if (figuraObjetivo == nullptr) return;

		std::vector<Punto*> puntos = figuraObjetivo->getPuntos();
		for (size_t i = 0; i < puntos.size(); ++i) {
			double x = puntos[i]->getX();
			double y = puntos[i]->getY();

			// scale with respect to center (cx, cy): new = center + factor * (old - center)
			if (this->tipo == 0) { // uniform scaling both axes
				double nx = cx + factor * (x - cx);
				double ny = -cy + factor * (y + cy);
				puntos[i]->setX(nx);
				puntos[i]->setY(ny);
			}
			else if (this->tipo == 1) { // scale X only
				double nx = cx + factor * (x - cx);
				puntos[i]->setX(nx);
			}
			else if (this->tipo == 2) { // scale Y only
				double ny = -cy + factor * (y + cy);
				puntos[i]->setY(ny);
			}
		}
	}
};