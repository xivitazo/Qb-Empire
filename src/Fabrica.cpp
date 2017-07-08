#include "Fabrica.h"
#include <iostream>
using namespace std;


Fabrica::Fabrica(Type _tipo,Vector posicion, unsigned int nivel): 
	type(_tipo),
	tiempo(0),
	Edificio(1000, 4,Color (),CUADRADO, Vector(4,4))
{
	tipo=type;
	this -> posicion = posicion;
	especifico=NINGUNO;
	switch(tipo){
	case F_ORO:		color.set(245, 208, 51); produccion=2;	break;
	case F_COMIDA:	color.set(234, 137, 154); produccion=4;	break;
	case F_HIERRO:	color.set(157, 161, 170); produccion=3;	break;
	}
	for(unsigned int n=1;n<nivel; n++)
		subirNivel();
	rango=-1;
}

Fabrica::~Fabrica(void)
{
}

void Fabrica :: subirNivel ()
{
	vida_max = vida_max*1.25f;
	vida= vida_max;
	cout<<"Altura del edificio:"<<altura<<endl;
	altura+=4;
	//Si subes de nivel la vida se regenera
	switch (tipo)
	{
	case F_COMIDA:
		produccion+=2;
		break;
	case F_HIERRO:
		produccion+=1;
		break;
	case F_ORO:
		produccion+=1;
		break;
	}
}

void Fabrica :: Timer (float t)
{
	Edificio :: Timer (t);
	tiempo+=t;
}

void Fabrica :: Dibuja (Color equipo)
{
	bool flag=false;
	Color oro(245, 208, 51),
		hierro(157, 161, 170), 
		comida(234, 137, 154);

		if(this->color==oro)
		{
			glPushName(22);
			flag=true;
		}
		if(this->color==hierro)
		{
			glPushName(23);
			flag=true;
		}
		if(this->color==comida)
		{
			glPushName(24);
			flag=true;
		}

	casita(posicion, equipo, color, superficie, altura);

	if(flag)	glPopName();
}

bool Fabrica :: generar (Recursos& almacen)
{
	if (poderGenerar())
	{
		switch (tipo)
		{
		case F_COMIDA:
			almacen.set(almacen.getComida()+produccion,almacen.getHierro(),almacen.getOro());
			break;
		case F_HIERRO:
			almacen.set(almacen.getComida(),almacen.getHierro()+produccion,almacen.getOro());
			break;
		case F_ORO:
			almacen.set(almacen.getComida(),almacen.getHierro(),almacen.getOro()+produccion);
			break;
		}
		tiempo=0;
	}
	return false;
}

bool Fabrica :: poderGenerar()
{
	if (tiempo>=3)
	{
		return true;
	}
	return false;
}
