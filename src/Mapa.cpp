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