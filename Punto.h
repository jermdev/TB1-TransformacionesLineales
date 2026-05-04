#pragma once

class Punto {
private:
	double x, y;

public:
	Punto(double x, double y) {
		this->x = x;
		this->y = y;
	}

	~Punto() {}

	double getX() { return x; }
	double getY() { return y; }

	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
};