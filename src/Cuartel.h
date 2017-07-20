#pragma once
//#include "Edificio.h"
#include "Personaje.h"
#include "Lista_de.h"

class Cuartel : public Edificio
{
protected:
	float segundos_tropa;
	float tiempo;

public:
	Cuartel( Vector posicion, unsigned int nivel);
	virtual ~Cuartel(void);
	//Devuelve un TRUE si se puede generar una nueva tropa 
	//Un FALSE si ya ha generado el maximo por unidad de tiempo
	void Timer (float t); //****LUIS CAMBIA T->TIEMPO******
	// no hará falta usar la t... no entiendo la variable tiempo
	bool poderGenerar ();
	void Dibuja(Color equipo=0);
	void subirNivel();
	Edificio* generar (int nivel, Luchadores tipo, Vector destino);

	friend class Interaccion;
};