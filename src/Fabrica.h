#pragma once
#include "Edificio.h"


class Fabrica : public Edificio
{
protected:
	int produccion;
	unsigned int p_subirNivel; 
	//Precio de oro que cuesta subir de nivel;
	float tiempo;

public:
	Fabrica(Type _tipo,Vector posicion, unsigned int nivel);
	/*	Según quieres:
			tipo==oro -> Fabrica de oro
			tipo==comida -> Fabrica de comida
			tipo==Hierro -> Fabrica de hierro
			*/
	virtual ~Fabrica(void);
	//void subirNivel(int tipo=0); Creo que la has puesto duplicada
	//falta implementar el rollo de cobrar el subir de nivel
	void Dibuja(Color equipo=0);
	void Timer (float t);
	void subirNivel();
	bool poderGenerar();
	bool generar (Recursos& Almacen);
	friend class Interaccion;
	friend class Menus;
};

