#pragma once
#include "Trasformacion.h"
#include "Figura.h"
class Reflexion :public Trasformacion {
private:
	Figura* figura;
	char lado;

public:
	Reflexion(Figura* figura, char lado):Trasformacion(figura) {
		this->lado = lado;
	}

	void trasformacion() override {

	}
};

