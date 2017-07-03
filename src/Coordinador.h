#pragma once
#include "Mundo.h"
#include "Menus.h"

class Coordinador
{
protected:
	enum Estado{INICIO, OPCIONES, JUEGO, GAME_OVER, YOU_WIN};
	Estado estado;
	Mundo mundo;
	static int pos;
	static bool flag1, flag2, flag3, flag4, flag5, flag6;
	static unsigned int flag_musica;

public:
	Coordinador(void);
	virtual ~Coordinador(void);

	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Timer(float t);
	void Dibuja();
	void Inicializa ();
	void Raton (int button, int state, Vector pos);
};

