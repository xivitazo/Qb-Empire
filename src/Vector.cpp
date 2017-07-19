#include "vector.h"


Vector::Vector(float x, float y):vx(x), vy(y)
{
}

Vector::~Vector(void)
{
}

Vector Vector :: operator - (Vector &v)
{
	Vector aux;
	aux.vx =vx - v.vx;
	aux.vy =vy - v.vy;
	return aux;
}

Vector Vector:: operator + (Vector &v)
{
	Vector aux;
	aux.vx =vx + v.vx;
	aux.vy =vy + v.vy;
	return aux;
}

float Vector:: operator * (Vector &v)
{
	return vx*v.vx+vy*v.vy;
}

Vector Vector :: operator * (float n)
{
	Vector aux;
	aux.vx =vx *n;
	aux.vy =vy *n;
	return aux;
}

Vector Vector :: operator / (float n)
{
	Vector aux;
	aux.vx =vx /n;
	aux.vy =vy /n;
	return aux;
}

float Vector::modulo()
{
	return (float)sqrt(vx*vx+vy*vy);
}

float Vector::argumento()
{
	return (float)atan(vy/vx);
}

Vector Vector:: unitario ()
{
	Vector u (vx,vy);
	return u/modulo();

}
void Vector :: setValor(float x, float y)
{
	vx=x;
	vy=y;
}

Vector Vector :: perpendicular()
{
	Vector aux;
	aux.vx = vy;
	aux.vy= -vx;
	return aux;
}
bool Vector :: operator == (Vector &v)
{
	if(abs(vx-v.vx)<=0.1f && abs(vy-v.vy)<=0.1f)
		return true;
	return false;
}
bool Vector :: operator == (float x)
{
	if(abs(modulo()-x)<=0.1f)
		return true;
	return false;
}

bool Vector :: operator != (Vector &v)
{
	if(abs(vx-v.vx)<=0.1f && abs(vy-v.vy)<=0.1f)
		return false;
	return true;
}
bool Vector :: operator < (float numero)
{
	return modulo()<numero;
}
bool Vector :: operator > (float numero)
{
	return modulo()>numero;
}