#include "Coordinador.h"
static int pos=0;
static bool flag1=0, flag2=0, flag3=0, flag4=0;
static unsigned int flag_musica=2;

Coordinador::Coordinador(void)
{
	estado=INICIO;
}


Coordinador::~Coordinador(void)
{
}

void Coordinador :: Dibuja()
{
	mundo.Dibuja();
	if(estado==INICIO)
	{   
		Menus :: inicio();
	}
	else if(estado == OPCIONES)
	{
		Menus :: opciones();

		if(flag_musica%3 == 0)
		{
			playMusica("sonidos/Two Steps from Hell   Heart of Courage.mp3", true);
			flag_musica++;
		}
		else if(flag_musica%3 == 2)	stopMusica();
	}
	else if(estado == JUEGO )
	{
		Menus :: superior(mundo);
		if(flag1)
		{
			Menus :: construccion (mundo);
		}
		if(flag2)
		{
			Menus :: seleccion(AYUNTAMIENTO, mundo);
		}
		if(flag3)	
		{
			Menus :: seleccion (F_ORO, mundo);
		}
		if(flag4)
		{
			Menus :: seleccion (CUARTEL, mundo);
		}
	}
	
	//Frase aleatoria divertida 
		/*
		glPushMatrix();
			ETSIDI::setTextColor(1,1,0);
			glTranslatef(0, 0, pos);
			pos++;
			ETSIDI::setFont("fuentes/Bitwise.ttf",70);
		ETSIDI::printxy("JUGUEMOS...... ;)", 50,80);
		glPopMatrix();
		*/

	else if (estado == GAME_OVER)
	{
		/*
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
		*/
		Menus :: game_over ();
	}
	else if (estado == YOU_WIN)
	{
		Menus :: you_win();
	}
}

void Coordinador :: Timer (float t)
{
	mundo.Timer(t);
}

void Coordinador :: Tecla (unsigned char key)
{
	switch(estado)
	{
	case INICIO:
		if(key=='E' || key=='e'){
			estado=JUEGO;
			mundo.setPerspectiva(-23,-47,50,50,25,0);
		}
		if(key=='o' || key=='O'){
			estado=OPCIONES;
		}
		else if (key == 27)	exit(1);
		break;
	case OPCIONES:
		if(key=='M' || key=='m'){			
			flag_musica++;
		}
		if(key == 8){
			estado=INICIO;
		}
		//if(key=='K' || key=='k'){}
		else if (key == 27)	exit(1);
		break;
	case JUEGO:
		mundo.Tecla(key); 	
		if(key == 'Z' || key=='z')	
		{
			estado=GAME_OVER;
			mundo.setPerspectiva(112.5, -175, 50, 112.5, 37.5, 0);
		}
		if(key == 'a' || key=='A')	
		{
			estado=YOU_WIN;
			mundo.setPerspectiva(112.5, -175, 50, 112.5, 37.5, 0);
		}
		if(key == ' ')	{
			if(flag1) flag1=false;
			else flag1=true;
			flag2=false;
			flag3=false;
			flag4=false;
		}
		if(key == 'w' || key=='W')  {
			if(flag2) flag2=false;
			else flag2=true;
			flag1=false;
			flag3=false;
			flag4=false;
		}
		if(key == 'e' || key=='E')  {
			if(flag3) flag3=false;
			else flag3=true;
			flag2=false;
			flag1=false;
			flag4=false;
		}
		if(key == 'r' || key=='R'){
			if(flag4) flag4=false;
			else flag4=true;
			flag1=0;
			flag2=0;
			flag3=0;
		}
		if(key == 8) {
			//retroceso
			flag1=0;
			flag2=0;
			flag3=0;
			flag4=0;
		}
		if(key == 27)	exit(0);
		break;
	case GAME_OVER:	
		if(key == 'Q' || key=='q')  {
			estado=INICIO;
			//No sé cómo destruir el mundo

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
