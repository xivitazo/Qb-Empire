#include "Mapa.h"


Mapa::Mapa(void)
{
	for(int n=0; n<20;n++)
		for (int i=0; i<21;i++)
		{
			cespedA[i][n]=Color(48,132,70);
			cespedB[i][n]=Color(48,132,70);
			barroA[i][n]=Color(78,59,49);
		}/*
	for(int i=0;i<2;i++)
		for(int n=0; n<20;n++)
		{
			cespedA[18+i][n]=Color(48+7.5*(i+1),132-18.25*(i+1),70-5.25*(i+1));
			barroA[i][n]=Color(48+7.5*(i+3),132-18.25*(i+3),70-5.25*(i+3));
			barroA[18+i][n]=Color(78-7.5*(i+1),59+18.25*(i+1),49+5.25*(i+1));
			cespedB[i][n]=Color(78-7.5*(i+3),59+18.25*(i+3),49+5.25*(i+3));
		}*/
	nombre=50;
}

Mapa::~Mapa(void)
{
}

void Mapa :: inicializa()
{
	//Ponemos los posibles sprites ( animaciones / explosiones)
	nube01 = new Sprite ("imagenes/nube01.png", 0, 105, 30, 30);
	nube02 = new Sprite ("imagenes/nube02.png", 0, 105, 30, 30);
	nube03= new Sprite ("imagenes/nube03.png", 0, 105, 30, 30);
	//nube01->Sprite::setPos(0, 0);
	//nube01->ETSIDI::Sprite::setVel(0, 0);

	//Posibles nubes para implementar
	/*nube01 = new Sprite ("imagenes/nube01.png", 0, 105, 30, 30);
	nube02 = new Sprite ("imagenes/nube02.png", 0, 105, 30, 30);
	nube03 = new Sprite ("imagenes/nube03.png", 0, 105, 30, 30);
	nube01 = new Sprite ("imagenes/nube01.png", 0, 105, 30, 30);
	nube02 = new Sprite ("imagenes/nube02.png", 0, 105, 30, 30);
	nube03 = new Sprite ("imagenes/nube03.png", 0, 105, 30, 30);*/

}

void Mapa :: Dibuja ()
{
	glutWireCube(0.001);
	glLoadName(MAPA);
	cesped1();
	cesped2();
	barro();
	//rio();
	monta�a();
	nubes();
}

void Mapa :: cesped1 ()
{
	for(int n=0; n<20;n++)
		for (int i=0; i<20;i++)
		{
			glPushMatrix();
			glLoadName(nombre);
			glTranslatef(n*4,4*i,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedA[n][i].getRed(),cespedA[n][i].getGreen(), cespedA[n][i].getBlue());
				glVertex2f(-2,-2);
				glVertex2f(-2, 2);
				glColor3ub(cespedA[n+1][i].getRed(),cespedA[n+1][i].getGreen(), cespedA[n+1][i].getBlue());
				glVertex2f(2,2);
				glVertex2f(2,-2);
			glEnd();
			glPopMatrix();
			nombre++;
		}
}

void Mapa :: barro ()
{
	for(int n=0; n<20;n++)
		for (int i=0; i<20;i++)
		{
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(80+n*4,4*i,0);
			glBegin(GL_QUADS);
			glColor3ub(barroA[n][i].getRed(),barroA[n][i].getGreen(), barroA[n][i].getBlue());
				glVertex2f(-2,-2);
				glVertex2f(-2, 2);
				glColor3ub(barroA[n+1][i].getRed(),barroA[n+1][i].getGreen(), barroA[n+1][i].getBlue());
				glVertex2f(2,2);
				glVertex2f(2,-2);
			glEnd();
			glPopName();
			glPopMatrix();
			nombre++;
		}
}

void Mapa :: monta�a ()
{
	glPushMatrix();
	float altura=-300;
	Vector dimension(240, 80);
	glTranslatef(-2,-2,0);
	glPushName(-1);
	//Pared eje X
	glBegin(GL_QUADS);
	glColor3ub(130, 130 ,130);
		glVertex3f(0,0,0);
		glVertex3f((float)dimension.vx, 0, 0);
		glVertex3f((float)dimension.vx, 0, (float)altura);	
		glVertex3f(0, 0,(float)altura);
	glEnd();
	glPopName();
	glPushName(-2);
	//Pared Eje Y
	glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(0,0,(float)altura);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);	
		glVertex3f(0,(float)dimension.vy,0);
	glEnd();
	glPopName();
	glPushName(-3);
	//Pared Eje XFondo
	glBegin(GL_QUADS);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
	glEnd();
	glPopName();
	glPushName(-4);
	//Pared Eje YFondo
	glBegin(GL_QUADS);
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,0,(float)altura);	
		glVertex3f((float)dimension.vx,0,0);
	glEnd();
	glPopName();
	glPopMatrix();
}

void Mapa :: nubes ()
{
	//NUBE 1
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(80, -80, -100);
	nube01->draw();
	glPopMatrix();
	//NUBE 2
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(10, -100, -100);
	nube02->draw();
	glPopMatrix();
	//NUBE 3
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(150, -60, -100);
	nube03->draw();
	glPopMatrix();
}

void Mapa :: cesped2()
{
	for(int n=0; n<20;n++)
		for (int i=0; i<20;i++)
		{
			glPushMatrix();
			glPushName(nombre);
			glTranslatef(n*4+160,i*4,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedB[n][i].getRed(),cespedB[n][i].getGreen(), cespedB[n][i].getBlue());
				glVertex2f(-2,-2);
				glVertex2f(-2, 2);
				glColor3ub(cespedB[n+1 ][i].getRed(),cespedB[n+1][i].getGreen(), cespedB[n+1][i].getBlue());
				glVertex2f(2,2);
				glVertex2f(2,-2);
			glEnd();
			glPopName();
			glPopMatrix();
			nombre++;
		}
}
