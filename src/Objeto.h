#pragma once
#include <cstdlib>
#include "Vector.h"
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
	Type tipo;
	Luchadores especifico;
	//Estableces el tipo de clase edificio tal y como se establece en Lista_de.h
public:
	//constructor con altura y visibilidad por defecto a 0
//	Objeto(float a=0,bool v=0);
	Objeto( float _altura=0, Color _color=0, Planta _planta=NO_GEOMETRIA , Vector dimension=0, bool _visible=0 );

	virtual ~Objeto(void);
	virtual void Dibuja(Color equipo=0);
	virtual void Timer (float t);
	Vector getPosicion();
	void setPosicion(int x, int y);
	virtual bool setVelocidad (Vector velocidad){return false;}

	friend class Interaccion;
};

