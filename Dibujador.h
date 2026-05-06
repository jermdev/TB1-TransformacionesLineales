#pragma once
#include "Figura.h"
#include "Punto.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace System::Drawing;
using namespace System;

class Dibujador {
public:
    void DibujarFigura(Graphics^ g, Figura* figura) {
        auto puntosLista = figura->getPuntos();

        // Necesitamos al menos 2 puntos (para cerrar polígono mínimo 3)
        if (puntosLista.size() < 2) return;

        size_t n = puntosLista.size();

        // Copiar puntos en double (seguro si getX/getY devuelven int o double)
        std::vector<std::pair<double, double>> pts;
        pts.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            double x = static_cast<double>(puntosLista[i]->getX());
            double y = static_cast<double>(puntosLista[i]->getY());
            pts.emplace_back(x, y);
        }

        // Calcular centroid (punto de referencia)
        double cx = 0.0, cy = 0.0;
        for (auto &p : pts) { cx += p.first; cy += p.second; }
        cx /= static_cast<double>(n);
        cy /= static_cast<double>(n);

        // Convertir a coordenadas polares (ángulo, radio) respecto al centroid
        struct Polar { double ang; double r; };
        std::vector<Polar> polar;
        polar.resize(n);
        for (size_t i = 0; i < n; ++i) {
            double dx = pts[i].first - cx;
            double dy = pts[i].second - cy;
            double ang = std::atan2(dy, dx); // [-pi, pi]
            double r = std::hypot(dx, dy);
            polar[i] = { ang, r };
        }

        // Crear índices y ordenar por ángulo (si ángulo igual, por radio)
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (polar[a].ang == polar[b].ang) return polar[a].r < polar[b].r;
            return polar[a].ang < polar[b].ang;
        });

        // Convertir a PointF aplicando offset de la figura
        cli::array<PointF>^ poly = gcnew cli::array<PointF>(static_cast<int>(n));
        double offsetX = static_cast<double>(figura->getX());
        double offsetY = static_cast<double>(figura->getY());
        for (size_t i = 0; i < n; ++i) {
            int id = idx[i];
            float x = static_cast<float>(pts[id].first + offsetX);
            float y = static_cast<float>(pts[id].second + offsetY);
            poly[static_cast<int>(i)] = PointF(x, y);
        }

        // Dibujar polígono cerrado
        Pen^ pen = gcnew Pen(Color::DarkRed, 2.0f);
        g->DrawPolygon(pen, poly);
        delete pen;
    }
};