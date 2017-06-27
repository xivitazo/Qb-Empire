#include "Menus.h"


Menus::Menus(void)
{
}


Menus::~Menus(void)
{
}

void Menus :: seleccion (Type tipo)
{
	if(tipo==AYUNTAMIENTO){

	}

}

void Menus :: construccion()
{

}

void Menus :: superior(Mundo &mundo)
{
	glPushMatrix();
		setTextColor(1,1,0);/*
		mundo.amiro_x
		mundo.amiro_y
		mundo.amiro_z
		mundo.ax_ojo			
		mundo.ay_ojo
		mundo.amiro_x
		mundo.amiro_x*/
		
		glTranslatef((mundo.ax_ojo-mundo.amiro_x), mundo.ay_ojo-mundo.amiro_y, mundo.az_ojo-mundo.amiro_z);
		setFont("fuentes/Bitwise.ttf",100);		
		printxy("ESTE SERA EL MENU SUPERIOR", 50, 300);
	glPopMatrix();
}

void Menus :: Timer (float t)
{
}