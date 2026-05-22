#pragma once
#include "Figura.h"
#include "Punto.h"
#include <vector>
#include <cmath>

using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System;

class Dibujador {
public:
	Dibujador() {}
	~Dibujador() {}

	void DibujarProyecciones(Graphics^ g, Figura* actual, double escala) {
		auto puntosLista = actual->getPuntos();
		if (puntosLista.size() < 2) return;

		float cx = (float)actual->getX();
		float cy = (float)actual->getY();

		Pen^ penProyeccion = gcnew Pen(Color::LimeGreen, 1.0f);
		penProyeccion->DashStyle = DashStyle::Dot;

		for (size_t i = 0; i < puntosLista.size(); ++i) {
			float dx = (float)(puntosLista[i]->getX() * escala + cx);
			float dy = (float)(puntosLista[i]->getY() * escala + cy);
			g->DrawLine(penProyeccion, cx, cy, dx, dy);
		}
		delete penProyeccion;
	}

	void DibujarAuxiliar(Graphics^ g, Figura* fig, Color c, double escala, DashStyle style, int thickness) {
		auto puntosLista = fig->getPuntos();
		size_t n = puntosLista.size();
		if (n < 2) return;

		float offX = (float)fig->getX();
		float offY = (float)fig->getY();

		cli::array<PointF>^ poly = gcnew cli::array<PointF>(static_cast<int>(n));
		for (size_t i = 0; i < n; ++i) {
			float x = (float)(puntosLista[i]->getX() * escala + offX);
			float y = (float)(puntosLista[i]->getY() * escala + offY);
			poly[static_cast<int>(i)] = PointF(x, y);
		}

		Pen^ pen = gcnew Pen(c, (float)thickness);
		pen->DashStyle = style;
		g->DrawPolygon(pen, poly);
		delete pen;
	}

	void DibujarFiguraNormal(Graphics^ g, Figura* actual, double escala) {
		DibujarAuxiliar(g, actual, Color::DarkRed, escala, DashStyle::Solid, 2);
	}

	void DibujarFiguraComparativa(Graphics^ g, Figura* original, Figura* actual, double escala, bool esHomotecia) {
		DibujarAuxiliar(g, original, Color::LightGray, escala, DashStyle::DashDot, 1);

		if (esHomotecia) {
			DibujarProyecciones(g, actual, escala);
		}

		DibujarFiguraNormal(g, actual, escala);
	}
};