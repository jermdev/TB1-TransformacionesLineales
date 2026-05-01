#pragma once
#include "Figura.h"
class Trasformacion {
private:
	Figura* figura;
public:

	Trasformacion(Figura *figura) {
		this->figura = figura;
	}

	~Trasformacion() {}

	void setFigura(Figura* figura) { this->figura = figura; }
	Figura* getFigura() { return this->figura ; }

	virtual void trasformacion() = 0;
};

