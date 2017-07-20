#include "Menus.h"

Menus::Menus()
{
}

Menus::~Menus(void)
{
}

void Menus :: inicializa () 
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		edificios = new Sprite ("imagenes/edificios.png",850, glutGet(GLUT_WINDOW_HEIGHT)-50, 30, 30);
		personajes = new Sprite ("imagenes/personajes.png", 995, glutGet(GLUT_WINDOW_HEIGHT)-50, 30, 30);
		disparos = new Sprite ("imagenes/disparos.png",1150, glutGet(GLUT_WINDOW_HEIGHT)-50, 30, 30);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void Menus :: seleccion (Type tipo, Mundo &mundo)
{
		
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
			char aux1[100], aux2[100], aux3[100], aux4[100], aux5[100], aux6[100];
			//sprintf(aux,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			sprintf_s(aux1,"SUBIR NIVEL -  (%d)",mundo.jugador1.nivel[AYUNTAMIENTO]);
			printxy(aux1, 50, 50);
			
			setTextColor(215.0f/255.0f, 45.0f/255.0f, 109.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",20);
			sprintf_s(aux2,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[ARQUERA]);
			sprintf_s(aux3,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[SOLDADO]);
			sprintf_s(aux4,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[CABALLERO]);
			sprintf_s(aux5,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[GUERRERO]);
			sprintf_s(aux6,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[GIGANTE]);
			printxy("ARQUERA", 500, 250);
			printxy("SOLDADO", 500, 200);
			printxy("CABALLERO", 500, 150);
			printxy("GUERRERO", 500, 100);
			printxy("GIGANTE", 500, 50);
			printxy(aux2, 900, 50);
			printxy(aux3, 900, 100);
			printxy(aux4, 900, 150);
			printxy(aux5, 900, 200);
			printxy(aux6, 900, 250);
			break;
		case F_ORO: 
			setTextColor(245.0f/255.0f,208.0f/255.0f,51.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxo[100];
			sprintf_s(auxo,"SUBIR NIVEL -  (%d)", mundo.jugador1.nivel[F_ORO]);
			printxy(auxo, 50, 50);		// glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)
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
			char aux[100];
			sprintf_s(aux,"SUBIR NIVEL -  (%d)  -  TECLA  'X'", mundo.jugador1.nivel[CUARTEL]);
			printxy("CUARTEL", 50, 100);
			printxy(aux, 50, 50);
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
			sprintf_s(aux1," CONSTRUIR FABRICA DE ORO  -  PULSAR   E   -");	
			sprintf_s(aux2," CONSTRUIR FABRICA DE HIERRO  -  PULSAR   W  -");	
			sprintf_s(aux3," CONSTRUIR FABRICA DE COMIDA  -  PULSAR   Q  -");
			sprintf_s(aux4," CONSTRUIR UN CUARTEL  -  PULSAR  A  -");
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

void Menus :: superior (Mundo &mundo, float tiempo)
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();


		setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",15);		
			char aux[500],aux1[500];
			int segundos=(tiempo-(int)tiempo)*60; 
			sprintf_s(aux,"Comida: %d            Hierro: %d           Oro: %d                              %d : %d",
				mundo.jugador1.almacen.getComida(),
				mundo.jugador1.almacen.getHierro(),
				mundo.jugador1.almacen.getOro(),
				(int)tiempo,
				segundos);
			sprintf_s(aux1,"%d / %d                %d / %d                %d",
				mundo.jugador1.numero_actual[EDIFICIOS],
				mundo.jugador1.max_Type[EDIFICIOS],
				mundo.jugador1.numero_actual[COMBATIENTES],
				mundo.jugador1.max_Type[COMBATIENTES],
				mundo.numero);
			printxy(aux,60 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			printxy(aux1,880 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			
			glPushMatrix();
			//glRotatef(90, 1.0, 0.0, 0.0);
			//glTranslatef(80, -80, -100);
			//glTranslatef(0, 0, -1);
			personajes->draw();
			glPopMatrix();
			glPushMatrix();
			//glTranslatef(30, 0, 0);
			edificios->draw();
			glPopMatrix();
			glPushMatrix();
			//glTranslatef(60, 0, 0);
			disparos->draw();
			glPopMatrix();

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

		setTextColor(255/255.0f,128/255.0f,0);
			setFont("fuentes/cityburn.ttf",100);		
			printxy("QB EMPIRE",glutGet(GLUT_WINDOW_WIDTH)*0.285 , glutGet(GLUT_WINDOW_HEIGHT)*3/4);

	
		setTextColor(76/255.0f,153/255.0f,0);
			setFont("fuentes/LemonMilk.otf",20);//200, 280
			printxy("PULSE LA TECLA -E- PARA EMPEZAR", glutGet(GLUT_WINDOW_WIDTH)*0.32, 180);

		
			setFont("fuentes/LemonMilk.otf",20);//200,180
			printxy("PULSE LA TECLA -O- PARA OPCIONES",glutGet(GLUT_WINDOW_WIDTH)*0.32, 120);
	
		
			setFont("fuentes/LemonMilk.otf",20);//210, 80
			printxy("PULSE LA TECLA -Esc- PARA SALIR",glutGet(GLUT_WINDOW_WIDTH)*0.32, 60);
	
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

		setTextColor(255/255.0f,0,0);
			setFont("fuentes/Bitwise.ttf",100);		
			printxy("GAME OVER", glutGet(GLUT_WINDOW_WIDTH)*0.270 , glutGet(GLUT_WINDOW_HEIGHT)*3/4);

			setFont("fuentes/LemonMilk.otf",20);
			printxy("PRESS -Q- TO RESTART",  glutGet(GLUT_WINDOW_WIDTH)*0.40, 180);

			setFont("fuentes/LemonMilk.otf",20);
			printxy("PRESS -Esc- TO EXIT",glutGet(GLUT_WINDOW_WIDTH)*0.40, 120);
	
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
			printxy("YOU WIN",glutGet(GLUT_WINDOW_WIDTH)*0.285 , glutGet(GLUT_WINDOW_HEIGHT)*3/4);

	
		setTextColor(0,1,0);
			setFont("fuentes/LemonMilk.otf",20);
			printxy("PRESS -Q- TO RESTART",glutGet(GLUT_WINDOW_WIDTH)*0.40, 180);
	
		setTextColor(0,1,0);
			setFont("fuentes/LemonMilk.otf",20);
			printxy("PRESS -Esc- TO EXIT",glutGet(GLUT_WINDOW_WIDTH)*0.40, 120);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);


}
