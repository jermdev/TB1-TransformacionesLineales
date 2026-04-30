#pragma once
class Punto {
private:
	int x, y;

public: 
	Punto(int x, int y) {
		this->x = x;
		this->y = y;
	}

	~Punto() {}

	int getX() { return x; }
	int getY() { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};