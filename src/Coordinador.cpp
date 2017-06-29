#include "Coordinador.h"
static int pos=0;

Coordinador::Coordinador(void)
{
	estado=INICIO;
	//play("sonidos/Two Steps from Hell   Heart of Courage.mp3");
}


Coordinador::~Coordinador(void)
{
}

void Coordinador :: Dibuja()
{
	if(estado==INICIO)
	{   
		mundo.Dibuja();
		glPushMatrix();
		ETSIDI::setTextColor(1,1,0);
		glTranslatef(0, 0, 40);
		ETSIDI::setFont("fuentes/Bitwise.ttf",70);		
		ETSIDI::printxy("QB--EMPIRE", 50,80);
		glPopMatrix();
		glPushMatrix();
		ETSIDI::setTextColor(1,0,0);
		glTranslatef(0, 0, -20);
		ETSIDI::setFont("fuentes/Bitwise.ttf",30);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", 45,-5);
		glPopMatrix();
		glPushMatrix();
		ETSIDI::setTextColor(1,0,0);
		glTranslatef(0, 0, -40);
		ETSIDI::setFont("fuentes/Bitwise.ttf",30);
		ETSIDI::printxy("PULSE LA TECLA -Esc- PARA SALIR", 46,-5);
		glPopMatrix();
		
	}
	else if(estado == JUEGO )
	{
		mundo.Dibuja();
		//Menus :: superior(mundo);
		glPushMatrix();
		ETSIDI::setTextColor(1,1,0);
		glTranslatef(0, 0, pos);
		pos++;
		ETSIDI::setFont("fuentes/Bitwise.ttf",70);
		ETSIDI::printxy("JUGUEMOS...... ;)", 50,80);
		glPopMatrix();
		
	}
	else if (estado == GAME_OVER)
	{
		mundo.Dibuja();
		
		glPushMatrix();
		ETSIDI::setTextColor(1,0,0);
		glTranslatef(0, 0, 40);
		ETSIDI::setFont("fuentes/Bitwise.ttf",100);
		ETSIDI::printxy("GAME OVER", 50,-5);
		glPopMatrix();
		glPushMatrix();
		ETSIDI::setTextColor(1,0,0);
		glTranslatef(0, 0, -20);
		ETSIDI::setFont("fuentes/Bitwise.ttf",30);
		ETSIDI::printxy("PRESS -Q- TO RESTART", 70,-5);
		glPopMatrix();
		glPushMatrix();
		ETSIDI::setTextColor(1,0,0);
		glTranslatef(0, 0, -40);
		ETSIDI::setFont("fuentes/Bitwise.ttf",30);
		ETSIDI::printxy("PRESS -Esc- TO EXIT", 75,-5);
		glPopMatrix();
	}
}

void Coordinador :: Timer (float t)
{
	//if estado==PAUSA
	//congelamos el timer????? PUEDE SER BUENA IDEA. VALORAR 
	mundo.Timer(t);
}

void Coordinador :: Tecla (unsigned char key)
{
	switch(estado)
	{
	case INICIO:
		if(key=='E'){
			estado=JUEGO;
			mundo.setPerspectiva(-23,-47,50,50,25,0);
		}
		else if (key == 27)	exit(1);
		break;
	case JUEGO:
		mundo.Tecla(key); 	
		if(key == 'Z')	
		{
			estado=GAME_OVER;
			mundo.setPerspectiva(112.5, -175, 50, 112.5, 37.5, 0);
		}
		if(key == ' ')	Menus :: construccion(mundo);	 
		if(key == 'w')  Menus :: seleccion(AYUNTAMIENTO, mundo);
		if(key == 'e')  Menus :: seleccion (F_ORO, mundo);
		if(key == 27)	exit(0);
		break;
	case GAME_OVER:	
		if(key == 'Q'){
			estado=INICIO;
			Inicializa();
		}
		else if (key == 27)	exit(0);
		break;
	}
}

void Coordinador :: TeclaEspecial (unsigned char key)
{
}

void Coordinador :: Inicializa ()
{
	mundo.Inicializa();
}

void Coordinador :: Raton (int button, int state, Vector pos)
{
	mundo.Raton(button, state, pos);
}
