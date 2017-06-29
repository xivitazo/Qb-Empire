#pragma once
#include <cmath>

class Vector
{
public:
	Vector(float x=0, float y=0);
	virtual ~Vector(void);
	float modulo();
	float argumento();	// argumento del vector
	void setValor(float x, float y);
	Vector operator - (Vector &);
	Vector operator + (Vector &);
	Vector operator - (float);
	Vector operator + (float);
	Vector operator * (float);
	Vector operator / (float);
	float operator * (Vector &);
	bool operator == (Vector &);
	bool operator != (Vector &);
	bool operator < (float numero);
	bool operator > (float numero);
	Vector unitario();
	Vector perpendicular();
	float vx, vy;
};
