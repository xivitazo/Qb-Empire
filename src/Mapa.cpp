#include "Mapa.h"
#include "glut.h"

Mapa::Mapa(void)
{
	for(int n=0; n<75;n++)
		for (int i=0; i<75;i++)
		{
			cespedA[i][n]=Color(48,132,70);
			cespedB[i][n]=Color(48,132,70);
			barroA[i][n]=Color(78,59,49);
		}
	for(int i=0;i<3;i++)
		for(int n=0; n<75;n++)
		{
			cespedA[73+i][n]=Color(48+6*(i+1),132-14.6*(i+1),70-4.2*(i+1));
			barroA[i][n]=Color(48+6*(i+3),132-14.6*(i+3),70-4.2*(i+3));
			barroA[73+i][n]=Color(78-6*(i+1),59+14.6*(i+1),49+4.2*(i+1));
			cespedB[i][n]=Color(78-6*(i+3),59+14.6*(i+3),49+4.2*(i+3));
		}
	nombre=0;
}

Mapa::~Mapa(void)
{
}

void Mapa :: Dibuja ()
{
	glLoadName(MAPA);
	cesped1();
	cesped2();
	barro();
	montaña();
}

void Mapa :: cesped1 ()
{
	for(int n=0; n<74;n++)
		for (int i=0; i<75;i++)
		{
			glPushMatrix();
			glLoadName(nombre);
			glTranslatef(n,i,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedA[n][i].getRed(),cespedA[n][i].getGreen(), cespedA[n][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glColor3ub(cespedA[n+1][i].getRed(),cespedA[n+1][i].getGreen(), cespedA[n+1][i].getBlue());
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopMatrix();
			nombre++;
		}
		for (int i=0; i<75;i++)
		{
			glPushMatrix();
			glLoadName(nombre);
			glTranslatef(74,i,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedA[74][i].getRed(),cespedA[74][i].getGreen(), cespedA[74][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glColor3ub(barroA[0][i].getRed(),barroA[0][i].getGreen(),barroA[0][i].getBlue());
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopMatrix();
			nombre++;
		}
	/*glDisable(GL_LIGHTING);
	
	glBegin(GL_POLYGON);
		glColor3ub(48,132,70);
		glVertex2f(0,0);
		glVertex2f(72.5f, 0);
		glVertex2f(72.5f,75.0f);
		glVertex2f(0,75.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(48,132,70);
		glVertex2f(72.5f,0);
		glVertex2f(72.5f,75.0f);
		glColor3ub(78,59,49);
		glVertex2f(77.5f,75.0f);	
		glVertex2f(77.5f,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(78,59,49);
		glVertex2f(77.5f,0);
		glVertex2f(77.5f,75.0f);
		glVertex2f(147.5f,75.0f);	
		glVertex2f(147.5f,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(78,59,49);
		glVertex2f(147.5f,0);
		glVertex2f(147.5f,75.0f);
		glColor3ub(48,132,70);
		glVertex2f(152.5f,75.0f);	
		glVertex2f(152.5f,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3ub(48,132,70);
		glVertex2f(152.5f,0);
		glVertex2f(152.5f,75.0f);
		glVertex2f(225.0f,75.0f);	
		glVertex2f(225.0f,0);
	glEnd();
	glEnable(GL_LIGHTING);*/
}


void Mapa :: barro ()
{
	
	for(int n=0; n<74;n++)
		for (int i=0; i<75;i++)
		{
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(75+n,i,0);
			glBegin(GL_QUADS);
			glColor3ub(barroA[n][i].getRed(),barroA[n][i].getGreen(), barroA[n][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glColor3ub(barroA[n+1][i].getRed(),barroA[n+1][i].getGreen(), barroA[n+1][i].getBlue());
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopMatrix();
			glPopMatrix();
			nombre++;
		}
		for (int i=0; i<75;i++)
		{
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(75+74,i,0);
			glBegin(GL_QUADS);
				glColor3ub(barroA[74][i].getRed(),barroA[74][i].getGreen(), barroA[74][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glColor3ub(cespedB[0][i].getRed(),cespedB[0][i].getGreen(),cespedB[0][i].getBlue());
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopName();
			glPopMatrix();
			nombre++;
		}
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
	glTranslatef(-0.5,-0.5,0);
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

void Mapa :: cesped2()
{
	for(int n=0; n<74;n++)
		for (int i=0; i<75;i++)
		{
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(n+150,i,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedB[n][i].getRed(),cespedB[n][i].getGreen(), cespedB[n][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glColor3ub(cespedB[n+1][i].getRed(),cespedB[n+1][i].getGreen(), cespedB[n+1][i].getBlue());
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopName();
			glPopMatrix();
			nombre++;
		}
	for (int i=0; i<75;i++)
		{
			int n=74;
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(n+150,i,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedB[n][i].getRed(),cespedB[n][i].getGreen(), cespedB[n][i].getBlue());
				glVertex2f(-0.5,-0.5);
				glVertex2f(-0.5, 0.5);
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			glPopName();
			glPopMatrix();
			nombre++;
		}
		
		

}