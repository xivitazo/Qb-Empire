#pragma once
#include "Objeto.h"
#include "Recursos.h"


class Edificio : public Objeto
{
protected:
	unsigned int vida,vida_max;
	unsigned int limite;
	//Limite de generacion por unidad de tiempo (Cuarteles y f�bricas)
	unsigned int nombre;
	//Este es el "nombre" de cada clase
	//Ser� la posicion del vector creado en Lista_de.h


	//Hay que organizar una variable de coste de cada edificio y tal
	//habia 
	int rango;
	//Rango de ataque, si no ataca ser� -1;
	int rango_visibilidad;

public:
	Edificio(unsigned int v, unsigned int _altura, Color _color=0, Planta planta= NO_GEOMETRIA, Vector _superficie=0);
	Edificio(const Edificio* copia);
	virtual ~Edificio(void);
	void Tecla();
	void Timer (float t);
	void Dibuja(Color equipo=0);
	void casita (Vector posicion, Color tejado, Color pared, Vector dimension, int altura);
	void setTipo(Type tipo);
	bool poderGenerar ();
	//Te dice si puedes generar lo que quieras
	virtual void subirNivel();
	//Solo se usar� el tipo en la clase personaje para definir que tropa sube de nivel
	void color_vida();
	unsigned int getMax(Type tipo);
	void setNumero_Generado(Type tipo, int incremento);
	int getRango (){return rango;}
	virtual bool Atacar (Edificio** lista){return false;}
	bool generar (Edificio ** tropa, int nivel, Luchadores tipo, Vector destino){return false;}
	virtual bool generar (Recursos& almacen){return false;};


	friend class Interaccion;
	friend class Disparo;
	friend class Lista_de;
};
