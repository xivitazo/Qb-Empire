#include "Edificio.h"
#include <math.h>


Edificio::Edificio(unsigned int v)
{
	vida_max=v;
	vida=vida_max;
}

Edificio::~Edificio(void)
{
}

void Edificio :: setTipo (unsigned int tipo)
{
	this->tipo=tipo;
}

unsigned int Edificio :: numero_generado=0;
unsigned int Edificio :: numero_total=0;
unsigned int Edificio :: nivel=0;

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

void Edificio :: casita (Vector posicion, Color tejado, Color pared, int dimension, int altura)
{
	glPushMatrix();
	glTranslatef(posicion.vx, posicion.vy, 0);
	glDisable(GL_LIGHTING);
	//Pared eje X
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,0,0);
		glVertex3f(0, 0,(float)altura);
		glVertex3f((float)dimension, 0, (float)altura);	
		glVertex3f((float)dimension, 0, 0);
	glEnd();
	//Pared Eje Y
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,0,0);
		glVertex3f(0,(float)dimension,0);
		glVertex3f(0.0f,(float)dimension,(float)altura);	
		glVertex3f(0,0,(float)altura);
	glEnd();
	//Pared Eje XFondo
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,(float)dimension,0);
		glVertex3f(0.0f,(float)dimension,(float)altura);
		glVertex3f((float)dimension,(float)dimension,(float)altura);	
		glVertex3f((float)dimension,(float)dimension,0);
	glEnd();
	//Pared Eje YFondo
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f((float)dimension,(float)dimension,0);
		glVertex3f((float)dimension,(float)dimension,(float)altura);	
		glVertex3f((float)dimension,0,(float)altura);	
		glVertex3f((float)dimension,0,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(0,(float)dimension,0);
		glVertex3f(0.0f,(float)dimension,(float)altura);
		glVertex3f((float)dimension,(float)dimension,(float)altura);	
		glVertex3f((float)dimension,(float)dimension,0);
	glEnd();
	// Techo Eje X
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0, 0,(float)altura);
		glVertex3f((float)dimension/2.0f,(float)dimension/2.0f,(float)altura+2.0f);
		glVertex3f((float)dimension,0,(float)altura);	
	glEnd();
	//Techo Eje y
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0, 0,(float)altura);
		glVertex3f((float)dimension/2.0f,(float)dimension/2.0f,(float)altura+2.0f);
		glVertex3f(0,(float)dimension,(float)altura);	
	glEnd();
	//Techo Eje Xfondo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(0,(float)dimension,(float)altura);	
		glVertex3f((float)dimension/2.0f,(float)dimension/2.0f,(float)altura+2.0f);
		glVertex3f((float)dimension,(float)dimension,(float)altura);	
	glEnd();
	//Techo Eje YFOndo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f((float)dimension,0,(float)altura);		
		glVertex3f((float)dimension/2.0f,(float)dimension/2.0f,(float)altura+2.0f);
		glVertex3f((float)dimension,(float)dimension,(float)altura);	
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
}

void Edificio :: color_vida()
{
	color.set(color.getRed()*(vida/vida_max),color.getGreen()*(vida/vida_max),color.getBlue()*(vida/vida_max));
}