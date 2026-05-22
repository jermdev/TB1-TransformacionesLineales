#pragma once
#include "Punto.h"
#include <vector>

using namespace std;

class Figura {
private:
	int x, y;
	vector<Punto*> puntos;
public:

	Figura(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Figura(int x, int y, vector<Punto*> ls) {
		this->x = x;
		this->y = y;
		this->puntos = ls;
	}

	~Figura() {
		for (auto p : puntos) {
			delete p;
		}
	}

	void agregarPunto(Punto* p) {
		puntos.push_back(p);
	}

	void limpiarPuntos() { puntos.clear(); }

	int getNumeroPuntos() { return static_cast<int>(puntos.size()); }

	vector<Punto*> getPuntos() {
		return puntos;
	}

	int getX() { return this->x; }
	int getY() { return this->y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	Figura* clonarFigura() {
		Figura* cloneFigura = new Figura(x, y);

		for (size_t i = 0; i < puntos.size(); i++) {
			Punto* nuevo = new Punto(puntos[i]->getX(), puntos[i]->getY());
			cloneFigura->agregarPunto(nuevo);
		}

		return cloneFigura;
	}
};