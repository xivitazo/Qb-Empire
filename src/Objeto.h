#pragma once
#include <cstdlib>
#include "Vector.h"
#include "Color.h"

class Objeto
{
protected:
	Color color;	//todos los objetos tienen un color blanco inicial
	bool visible;
	Vector posicion;
	Vector superificie;
	float altura;
public:
	//constructor con altura y visibilidad por defecto a 0
//	Objeto(float a=0,bool v=0);
	Objeto( float a=0, bool v=0, unsigned int red=0, unsigned int green=0, unsigned int blue=0 );

	virtual ~Objeto(void);
	virtual void Dibuja(Color equipo=0);
	virtual void Timer (float t);
	Vector getPoscion();
	void setPosicion(int x, int y);

	friend class Interaccion;
};

