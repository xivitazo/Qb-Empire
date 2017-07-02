#pragma once
#include "Mundo.h"
#include "Menus.h"

class Coordinador
{
protected:
	enum Estado{INICIO, OPCIONES, JUEGO, GAME_OVER, YOU_WIN};
	Estado estado;
	Mundo mundo;

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

