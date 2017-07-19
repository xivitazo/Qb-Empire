#pragma once
#include <cstdlib>
#include "Vector.h"
#include "Vector3D.h"
#include "Color.h"

enum Planta {NO_GEOMETRIA, CUADRADO, REDONDO};
enum Type {NINGUNA_F, AYUNTAMIENTO, F_COMIDA, F_HIERRO, F_ORO,CUARTEL, LUCHADOR  };
enum Luchadores {NINGUNO, CABALLERO, ARQUERA, GIGANTE, SOLDADO, GUERRERO};

class Objeto
{
protected:
	Color color;	//todos los objetos tienen un color blanco inicial
	bool visible;
	Vector posicion;
	Vector superficie;
	unsigned int altura;
	Planta planta;
public:
	Objeto( float _altura=0, Color _color=0, Planta _planta=NO_GEOMETRIA , Vector dimension=0, bool _visible=0 );

	virtual ~Objeto(void);
	virtual void Dibuja(Color equipo=0);
	virtual void Timer (float t);
	Vector getPosicion();
	void setPosicion(int x, int y);
	virtual bool setVelocidad (Vector velocidad){return false;}

	friend class Interaccion;
};

