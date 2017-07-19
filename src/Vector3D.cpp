#include "Vector3D.h"


Vector3D::Vector3D(void)
{
}


Vector3D::~Vector3D(void)
{
}
Vector3D::Vector3D(float x, float y, float z):vx(x), vy(y), vz(z)
{
}

Vector3D Vector3D :: operator - (Vector3D &v)
{
	Vector3D aux;
	aux.vx =vx - v.vx;
	aux.vy =vy - v.vy;
	aux.vz =vz - v.vz;
	return aux;
}

Vector3D Vector3D :: operator + (Vector3D &v)
{
	Vector3D aux;
	aux.vx =vx + v.vx;
	aux.vy =vy + v.vy;
	aux.vz =vz + v.vz;
	return aux;
}

float Vector3D:: operator * (Vector3D &v)
{
	return vx*v.vx+vy*v.vy+vz*v.vz;
}

Vector3D Vector3D :: operator * (float n)
{
	Vector3D aux;
	aux.vx =vx *n;
	aux.vy =vy *n;
	aux.vz =vz *n;
	return aux;
}

Vector3D Vector3D :: operator / (float n)
{
	Vector3D aux;
	aux.vx =vx /n;
	aux.vy =vy /n;
	aux.vz =vz /n;
	return aux;
}

float Vector3D :: modulo()
{
	return (float)sqrt(vx*vx+vy*vy+vz*vz);
}

Vector3D Vector3D :: unitario ()
{
	Vector3D u (vx,vy,vz);
	return u/modulo();

}
void Vector3D :: setValor(float x, float y, float z)
{
	vx=x;
	vy=y;
	vz=z;
}
bool Vector3D :: operator == (Vector3D &v)
{
	if(abs(vx-v.vx)<=0.3f && abs(vy-v.vy)<=0.3f && abs(vz-v.vz)<=0.3f)
		return true;
	return false;
}
bool Vector3D :: operator != (Vector3D &v)
{
	if(abs(vx-v.vx)<=0.3f && abs(vy-v.vy)<=0.3f && abs(vz-v.vz)<=0.3f)
		return false;
	return true;
}

bool Vector3D :: operator = (Vector3D &i)
{
	vx=i.vx;
	vy=i.vy;
	vz=i.vz;
	return 1;
}

Vector3D Vector3D :: operator ^ (Vector3D &v)
{
	Vector3D aux;
	aux.vx=v.vz*vy-vz*v.vy;
	aux.vy=vz*v.vx-vx*v.vz;
	aux.vz=vx*v.vy-vy*v.vx;
	return aux;
}