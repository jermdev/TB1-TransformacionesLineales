#pragma once
#include "Trasformacion.h"
#include "Figura.h"
#include "Reflexion.h"
#include "Homotecia.h"
#include "Rotacion.h"

using namespace std;
using namespace System;

class TrasformacionService {
	Trasformacion* trasformacion;
	
	TrasformacionService(Figura figura) {
		trasformacion = nullptr;
	}

	~TrasformacionService() {
		if (trasformacion != nullptr) delete trasformacion;
	}
	void realizarTransformacion() {

		if (trasformacion != nullptr) {
			trasformacion->trasformacion();
		}
	}

	void realizarReflexion(Figura*fig,char lado) {
		
		trasformacion = new Reflexion(fig,lado);
		if (trasformacion != nullptr) {
			realizarTransformacion();
		}
		
	}
	void realizarHomotecia() {


	}
	void realizarRotacion() {


	}
	void realizarTransformacion() {


	}

	Trasformacion* getTransformacion() {
		return trasformacion;
	}

	void setTransformacion(Trasformacion*nuevaTransformacion) {
		this->trasformacion = nuevaTransformacion;
	}

};