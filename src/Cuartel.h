#pragma once
#include "Edificio.h"
#include "Personaje.h"
#include "Lista_de.h"

class Cuartel : public Edificio
{
protected:
	unsigned int limite_tropas, numero_tropas;
	unsigned int tiempo;

public:
	Cuartel(unsigned int nivel);
	virtual ~Cuartel(void);
	bool newTropa();
	//Devuelve un TRUE si se puede generar una nueva tropa 
	//Un FALSE si ya ha generado el maximo por unidad de tiempo
	void Timer (float t); //****LUIS CAMBIA T->TIEMPO******
	// no hará falta usar la t... no entiendo la variable tiempo
	bool poderGenerar ();
	void Dibuja(Color equipo=0);
	void subirNivel();

	friend class Interaccion;
};