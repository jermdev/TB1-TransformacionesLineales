#pragma once
#include "Trasformacion.h"
#include <cmath>
#include <vector>

class Rotacion : public Trasformacion {
private:
	double angulo;

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

		double pi = 3.14159265358979323846;
		double radianes = angulo * pi / 180.0;
		double calculoCoseno = cos(radianes);
		double calculoSeno = sin(radianes);

		std::vector<Punto*> puntosFigura = figuraObjetivo->getPuntos();

		for (int i = 0; i < puntosFigura.size(); i++) {
			Punto* puntoActual = puntosFigura[i];
			int posicionX = puntoActual->getX();
			int posicionY = puntoActual->getY();

			int nuevoX = round(posicionX * calculoCoseno - posicionY * calculoSeno);
			int nuevoY = round(posicionX * calculoSeno + posicionY * calculoCoseno);

			puntoActual->setX(nuevoX);
			puntoActual->setY(nuevoY);
		}
	}
};
