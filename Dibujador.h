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

	void DibujarProyecciones(Graphics^ g,
		Figura* original,
		Figura* actual,
		double escala,
		float centroXH,
		float centroYH) {
		auto puntosActual = actual->getPuntos();
		auto puntosOriginal = original->getPuntos();
		if (puntosActual.size() < 2 || puntosOriginal.size() < 2) return;

		float cx = (centroXH == 0)? (float)actual->getX() : centroXH;
		float cy = (centroYH == 0)? (float)actual->getY() : centroYH;

		Pen^ penProyeccion = gcnew Pen(Color::LimeGreen, 1.0f);
		penProyeccion->DashStyle = DashStyle::Dot;

		for (size_t i = 0; i < puntosActual.size(); ++i) {

			// Punto ORIGINAL
			float ox =
				(float)(puntosOriginal[i]->getX() * escala +
					original->getX());

			float oy =
				(float)(puntosOriginal[i]->getY() * escala +
					original->getY());

			// Punto TRANSFORMADO
			float dx =
				(float)(puntosActual[i]->getX() * escala +
					actual->getX());

			float dy =
				(float)(puntosActual[i]->getY() * escala +
					actual->getY());

			// Dirección de la recta homotética
			float vx = dx - cx;
			float vy = dy - cy;

			// longitud
			float len = sqrt(vx * vx + vy * vy);

			if (len < 0.0001f)
				continue;

			// normalizar
			vx /= len;
			vy /= len;

			// extender bastante en ambos sentidos
			float extension = 5000.0f;

			// punto inicial extendido
			float startX = cx - vx * extension;
			float startY = cy - vy * extension;

			// punto final extendido
			float endX = cx + vx * extension;
			float endY = cy + vy * extension;

			// dibujar recta completa
			g->DrawLine(
				penProyeccion,
				startX,
				startY,
				endX,
				endY);
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

	void DibujarFiguraComparativa(Graphics^ g, Figura* original, Figura* actual, double escala, bool esHomotecia, float centroXH = 0, float centroYH = 0) {
		DibujarAuxiliar(g, original, Color::LightGray, escala, DashStyle::DashDot, 1);

		if (esHomotecia) {
			DibujarProyecciones(
				g,
				original,
				actual,
				escala,
				centroXH,
				centroYH);
		}

		DibujarFiguraNormal(g, actual, escala);
	}
};