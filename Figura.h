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
		this->y= y;
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

	int getNumeroPuntos() { return puntos.size(); }

	vector<Punto*> getPuntos() {
		return puntos;
	}

	int getX() { return this->x; }
	int getY() { return this->y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};

