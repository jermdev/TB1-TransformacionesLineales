#pragma once
#include "Trasformacion.h"
#include "Dibujador.h"

using namespace System::Drawing;
using namespace System::Threading;
using namespace System::Windows::Forms;

class Animacion
{
private:
    Trasformacion* trasformacionActual;
    Dibujador* dibujador;
    int pasosTotales;
    int tiempoTotalMs;

public:

    Animacion(Trasformacion* trans, Dibujador* dib, int pasos, int tiempoMs) {
        this->trasformacionActual = trans;
        this->dibujador = dib;
        this->pasosTotales = pasos;
        this->tiempoTotalMs = tiempoMs;
    }

    ~Animacion() {}

    void Animar(Graphics^ g) {
        if (pasosTotales <= 0) return;

        // Calculamos cu�nto debe pausar el programa entre cada cuadro (frame)
        int delay = tiempoTotalMs / pasosTotales;

        for (int i = 0; i < pasosTotales; i++) {
            // 1. Aplica la transformaci�n gradual (un paso)
            trasformacionActual->trasformacion();

            // 2. Limpia el lienzo (se usa color negro seg�n tu interfaz)
            //g->Clear(Color::Black);

            // 3. Dibuja la figura en su nuevo estado
            dibujador->DibujarFigura(g, trasformacionActual->getFigura());

            // 4. Pausa la ejecuci�n para crear el intervalo de la animaci�n
            Thread::Sleep(delay);

            // 5. Permite que Windows Forms procese los gr�ficos y no marque "No responde"
            Application::DoEvents();
        }
    }

    void animarPaso() {
        if (pasosTotales <= 0) return;

        trasformacionActual->trasformacion();
        pasosTotales--;
    }

    int getPasosTotales() { return this->pasosTotales; }
};