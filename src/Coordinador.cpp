#include "Coordinador.h"

int Coordinador :: pos = 0;
bool Coordinador :: flag1=0;
bool Coordinador :: flag2=0;
bool Coordinador :: flag3=0;
bool Coordinador :: flag4=0;
bool Coordinador :: flag5=0;
bool Coordinador :: flag6=0;
unsigned int Coordinador :: flag_musica=2;

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

	if(estado==INICIO)   Menus :: inicio();
	else if(estado == OPCIONES)
	{
		Menus :: opciones();

		if(flag_musica%3 == 0)
		{
			playMusica("sonidos/Two Steps from Hell   Heart of Courage.mp3", true);
			flag_musica++;
		}
		else if(flag_musica%3 == 2)		stopMusica();
	}
	else if(estado == JUEGO )
	{
		Menus :: superior(mundo);
		if(flag1)	Menus :: construccion (mundo);
		if(flag2)	Menus :: seleccion (AYUNTAMIENTO, mundo);
		if(flag3)	Menus :: seleccion (F_ORO, mundo);
		if(flag4)	Menus :: seleccion (CUARTEL, mundo);
		if(flag5)	Menus :: seleccion (F_HIERRO, mundo);
		if(flag6)	Menus :: seleccion (F_COMIDA, mundo);
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
		Menus :: game_over ();
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
			//retroceso (DEL)
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
			//No s� c�mo destruir el mundo

			Inicializa();
		}
		else if (key == 27)	exit(0);
		break;
	case YOU_WIN:	
		if(key == 'Q' || key=='q')  {
			estado=INICIO;
			//No s� c�mo destruir el mundo

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

int Coordinador :: Mouse (int names[], unsigned int hits)
{
	bool flag=false;
	for (unsigned int i=0; i<hits; i++)	
	{
		if(names[i]==100)
		{
			flag=true;
		}
	}

	unsigned int j=0;
	while(j<hits && flag==true)
	{
		switch(names[j])
		{
		case 21:	
			cout<<"AYUNTAMIENTO"<<endl;
			if(flag2)	flag2=false;
			else		flag2=true;
			flag1=false;
			flag3=false;
			flag4=false;
			flag5=false;
			flag6=false;
			break;
		case 22:
			cout<<"FABRICA DE ORO"<<endl;
			if(flag3)	flag3=false;
			else		flag3=true;
			flag1=false;
			flag2=false;
			flag4=false;
			flag5=false;
			flag6=false;
			break;
		}
		mundo.Mouse(names[j]);
		j++;
	}
	return true;
}