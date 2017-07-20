#include "Coordinador.h"

int Coordinador :: pos = 0;
bool Coordinador :: flag1=0;	//Menu construccion
bool Coordinador :: flag2=0;	//Menu seleccion AYUNTAMIENTO
bool Coordinador :: flag3=0;	//Menu seleccion F_ORO
bool Coordinador :: flag4=0;	//Menu seleccion F_COMIDA
bool Coordinador :: flag5=0;	//Menu seleccion F_HIERRO
bool Coordinador :: flag6=0;	//Menu seleccion CUARTEL
bool Coordinador :: flag7=0;	//Menu seleccion LUCHADOR
bool Coordinador :: flag_jugador=0;

unsigned int Coordinador :: flag_musica=2;

Coordinador::Coordinador(void):
	cielo(0,0,102)
{
	mundo = new Mundo ();
	estado=INICIO;
	minutos_juego=0;
	for(int n=0;n<NAMESIZE;n++)
	{
		seleccion[n]=0;
	}
}

Coordinador::~Coordinador(void)
{
	delete mundo;
}

void Coordinador :: Dibuja()
{
	mundo->Dibuja();


	if(estado==INICIO)   menus.inicio();
	else if(estado == OPCIONES)
	{
		menus.opciones();

		if(flag_musica%3 == 0)
		{
			playMusica("sonidos/Two Steps from Hell   Heart of Courage.mp3", true);
			flag_musica++;
		}
		else if(flag_musica%3 == 2)		stopMusica();
	}
	else if(estado == JUEGO )
	{

		menus.superior(*mundo, minutos_juego);
		if(flag1)	menus.construccion (*mundo);
		if(flag2)	menus.seleccion (AYUNTAMIENTO, *mundo);
		if(flag3)	menus.seleccion (F_ORO, *mundo);
		if(flag6)	menus.seleccion (CUARTEL, *mundo);
		if(flag5)	menus.seleccion (F_HIERRO, *mundo);
		if(flag4)	menus.seleccion (F_COMIDA,* mundo);
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
		menus.game_over ();
	}
	else if (estado == YOU_WIN)
	{
		menus.you_win();
	}
}

void Coordinador :: Timer (float t)
{
	mundo->Timer(t);
	if(estado==JUEGO)
	{
		minutos_juego+=t/60.0F;
		cielo.set((102.0f*(minutos_juego))/(15.0f),0,(102.0f*(15.0-minutos_juego))/15.0f);
		if(minutos_juego>15)
			cielo.set(102,0,0);
	}
	else if(estado==GAME_OVER)
	{
		cielo.set(102,0,0);
		minutos_juego=0;
	}
	else if(estado==YOU_WIN)
	{
		cielo.set(0,0,102);
		minutos_juego=0;
	}
	else if(estado==INICIO)
	{
		cielo.set(0,0,102);
		minutos_juego=0;
	}
	
}

void Coordinador :: Tecla (unsigned char key)
{
	switch(estado)
	{
	case INICIO:
		if(key=='E' || key=='e'){
			estado=JUEGO;
			menus.inicializa();
			mundo->setPerspectiva(-23,-47,50,50,25,0);
		}
		if(key=='o' || key=='O'){
			estado=OPCIONES;
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
		mundo->Tecla(key); 	
		if(key == 'Z')	
		{
			estado=GAME_OVER;
			mundo->setPerspectiva(120, -200, 50, 120, 37.5, 0);
		}
		if(key=='A')	
		{
			estado=YOU_WIN;
			mundo->setPerspectiva(120, -200, 50, 120, 37.5, 0);
		}
		if(key=='S')	
		{
			mundo->jugador1.AñadirOro(100);
		}
		if(key == ' ')	{
			if(flag1) flag1=false;
			else flag1=true;
			flag2=false;
			flag3=false;
			flag4=false;
			flag5=false;
			flag6=false;
			flag7=false;

		}
		if(key == 8) {
			//retroceso (DEL)

			flag1=0;
			flag2=0;
			flag3=0;
			flag4=0;
			flag5=false;
			flag6=false;
			flag7=false;
		}
		if(key == 27)	exit(0);
		break;
	case GAME_OVER:	
		if(key == 'Q' || key=='q')  {
			estado=INICIO;
			delete mundo;
			mundo = new Mundo ();
			Inicializa();
		}
		else if (key == 27)	exit(0);
		break;
	case YOU_WIN:	
		if(key == 'Q' || key=='q')  {
			estado=INICIO;
			delete mundo;
			mundo = new Mundo ();

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
	mundo->Inicializa();
}

bool Coordinador :: Mouse (int names[], unsigned int hits, bool button)
{
//	Type nombre;
	Vector click;
	int cuadrados=0;
	unsigned int j=0;
	
	flag_jugador=false;
	for (int i=hits; i>=0; i--)	
	{
		
		if(names[i]==JUGADOR1 && button==0)
		{
			flag_jugador=true;
			seleccion[j++]=JUGADOR1;
			seleccion[j++]=names[i+1];
			switch (mundo->jugador1.getLista()[names[i+1]-100]->getTipo()){
			case AYUNTAMIENTO: 
				//cout<<"AYUNTAMIENTO"<<endl;
				if(flag2)
				{
					mundo->Mouse(AYUNTAMIENTO);
					//flag2=false;
				}
				else		flag2=true;
				flag1=false;
				flag3=false;
				flag4=false;
				flag5=false;
				flag6=false;
				flag7=false;
				break;
			case F_ORO:
				//cout<<"FABRICA DE ORO"<<endl;
				if(flag3)
				{
					mundo->Mouse(F_ORO);
					flag3=false;
				}
				else		flag3=true;
				flag1=false;
				flag2=false;
				flag4=false;
				flag5=false;
				flag6=false;
				flag7=false;
				break;
			case F_HIERRO:
				//cout<<"FABRICA DE HIERRO"<<endl;
				if(flag5)
				{
					mundo->Mouse(F_HIERRO);
					flag5=false;
				}
				else		flag5=true;
				flag1=false;
				flag2=false;
				flag4=false;
				flag3=false;
				flag6=false;
				flag7=false;
				break;
			case F_COMIDA:
				//cout<<"FABRICA DE COMIDA"<<endl;
				if(flag4)
				{
					mundo->Mouse(F_COMIDA);
					flag4=false;
				}
				else		flag4=true;
				flag1=false;
				flag2=false;
				flag3=false;
				flag5=false;
				flag6=false;
				flag7=false;
				break;
			case CUARTEL:
				//cout<<"CUARTEL"<<endl;
				if(flag6)	
				{
					mundo->Mouse(CUARTEL);
					flag6=false;
				}
				else		flag6=true;
				flag1=false;
				flag2=false;
				flag4=false;
				flag5=false;
				flag3=false;
				flag7=false;
				break;
			case LUCHADOR:
				//cout<<"LUCHADOR"<<endl;
				if(flag7)
				{
				}
				else flag7=true;
				flag1=false;
				flag2=false;
				flag3=false;
				flag4=false;
				flag5=false;
				flag6=false;
				break;
			}

			
			//nombre = mundo->jugador1.getLista()[names[i+1]-100]->getTipo();
		}
		else if(names[i]==MAPA)
		{
			click.vx += names[i+1]-100;
			click.vy += names[i+2]-100;
			cuadrados++;

		}

	}
	
	/*for (unsigned int i=0;seleccion[i]!=0;i++)
	{
		cout<<seleccion[i]<<endl;
	}*/
	click=click/cuadrados;
	if(/*flag7 &&*/ button)
	{
		for (unsigned int i=0;seleccion[i]!=0;i++)
		{
			if(seleccion[i]==JUGADOR1)
				mundo->jugador1.getLista()[seleccion[i+1]-100]->mover(click);
			
		}
	}
	//cout<<click.vx<<"\t"<<click.vy<<endl;
	
	if(flag_jugador==false)
	{
		flag1=false;
		flag2=false;
		flag3=false;
		flag4=false;
		flag5=false;
		flag6=false;
		for(unsigned int n=0;n<j;n++)
		{
			seleccion[n]=0;
		}
	}
	return true;
}

void Coordinador :: dibujaCielo()
{
	glClearColor((float)cielo.getRed()/255.0f,(float)cielo.getGreen()/255.0f,(float)cielo.getBlue()/255.0f,1);
}