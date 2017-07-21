#pragma once
#include "Mundo.h"
#include "Menus.h"

#define NAMESIZE 16384 //2^14

class Coordinador
{
protected:
	enum Estado{INICIO, OPCIONES, JUEGO, GAME_OVER, YOU_WIN};
	Estado estado;
	Mundo *mundo;
	Menus menus;
	Type construccion;
	Color cielo;
	int seleccion[NAMESIZE];
	static int pos;
	static bool flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag_jugador;
	static unsigned int flag_musica;
	float minutos_juego;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	float miro_x, miro_y, miro_z;
	float ax_ojo;
	float ay_ojo;
	float az_ojo;
	float amiro_x, amiro_y, amiro_z;


public:
	Coordinador(void);
	virtual ~Coordinador(void);

	bool Mouse (int names[], unsigned int hits, bool button);
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Timer(float t);
	void Dibuja();
	void Inicializa ();
	void dibujaCielo();
	void movimientoCamara(float t);
	void Inicializa_vista();
	void setPerspectiva(float ojo_a, float ojo_b, float ojo_c, float miro_a, float miro_b, float miro_c);
	
};

