#pragma once
#include <cmath>

class Vector3D
{
public:
	float vx,vy,vz;
	Vector3D(void);
	Vector3D (float x, float y, float z);
	~Vector3D(void);
	float modulo();
	float argumento();	// argumento del vector
	void setValor(float x, float y, float z);
	Vector3D operator - (Vector3D &);
	Vector3D operator + (Vector3D &);
	Vector3D operator * (float);
	Vector3D operator / (float);
	float operator * (Vector3D &);
	bool operator == (Vector3D &);
	bool operator != (Vector3D &);
	Vector3D unitario();
	Vector3D perpendicular();
};

