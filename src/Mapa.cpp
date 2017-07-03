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
<<<<<<< HEAD
	glLoadName(MAPA);
	cesped1();
	cesped2();
	barro();
=======
	cesped();
	//rio();
>>>>>>> refs/remotes/origin/master
	montaña();
	nubes();
}

<<<<<<< HEAD
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
=======
void Mapa :: cesped ()
{
	glPushMatrix();
	//Misma razón que con otros. El comando glut para dibujar nos mantiene las luces puestas sin necesidad de hacer nada más.
	//Trucos del prueba y error
	glutWireCube(0.0001); //Queda poco profesional, pero funciona

	//Así coloreamos por trozos, pero no usamos una matriz
	//Por eso no lo implemento, no hallo diferencia...
	/*
	glBegin(GL_QUADS);
	glColor3ub(48,132,70);
	for(int i=0; i<72; i++)
	{
		for (int j=0; j<75; j++)
		{
				glVertex3f(i,j,0);
				glVertex3f(i+1,j,0);
				glVertex3f(i+1,j+1,0);
				glVertex3f(i,j+1,0);
		}
	}
	glEnd();
	*/
	glBegin(GL_QUADS);
>>>>>>> refs/remotes/origin/master
		glColor3ub(48,132,70);
		glVertex2f(0,0);
		glVertex2f(72.5f, 0);
		glVertex2f(72.5f,75.0f);
		glVertex2f(0,75.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(48,132,70);
		glVertex2f(72.5f,0);
		glVertex2f(72.5f,75.0f);
		glColor3ub(78,59,49);
		glVertex2f(77.5f,75.0f);	
		glVertex2f(77.5f,0);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(78,59,49);
		glVertex2f(77.5f,0);
		glVertex2f(77.5f,75.0f);
		glVertex2f(147.5f,75.0f);	
		glVertex2f(147.5f,0);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(78,59,49);
		glVertex2f(147.5f,0);
		glVertex2f(147.5f,75.0f);
		glColor3ub(48,132,70);
		glVertex2f(152.5f,75.0f);	
		glVertex2f(152.5f,0);
	glEnd();
	glBegin(GL_QUADS);
		glColor3ub(48,132,70);
		glVertex2f(152.5f,0);
		glVertex2f(152.5f,75.0f);
		glVertex2f(225.0f,75.0f);	
		glVertex2f(225.0f,0);
	glEnd();
<<<<<<< HEAD
	glEnable(GL_LIGHTING);*/
=======
	glPopMatrix();
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
	glTranslatef(-0.5,-0.5,0);
=======
	//glutWireCube(0.0001);
	
>>>>>>> refs/remotes/origin/master
	//Pared eje X
	glBegin(GL_QUADS);
	glColor3ub(130, 130 ,130);
		glVertex3f(0,0,0);
		glVertex3f((float)dimension.vx, 0, 0);
		glVertex3f((float)dimension.vx, 0, (float)altura);	
		glVertex3f(0, 0,(float)altura);
	glEnd();
	//Pared Eje Y
	glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(0,0,(float)altura);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);	
		glVertex3f(0,(float)dimension.vy,0);
	glEnd();
	//Pared Eje XFondo
	glBegin(GL_QUADS);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
	glEnd();
	//Pared Eje YFondo
	glBegin(GL_QUADS);
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,0,(float)altura);	
		glVertex3f((float)dimension.vx,0,0);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0,(float)dimension.vy,0);
		glVertex3f(0.0f,(float)dimension.vy,(float)altura);
		glVertex3f((float)dimension.vx,(float)dimension.vy,(float)altura);	
		glVertex3f((float)dimension.vx,(float)dimension.vy,0);
	glEnd();
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