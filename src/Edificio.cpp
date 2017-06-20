#include "Edificio.h"
#include <math.h>


Edificio::Edificio(unsigned int v, unsigned int _altura, Color _color, Planta planta, Vector _superficie):
	Objeto(_altura, _color, planta, _superficie)
{
	rango_visibilidad=20;
	vida_max=v;
	vida=vida_max;
}
Edificio :: Edificio (const Edificio* copia)
{
}

Edificio::~Edificio(void)
{
}

void Edificio :: setTipo (Type tipo)
{
	this->tipo=tipo;
}




void Edificio :: Timer (float t)
{
	color_vida();
}

void Edificio :: Dibuja (Color equipo)
{
}

void Edificio :: Tecla ()
{
}

void Edificio :: casita (Vector posicion, Color tejado, Color pared, Vector dimension, int altura)
{
	glPushMatrix();
	glTranslatef(posicion.vx, posicion.vy, 0);
	
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	//Pared eje X
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,0,0);
		glVertex3f(0, 0,(float)altura);
		glVertex3f(dimension.vx, 0, (float)altura);	
		glVertex3f(dimension.vx, 0, 0);
	glEnd();
	//Pared Eje Y
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,0,0);
		glVertex3f(0,dimension.vx,0);
		glVertex3f(0.0f,dimension.vy,(float)altura);	
		glVertex3f(0,0,(float)altura);
	glEnd();
	//Pared Eje XFondo
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,dimension.vy,0);
		glVertex3f(0.0f,dimension.vy,(float)altura);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,dimension.vy,0);
	glEnd();
	//Pared Eje YFondo
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(dimension.vx,dimension.vy,0);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,0,(float)altura);	
		glVertex3f(dimension.vx,0,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,dimension.vy,0);
		glVertex3f(0.0f,dimension.vy,(float)altura);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,dimension.vy,0);
	glEnd();
	// Techo Eje X
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0, 0,(float)altura);
		glVertex3f(dimension.vx/2.0f,dimension.vy/2.0f,(float)altura+2.0f);
		glVertex3f(dimension.vx,0,(float)altura);	
	glEnd();
	//Techo Eje y
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0, 0,(float)altura);
		glVertex3f(dimension.vx/2.0f,dimension.vy/2.0f,(float)altura+2.0f);
		glVertex3f(0,dimension.vy,(float)altura);	
	glEnd();
	//Techo Eje Xfondo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx/2.0f,dimension.vy/2.0f,(float)altura+2.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	//Techo Eje YFOndo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(dimension.vx,0,(float)altura);		
		glVertex3f(dimension.vx/2.0f,dimension.vy/2.0f,(float)altura+2.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	//glEnable(GL_LIGHTING);
	glPopMatrix();
	
}

void Edificio :: color_vida()
{
	color.set(color.getRed()*(vida/vida_max),color.getGreen()*(vida/vida_max),color.getBlue()*(vida/vida_max));
}
void Edificio :: poderGenerar (Type tipo)
{
}
void Edificio :: subirNivel()
{
}