#pragma once
#include "Vector.h"
#include "Edificio.h"

class Disparo : public Objeto
{
protected:
	float radio;
	unsigned int da�o;
	Edificio* destino;
	Vector velocidad;
	int velocidad_max, salpicadura;
	Edificio** lista;
	//vector aceleracion; lo omitimos por ahora
public:
	Disparo(Vector posicion, Edificio* destino,unsigned int da�o, unsigned int salpicadura, Edificio** lista );
	//Introduces la posicion del disparo, aquien disparar, el da�o y la salpicadura
	virtual ~Disparo(void);

	void Dibuja(void);
	bool Mueve(void); //devuelve un 1 en el momento que llega al destino
	bool Timer_disparo (float t);
	bool setVelocidad(Vector velocidad){return true;}

	//amigo de la clase interacci�n para que interaccion
	//pueda usar las cosas de disparo
	friend class Interaccion;
};