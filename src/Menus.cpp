#include "Menus.h"


Menus::Menus()
{
}

Menus::~Menus(void)
{
}

void Menus :: seleccion (Type tipo, Mundo &mundo)
{
	/*
	if(tipo==AYUNTAMIENTO){
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(215.0f/255.0f, 45.0f/255.0f, 109.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			//sprintf(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			sprintf_s(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			printxy(aux, 50, 50);
			
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}

	if(tipo==F_ORO){
	//Menu definitivo
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(245.0f/255.0f,208.0f/255.0f,51.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_ORO]);
			printxy(aux, 50, 50);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}

	if(tipo==F_HIERRO){
	//Menu definitivo
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(157/255.0f,161/255.0f,170/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_HIERRO]);
			printxy(aux, 50, 50);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}

	if(tipo==F_COMIDA){
	//Menu definitivo
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(234/255.0f,137/255.0f,154/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_COMIDA]);
			printxy(aux, 50, 50);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}

	if(tipo==CUARTEL){
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(139.0f/255.0f,69.0f/255.0f,19.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux1[100], aux2[100], aux3[100], aux4[100], aux5[100], aux6[100];
			sprintf_s(aux1,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[CUARTEL]);
			sprintf_s(aux2,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[ARQUERA]);
			sprintf_s(aux3,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[SOLDADO]);
			sprintf_s(aux4,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[CABALLERO]);
			sprintf_s(aux5,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[GUERRERO]);
			sprintf_s(aux6,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[GIGANTE]);
			printxy("ARQUERA", 500, 250);
			printxy("SOLDADO", 500, 200);
			printxy("CABALLERO", 500, 150);
			printxy("GUERRERO", 500, 100);
			printxy("GIGANTE", 500, 50);
			printxy("CUARTEL", 50, 100);
			printxy(aux1, 50, 50);
			printxy(aux2, 900, 50);
			printxy(aux3, 900, 100);
			printxy(aux4, 900, 150);
			printxy(aux5, 900, 200);
			printxy(aux6, 900, 250);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);

	}
	if(tipo==F_HIERRO){
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(157.0f/255.0f, 161.0f/255.0f, 170.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[F_HIERRO]);
			printxy(aux, 50, 50);
			
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}
	if(tipo==F_COMIDA){
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(234.0f/255.0f, 137.0f/255.0f, 154.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[F_COMIDA]);
			printxy(aux, 50, 50);
			
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}

	if(tipo==CABALLERO){
	//Menu definitivo
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(245.0f/255.0f,208.0f/255.0f,51.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_ORO]);
			printxy(aux, 50, 50);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	}
	*/
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		switch(tipo)
		{
		case AYUNTAMIENTO:
			setTextColor(215.0f/255.0f, 45.0f/255.0f, 109.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux[100];
			//sprintf(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			sprintf_s(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			printxy(aux, 50, 50);
			break;
		case F_ORO: 
			setTextColor(245.0f/255.0f,208.0f/255.0f,51.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxo[100];
			sprintf_s(auxo,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_ORO]);
			printxy(auxo, 50, 50);
			break;
		case F_HIERRO:
			setTextColor(157/255.0f,161/255.0f,170/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxh[100];
			sprintf_s(auxh,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_HIERRO]);
			printxy(auxh, 50, 50);
			break;
		case F_COMIDA:
			setTextColor(234.0f/255.0f, 137.0f/255.0f, 154.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxc[100];
			sprintf_s(auxc,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[F_COMIDA]);
			printxy(auxc, 50, 50);
			break;
		case CUARTEL:
			setTextColor(139.0f/255.0f,69.0f/255.0f,19.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char aux1[100], aux2[100], aux3[100], aux4[100], aux5[100], aux6[100];
			sprintf_s(aux1,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[CUARTEL]);
			sprintf_s(aux2,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[ARQUERA]);
			sprintf_s(aux3,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[SOLDADO]);
			sprintf_s(aux4,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[CABALLERO]);
			sprintf_s(aux5,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[GUERRERO]);
			sprintf_s(aux6,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[GIGANTE]);
			printxy("ARQUERA", 500, 250);
			printxy("SOLDADO", 500, 200);
			printxy("CABALLERO", 500, 150);
			printxy("GUERRERO", 500, 100);
			printxy("GIGANTE", 500, 50);
			printxy("CUARTEL", 50, 100);
			printxy(aux1, 50, 50);
			printxy(aux2, 900, 50);
			printxy(aux3, 900, 100);
			printxy(aux4, 900, 150);
			printxy(aux5, 900, 200);
			printxy(aux6, 900, 250);
			break;
		}

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void Menus :: construccion(Mundo &mundo)
{
	//NO BORRAR. TODAVÍA 
	/*
	glPushMatrix();
		GLdouble x,y,z,modelview[16],proyeccion[16];
		GLint viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
		glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
		glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
		gluUnProject(0, 0,1,modelview,proyeccion,viewport,&x,&y,&z);
		glTranslatef(x,y,z);
		setTextColor(1,0.8,0);
		setFont("fuentes/Bitwise.ttf",20);		
		char aux[500];
		sprintf(aux,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_ORO]);
		printxy(aux,0,0);
	glPopMatrix();
	*/
	//Menu definitivo
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",20);		
			char aux1[100], aux2[100], aux3[100], aux4[100];
			sprintf_s(aux1," CONSTRUIR FABRICA DE ORO  -  PULSAR   O   -");	
			sprintf_s(aux2," CONSTRUIR FABRICA DE HIERRO  -  PULSAR   Y  -");	
			sprintf_s(aux3," CONSTRUIR FABRICA DE COMIDA  -  PULSAR   U  -");
			sprintf_s(aux4," CONSTRUIR UN CUARTEL  -  PULSAR  I  -");
			printxy(aux1,30, 200); 
			printxy(aux2,30, 150);
			printxy(aux3,30, 100);
			printxy(aux4,30, 50);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);

}

void Menus :: superior(Mundo &mundo)
{
	/*
	glPushMatrix();
		GLdouble x,y,z,modelview[16],proyeccion[16];
		GLint viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
		glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
		glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
		gluUnProject(0, 700,1,modelview,proyeccion,viewport,&x,&y,&z);
		
		glTranslatef(x, y, z);
		setTextColor(1,0.8,0);
		setFont("fuentes/Bitwise.ttf",20);		
		char aux[500];
		sprintf_s(aux,"Hierro:%d        Oro:%d        Comida:%d",
			player.almacen.getHierro(),
			player.almacen.getOro(),
			player.almacen.getComida() );
		printxy(aux,0,0);
	glPopMatrix();
	*/
	
	//FORMA DEFINITIVA DE HACER LOS MENUS 
	
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(1,0.8,0);
			setFont("fuentes/Bitwise.ttf",25);		
			char aux[500];
			sprintf_s(aux,"Hierro: %d           Oro: %d          Comida: %d",
				mundo.jugador1.almacen.getHierro(),
				mundo.jugador1.almacen.getOro(),
				mundo.jugador1.almacen.getComida() );
			printxy(aux,60 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			printxy("AYUDA :: ESP",glutGet(GLUT_WINDOW_WIDTH)-200 , glutGet(GLUT_WINDOW_HEIGHT)-60);
				
			
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	
}

void Menus :: Timer (float t)
{
}

void Menus :: inicio ()
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(1,1,0);
			setFont("fuentes/cityburn.ttf",100);		
			printxy("QB EMPIRE",glutGet(GLUT_WINDOW_WIDTH)*1/4 , glutGet(GLUT_WINDOW_HEIGHT)*3/4);

	
		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);//200, 280
			printxy("PULSE LA TECLA -E- PARA EMPEZAR", glutGet(GLUT_WINDOW_WIDTH)*1/4, 280);

		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);//200,180
			printxy("PULSE LA TECLA -O- PARA OPCIONES",glutGet(GLUT_WINDOW_WIDTH)*1/4, 180);
	
		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);//210, 80
			printxy("PULSE LA TECLA -Esc- PARA SALIR",glutGet(GLUT_WINDOW_WIDTH)*1/4, 80);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);

}

void Menus :: game_over ()
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(1,0,0);
			setFont("fuentes/Bitwise.ttf",100);		
			printxy("GAME OVER", 580, 700);

	
		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("PRESS -Q- TO RESTART", 200, 280);
	
		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("PRESS -Esc- TO EXIT",210,180);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);


}

void Menus :: opciones ()
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(0.5,0.5,1);
			setFont("fuentes/LemonMilk.otf",50);
			printxy("MUSICA  - M - ", 650, 550);
	
		setTextColor(0.5,0.8,0);
			setFont("fuentes/LemonMilk.otf",50);
			printxy("EFECTOS  - K -", 650,400);

		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("VOLVER  - DEL -", 200,200);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);

}

void Menus :: you_win()
{
	
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(0,1,0);
			setFont("fuentes/Bitwise.ttf",100);		
			printxy("YOU WIN", 580, 700);

	
		setTextColor(0,1,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("PRESS -Q- TO RESTART", 200, 280);
	
		setTextColor(0,1,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("PRESS -Esc- TO EXIT",210,180);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);


}