#pragma once
#include "Vector.h"
#include "Objeto.h"

class Disparo : public Objeto
{
protected:
	float radio;
	unsigned int da�o;
	Vector destino;
	Vector velocidad;
	float velocidad_z, z, z0;
	int velocidad_max, salpicadura;
	//vector aceleracion; lo omitimos por ahora
	float tiempo;
public:
	Disparo(Vector posicion, Vector destino,unsigned int da�o, unsigned int salpicadura);
	//Introduces la posicion del disparo, aquien disparar, el da�o y la salpicadura
	virtual ~Disparo(void);

	void Dibuja(void);
	bool Mueve(void); //devuelve un 1 en el momento que llega al destino
	bool Timer_disparo (float t);
	bool setVelocidad(Vector velocidad){return true;}
	int getSalpicadura(){return salpicadura;}
	bool explosion();

	//amigo de la clase interacci�n para que interaccion
	//pueda usar las cosas de disparo
	friend class Interaccion;
};