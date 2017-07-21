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
	nombre=0;
}

Mapa::~Mapa(void)
{
}
			
void Mapa :: inicializa()
{
	//Ponemos los posibles sprites ( animaciones / explosiones)
	//glPushName(20);
	//help = new Sprite ("imagenes/help.png", glutGet(GLUT_WINDOW_WIDTH)-150, glutGet(GLUT_WINDOW_HEIGHT)-60, 40, 40);
	//glPopName();
	nube01 = new Sprite ("imagenes/nube01.png", 0, 105, 30, 30);
	nube02 = new Sprite ("imagenes/nube02.png", 0, 105, 30, 30);
	nube03 = new Sprite ("imagenes/nube03.png", 0, 105, 30, 30);

	mitextura=getTexture("imagenes/piedraa.png");
	
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
	nombre=0;
	glutWireCube(0.001);
	cesped1();
	barro();
	cesped2();
	glLoadName(99);
	monta�a();
	sprites();

}

void Mapa :: cesped1 ()
{
	for(int n=0; n<20;n++)
	{
		glPushName(100+4*n+2);
		for (int i=0; i<20;i++)
		{
			glPushName(100+4*i+2);
			glPushMatrix();
			glTranslatef(n*4+2,4*i+2,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedA[n][i].getRed(),cespedA[n][i].getGreen(), cespedA[n][i].getBlue());
				glVertex2f(-2,-2);
				glVertex2f(-2, 2);
				glColor3ub(cespedA[n+1][i].getRed(),cespedA[n+1][i].getGreen(), cespedA[n+1][i].getBlue());
				glVertex2f(2,2);
				glVertex2f(2,-2);
			glEnd();
			glPopMatrix();
			glPopName();
			nombre++;
		}
		glPopName();
	}
}

void Mapa :: barro ()
{
	for(int n=0; n<20;n++)
	{
		glPushName(180+4*n+2);
		for (int i=0; i<20;i++)
		{
			glPushMatrix();
			glPushName(100+4*i+2);
			glTranslatef(80+n*4+2,4*i+2,0);
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
		glPopName();
	}
}

void Mapa :: monta�a ()
{
	Vector dimension(20, 20);
	glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, mitextura.id);
			glDisable(GL_LIGHTING);
	
		//PARED EJE X PROXIMO
		for (int i=0; i<12; i++)
		{
			for(int n=0;n<15;n++)
			{
				glPushMatrix();
				glTranslatef(dimension.vx*i+dimension.vx/2.0f,0,-dimension.vy*n-dimension.vy/2.0f);
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glTexCoord2d(1,1); glVertex3f(-dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,1); glVertex3f(dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,0); glVertex3f(dimension.vx/2.0f,0,dimension.vy/2.0f);
					glTexCoord2d(1,0); glVertex3f(-dimension.vx/2.0f,0,dimension.vy/2.0f);
				glEnd();
				glPopMatrix();
			}
		}

		//PARED EJE Y PROXIMO
		glPushMatrix();
		glRotatef(90, 0, 0, -1);
		for (int i=0; i<4; i++)
		{
			for(int n=0;n<15;n++)
			{
				glPushMatrix();
				glTranslatef(-dimension.vx*i-dimension.vx/2.0f,0,-dimension.vy*n-dimension.vy/2.0f);
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glTexCoord2d(1,1); glVertex3f(-dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,1); glVertex3f(dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,0); glVertex3f(dimension.vx/2.0f,0,dimension.vy/2.0f);
					glTexCoord2d(1,0); glVertex3f(-dimension.vx/2.0f,0,dimension.vy/2.0f);
				glEnd();
				glPopMatrix();
			}
		}
		glPopMatrix();

		//PARED EJE X LEJANO
		for (int i=0; i<12; i++)
		{
			for(int n=0;n<15;n++)
			{
				glPushMatrix();
				glTranslatef(dimension.vx*i+dimension.vx/2.0f,80,-dimension.vy*n-dimension.vy/2.0f);
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glTexCoord2d(1,1); glVertex3f(-dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,1); glVertex3f(dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,0); glVertex3f(dimension.vx/2.0f,0,dimension.vy/2.0f);
					glTexCoord2d(1,0); glVertex3f(-dimension.vx/2.0f,0,dimension.vy/2.0f);
				glEnd();
				glPopMatrix();
			}
		}

		//PARED EJE Y LEJANO
		glPushMatrix();
		glRotatef(90, 0, 0, -1);
		for (int i=0; i<4; i++)
		{
			for(int n=0;n<15;n++)
			{
				glPushMatrix();
				glTranslatef(-dimension.vx*i-dimension.vx/2.0f,240,-dimension.vy*n-dimension.vy/2.0f);
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glTexCoord2d(1,1); glVertex3f(-dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,1); glVertex3f(dimension.vx/2.0f,0,-dimension.vy/2.0f);
					glTexCoord2d(0,0); glVertex3f(dimension.vx/2.0f,0,dimension.vy/2.0f);
					glTexCoord2d(1,0); glVertex3f(-dimension.vx/2.0f,0,dimension.vy/2.0f);
				glEnd();
				glPopMatrix();
			}
		}
		glPopMatrix();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPushMatrix();
		glLineWidth(1.0f);
		glBegin(GL_LINES);
		glColor3ub(0, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(240, 0, 0);
		glVertex3f(240, 0, 0);
		glVertex3f(240, 80, 0);
		glVertex3f(240, 80, 0);
		glVertex3f(0, 80, 0);
		glVertex3f(0, 80, 0);
		glVertex3f(0, 0, 0);
		glEnd();
	glPopMatrix();

	/*
	glPushMatrix();
	float altura=-300;
	Vector dimension(240, 80);

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
	glPopMatrix();
	*/
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
	{
		glPushName(260+4*n+2);
		for (int i=0; i<20;i++)
		{
			glPushName(100+4*i+2);
			glPushMatrix();
			glTranslatef(n*4+160+2,i*4+2,0);
			glBegin(GL_QUADS);
				glColor3ub(cespedB[n][i].getRed(),cespedB[n][i].getGreen(), cespedB[n][i].getBlue());
				glVertex2f(-2,-2);
				glVertex2f(-2, 2);
				glColor3ub(cespedB[n+1][i].getRed(),cespedB[n+1][i].getGreen(), cespedB[n+1][i].getBlue());
				glVertex2f(2,2);
				glVertex2f(2,-2);
			glEnd();
			glPopMatrix();
			glPopName();
			nombre++;
		}
		glPopName();
	}
}

void Mapa :: sprites ()
{
	nubes();
	/*
	//ayuda	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

			help->draw();				
			
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	*/
}