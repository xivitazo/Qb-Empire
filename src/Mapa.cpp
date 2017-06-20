#include "Mapa.h"
#include "glut.h"

Mapa::Mapa(void)
{
}

Mapa::~Mapa(void)
{
}

void Mapa :: Dibuja ()
{
	cesped();
	rio();
	montaña();
}

void Mapa :: cesped ()
{
	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(100,250,0);
		glVertex3f(-500.0f,0,-50.0f);
		glVertex3f(-500.0f,0,50.0f);
		glVertex3f(500.0f,0,50.0f);	
		glVertex3f(500.0f,0,-50.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/
	//glPopMatrix();
	/*glTranslatef(30.0f,30.0f,0);
	glColor3ub(255,255,255);
	glutSolidCube(4);
	glTranslatef(-30.0f,-30.0f,0);*/
	//glPushMatrix();
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(48,132,70);
		glVertex2f(0,0);
		glVertex2f(75.0f, 0);
		glVertex2f(75.0f,75.0f);	
		glVertex2f(0,75.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(78,59,49);
		glVertex2f(75.0f,0);
		glVertex2f(75.0f,75.0f);
		glVertex2f(150.0f,75.0f);	
		glVertex2f(150.0f,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(48,132,70);
		glVertex2f(150.0f,0);
		glVertex2f(150.0f,75.0f);
		glVertex2f(225.0f,75.0f);	
		glVertex2f(225.0f,0);
	glEnd();
	glEnable(GL_LIGHTING);

	
}


void Mapa :: rio ()
{
	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(0,0,250);
		glVertex3f(-10.0f,1,-50.0f);
		glVertex3f(-10.0f,1,50.0f);
		glVertex3f(-30.0f,1,50.0f);	
		glVertex3f(-30.0f,1,-50.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/
}

void Mapa :: montaña ()
{
	glPushMatrix();
	float altura=-300;
	Vector dimension(225, 75);
	
	//glDisable(GL_LIGHTING);	
	//glShadeModel(GL_FLAT);
	//Pared eje X
	glBegin(GL_POLYGON);
	glColor3ub(130, 130 ,130);
		glVertex3f(0,0,0);
		glVertex3f(0, 0,(float)altura);
		glVertex3f((float)dimension.vx, 0, (float)altura);	
		glVertex3f((float)dimension.vx, 0, 0);
	glEnd();
	//Pared Eje Y
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);	
		glVertex3f(0,0,(float)altura);
	glEnd();
	//Pared Eje XFondo
	glBegin(GL_POLYGON);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
	glEnd();
	//Pared Eje YFondo
	glBegin(GL_POLYGON);
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,0,(float)altura);	
		glVertex3f((float)dimension.vx,0,0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
	glEnd();
	//Techo, eso sí

	//glEnable(GL_LIGHTING);
	glPopMatrix();
}