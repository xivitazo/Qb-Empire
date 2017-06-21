#pragma once
#include "Objeto.h"
enum Type {NINGUNA_F, AYUNTAMIENTO, F_COMIDA, F_HIERRO, F_ORO,CUARTEL, LUCHADOR  };
enum Luchadores {NINGUNO, CABALLERO, ARQUERA, GIGANTE, SOLDADO, GUERRERO};

class Edificio : public Objeto
{
protected:
	unsigned int vida,vida_max;
	unsigned int limite;
	//Limite de generacion por unidad de tiempo (Cuarteles y fábricas)
	unsigned int nombre;
	//Este es el "nombre" de cada clase
	//Será la posicion del vector creado en Lista_de.h


	//Hay que organizar una variable de coste de cada edificio y tal
	//habia 
	Type tipo;
	Luchadores especifico;
	//Estableces el tipo de clase edificio tal y como se establece en Lista_de.h
	int rango;
	//Rango de ataque, si no ataca será -1;
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
	bool poderGenerar (Type tipo);
	//Te dice si puedes generar lo que quieras
	virtual void subirNivel();
	//Solo se usará el tipo en la clase personaje para definir que tropa sube de nivel
	void color_vida();
	unsigned int getMax(Type tipo);
	void setNumero_Generado(Type tipo, int incremento);
	int getRango (){return rango;}
	virtual bool Atacar (Edificio** lista){return false;}
	virtual bool generar (Edificio** tropa = 0, int nivel=1, Luchadores tipo = NINGUNO){return false;}


	friend class Interaccion;
	friend class Disparo;
	friend class Lista_de;
};
