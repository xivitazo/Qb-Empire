#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include <stdio.h>


Mundo::Mundo():jugador1(0, 0, 205), jugador2 (179,36,40)
{
}
void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		miro_x, miro_y, miro_z,      // hacia que punto mira  (0,0,0) 
			0.0, 0, 1.0);      // definimos hacia arriba (eje Z)    

	//aqui es donde hay que poner el codigo de dibujo

	
	//dibujo del suelo
	map.Dibuja();
	jugador1.Dibuja();
	jugador2.Dibuja();
	
	//Tenemos posibles coordenadas del mapa.
	/*printf("Posicion Ojo x:  %f",x_ojo);
	printf("\n");
	printf("Posicion Ojo y: %f",y_ojo);
	printf("\n");
	printf("Posicion Ojo z: %f",z_ojo);
	printf("\n");
	printf("Miro x:  %f", miro_x);
	printf("\n");
	printf("Miro y: %f", miro_y);
	printf("\n");
	printf("Miro z: %f", miro_z);
	printf("\n");*/
  
}

void Mundo::Timer(float t)
{
	jugador1.Rebote();
	jugador2.Rebote();
	for(int n=0; n<jugador1.getNumero();n++)
	{
		for(int i=0; i<jugador2.getNumero();i++)
			Interaccion :: Rebote(jugador1.getPosN(n),jugador2.getPosN(i));
	}
	jugador1.Timer(t);
	jugador2.Timer(t);
}

void Mundo::Inicializa()
{
	x_ojo=112.5;
	y_ojo=-37.5;
	z_ojo=50;
	miro_x=112.5;
	miro_y=37.5;
	miro_z=0;
}

void Mundo::Tecla(unsigned char key)
{
	switch(key)
	{
	case 'a': x_ojo+=1; break;
	case 's': y_ojo+=1; break;
	case 'd': z_ojo+=1; break;
	case 'z': x_ojo-=1; break;
	case 'x': y_ojo-=1; break;
	case 'c': z_ojo-=1; break;
	case 'f': miro_x+=1; break;
	case 'g': miro_y+=1; break;
	case 'h': miro_z+=1; break;
	case 'v': miro_x-=1; break;
	case 'b': miro_y-=1; break;
	case 'n': miro_z-=1; break;
	case '1': setPerspectiva(-37.5,37.5,50,25,37.5,0); break; //Vista Poblado
	case '2': setPerspectiva(112.2,-28.5,60,112.5,27.5,0); break; //Vista Batalla
	case '3': setPerspectiva(-23,-47,50,50,25,0); break; //Vista General
	case 'p': jugador1.prueba(1);
	case 'o': jugador2.prueba(2);
	}
}

void Mundo::Raton(int button, int state, Vector pos)
{
	printf("%f\t%f\n", pos.vx, pos.vy);
}

void Mundo:: RatonPasivo(int x, int y)
{

}

void Mundo:: setPerspectiva(float ojo_a, float ojo_b, float ojo_c, float miro_a, float miro_b, float miro_c)
{
	x_ojo=ojo_a;
	y_ojo=ojo_b;
	z_ojo=ojo_c;
	miro_x=miro_a;
	miro_y=miro_b;
	miro_z=miro_c;
}