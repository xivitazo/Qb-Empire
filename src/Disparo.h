#pragma once
#include "Vector.h"
#include "Edificio.h"

class Disparo : public Objeto
{
protected:
	float radio;
	unsigned int daño;
	Edificio* destino;
	Vector velocidad;
	int velocidad_max, salpicadura;
	//vector aceleracion; lo omitimos por ahora
public:
	//constructor con daño = d y radio = r;
	Disparo(Vector posicion, Edificio* destino,unsigned int daño, unsigned int salpicadura );
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