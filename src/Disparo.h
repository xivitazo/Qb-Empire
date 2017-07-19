#pragma once
#include "Edificio.h"
#include "Interaccion.h"

class Disparo : public Objeto
{
protected:
	float radio;
	unsigned int daño;
	Edificio* destino;
	Vector velocidad;
	int velocidad_max, salpicadura;
	Edificio** lista;
	//vector aceleracion; lo omitimos por ahora
public:
	Disparo(Vector posicion, Edificio* destino,unsigned int daño, unsigned int salpicadura, Edificio** lista );
	//Introduces la posicion del disparo, aquien disparar, el daño y la salpicadura
	virtual ~Disparo(void);

	void Dibuja(void);
	bool Mueve(void); //devuelve un 1 en el momento que llega al destino
	void Timer (float t);
	bool setVelocidad(Vector velocidad){return true;}

	//amigo de la clase interacción para que interaccion
	//pueda usar las cosas de disparo
	friend class Interaccion;
};