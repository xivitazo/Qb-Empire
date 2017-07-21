
#include "Mundo.h"
#include <math.h>
#include "Menus.h"
#include <iostream>
#include "glut.h"

using namespace std;

GLfloat x=0, y=0, z=-0.1;

Mundo::Mundo():
	jugador1(Vector(8, 37.5),Color(0, 0, 205)), 
	jugador2 (Vector(217, 37.5),Color(179,36,40)),
	numero(0)
{
	for(int n=0; n<MAX;n++)
	{
		disparos[n]=0;
	}
}

Mundo :: ~Mundo()
{
	for(int n=0;n<numero; n++)
	{
		delete disparos[n];
	}
}

void Mundo::Dibuja()
{
	  

	//aqui es donde hay que poner el codigo de dibujo

	
	//dibujo del suelo
	//glPushName(2);
	glLoadName(MAPA);
	map.Dibuja();
	//glPopName();

	//Dibujamos ayuntamientos

	glLoadName(JUGADOR1);
	jugador1.Dibuja();
	//glPopName();

	//glLoadName(3);
	glLoadName(JUGADOR2);
	jugador2.Dibuja();	
	//glPopName();
	glLoadName(99);
	for(int n=0; n<numero; n++)
	{
		disparos[n]->Dibuja();
	}  
}

void Mundo::Timer(float t)
{
	for(int n=0; n<jugador1.getNumero();n++)
	{
		for(int i=0; i<jugador2.getNumero();i++)
			Interaccion :: rebote(*jugador1.getPosN(n),*jugador2.getPosN(i));
	}
	atacar();
	morir();
	jugador1.Timer(t);
	jugador2.Timer(t);
	
	for(int n=0; n<numero; n++)
	{
		if(disparos[n]->Timer_disparo(t))
		{
			Interaccion :: Ataque(disparos [n],jugador1.getLista());
			Interaccion :: Ataque(disparos[n],jugador2.getLista());
			delete disparos[n];
			numero--;
			for(int i=n;i<numero;i++)
			{
				disparos[i]=disparos[i+1];
			}
			disparos[numero]=0;
		}
	}

	//Para el sonido del disparo
	//ETSIDI::play("sonidos/impacto.wav");

}

void Mundo::Inicializa()
{

	map.inicializa();

}

void Mundo::Tecla(unsigned char key)
{/*
	case 'A':
	case 'a': x_ojo+=1; break;
	case 'S':
	case 's': y_ojo+=1; break;
	case 'D':
	case 'd': z_ojo+=1; break;
	case 'Z':
	case 'z': x_ojo-=1; break;
	case 'X':
	case 'x': y_ojo-=1; break;
	case 'C':
	case 'c': z_ojo-=1; break;
	case 'F':
	case 'f': miro_x+=1; break;
	case 'G':
	case 'g': miro_y+=1; break;
	case 'H':
	case 'h': miro_z+=1; break;
	case 'V':
	case 'v': miro_x-=1; break;
	case 'B':
	case 'b': miro_y-=1; break;
	case 'N':
	case 'n': miro_z-=1; break;*/
}

void Mundo:: RatonPasivo(int x, int y)
{

}

void Mundo :: atacar()
{
	numero+=jugador1.atacar(&disparos[numero], jugador2.getLista());
	numero+=jugador2.atacar(&disparos[numero], jugador1.getLista());
} 

void Mundo :: morir()
{
	int muertos;
	float dado1=lanzaDado(1.0f);
	float dado2=lanzaDado(1.0f);
	float dado3=lanzaDado(1.0f);
	muertos=jugador1.Morir();
	if(dado1>0.5)
		dado1=1;
	else
		dado1=0;
	if(dado2>0.65)
		dado2=1;
	else
		dado2=0;
	if(dado3>0.85)
		dado3=1;
	else
		dado3=0;

	if(muertos)
	{
		jugador2.AñadirComida(dado1*muertos);
		jugador2.AñadirHierro(dado2*muertos);
		jugador2.AñadirOro(dado3*muertos);
	}
	muertos=jugador2.Morir();
	if(muertos)
	{
		jugador1.AñadirComida(dado1*muertos);
		jugador1.AñadirHierro(dado2*muertos);
		jugador1.AñadirOro(dado3*muertos);
	}
}