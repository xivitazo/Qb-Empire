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
			printxy("SUBIR NIVEL", 50, 50);
			sprintf_s(aux1,"(%d)  ORO: %d",mundo.jugador1.nivel[AYUNTAMIENTO], mundo.jugador1.coste_nivel[AYUNTAMIENTO]);
			printxy(aux1, 300, 50);
			setTextColor(1,1,1);
			printxy("Q", 600, 50);
			//printxy("Z", 450, 50);
			
			setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",15);

			printxy("SOLDADO", 700, 250);
			printxy("SUBIR NIVEL", 850, 250);
			sprintf_s(aux2,"(%d)", mundo.jugador1.nivel[LUCHADOR+SOLDADO]);
			printxy("W", 1100, 250);
			printxy(aux2, 1000, 250);

			printxy("ARQUERA", 700, 200);
			printxy("SUBIR NIVEL", 850, 200);
			sprintf_s(aux3,"(%d)", mundo.jugador1.nivel[LUCHADOR+ARQUERA]);
			printxy("E", 1100, 200);
			printxy(aux3, 1000, 200);

			printxy("CABALLERO", 700, 150);
			printxy("SUBIR NIVEL", 850, 150);
			sprintf_s(aux4,"(%d)", mundo.jugador1.nivel[LUCHADOR+CABALLERO]);
			printxy("R", 1100, 150);
			printxy(aux4, 1000, 150);

			printxy("GUERRERO", 700, 100);
			printxy("SUBIR NIVEL", 850, 100);
			sprintf_s(aux5,"(%d)", mundo.jugador1.nivel[LUCHADOR+GUERRERO]);
			printxy("T", 1100, 100);
			printxy(aux5, 1000, 100);

			printxy("GIGANTE", 700, 50);
			printxy("SUBIR NIVEL", 850, 50);
			sprintf_s(aux6,"(%d)", mundo.jugador1.nivel[LUCHADOR+GIGANTE]);
			printxy("Y", 1100, 50);
			printxy(aux6, 1000, 50);			
			break;
		case F_ORO: 
			setTextColor(245.0f/255.0f,208.0f/255.0f,51.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxo[100]/*, auxh2[100]*/;
			sprintf_s(auxo,"SUBIR NIVEL   (%d)   ORO: %d                 Q", mundo.jugador1.nivel[F_ORO], mundo.jugador1.coste_nivel[F_ORO]);
			//sprintf_s(auxh2,"DESTRUIR      (%d)   RECUPERAS: %d HIERRO      Q'", mundo.jugador1.coste[F_COMIDA],mundo.jugador1.coste[F_COMIDA].getHierro() );
			//printxy(auxh2, 50, 50);
			printxy(auxo, 50, 100);		// glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)
			break;
		case F_HIERRO:
			setTextColor(157/255.0f,161/255.0f,170/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxh[100]/*, auxh3[100]*/;
			sprintf_s(auxh,"SUBIR NIVEL -  (%d)   -  TECLA  'Q'", mundo.jugador1.nivel[F_HIERRO]);
			//sprintf_s(auxh3,"DESTRUIR       (%d)     TECLA  'Q'", mundo.jugador1.coste_nivel[F_COMIDA]);
			//printxy(auxh3, 50, 50);
			printxy(auxh, 50, 100);
			break;
		case F_COMIDA:
			setTextColor(234.0f/255.0f, 137.0f/255.0f, 154.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxc[100]/*, auxc3[100]*/;
			sprintf_s(auxc,"SUBIR NIVEL  -  (%d)   -  TECLA  'Q'",mundo.jugador1.nivel[F_COMIDA]);
			//sprintf_s(auxc3,"DESTRUIR        (%d)     TECLA  'Q'", mundo.jugador1.coste_nivel[F_COMIDA]);
		//	printxy(auxc3, 50, 50);
			printxy(auxc, 50, 100);
			break;
		case CUARTEL:
			setTextColor(139.0f/255.0f,69.0f/255.0f,19.0f/255.0f);
			setFont("fuentes/LemonMilk.otf",30);		
			char auxc1[100]/*, auxc2[100]*/;
			sprintf_s(auxc1,"SUBIR NIVEL     (%d)     TECLA  'Q'", mundo.jugador1.nivel[CUARTEL]);
			//sprintf_s(auxc2,"DESTRUIR        (%d)     TECLA  'Q'", mundo.jugador1.coste_nivel[CUARTEL]);
			printxy("CUARTEL", 50, 150);
			//printxy(auxc2, 50, 50);
			printxy(auxc1, 50, 100);


			setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",20);
			printxy("GENERAR :", 1000,300);

			setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",15);
			printxy("SOLDADO", 1000, 250);
			printxy("TECLA  'W'", 1150, 250);
			printxy("ARQUERA", 1000, 200);
			printxy("TECLA  'E'", 1150, 200);
			printxy("CABALLERO", 1000, 150);
			printxy("TECLA  'R'", 1150, 150);
			printxy("GUERRERO", 1000, 100);
			printxy("TECLA  'T'", 1150, 100);
			printxy("GIGANTE", 1000, 50);
			printxy("TECLA  'Y'", 1150, 50);

			setTextColor(1,1,1);
			setFont("fuentes/LemonMilk.otf",15);		
			printxy("COLA PARA GENERAR: ",700, 150);

			setTextColor(1,1,1);
			setFont("fuentes/LemonMilk.otf",12);	
			Luchadores *cola=mundo.jugador1.getCola();
			int numero=1;
			int linea=0;
			for(int i=0; i<mundo.jugador1.getNumCola(); i++)
			{
				if(cola[i]==cola[i+1])
					numero++;
				else
				{
					char aux[100];
					sprintf_s(aux," x%d",numero);
					switch(cola[i])
					{
					case SOLDADO: 
						printxy("SOLDADO ", 705 , 120-20*linea);
						break;
					case ARQUERA:
						printxy("ARQUERA ", 705 , 120-20*linea);
						break;
					case CABALLERO:
						printxy("CABALLERO", 705 ,120-20*linea);
						break;
					case GUERRERO:
						printxy("GUERRERO", 705 , 120-20*linea);
						break;
					case GIGANTE:
						printxy("GIGANTE", 705 , 120-20*linea);
						break;
					}
					printxy(aux,805 , 120-20*linea);
					numero=1;
					linea++;
				}
				
			}
			break;
		}
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	if(tipo==CUARTEL)
	{
		glPushMatrix();
		glTranslatef(mundo.jugador1.getDestino().vx,mundo.jugador1.getDestino().vy,0);
		bandera(mundo.jugador1.getEquipo());
		glPopMatrix();
	}
		

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
			printxy("GRANJA", 500, 200);
			printxy("Q", 500, 150);
			printxy("MINA HIERRO", 700, 200);
			printxy("W", 700, 150);
			printxy("MINA ORO", 900, 200);
			printxy("E", 900, 150);
			printxy("CUARTEL", 1100, 200);
			printxy("R", 1100, 150);

			
			setFont("fuentes/LemonMilk.otf",15);
			sprintf_s(aux1,"%d HIERRO", mundo.jugador1.coste[0].getHierro());
			printxy(aux1,500, 100);
			sprintf_s(aux2,"%d HIERRO", mundo.jugador1.coste[0].getHierro());
			printxy(aux2,700, 100);
			sprintf_s(aux3,"%d HIERRO", mundo.jugador1.coste[0].getHierro());
			printxy(aux3,900, 100);		
			sprintf_s(aux4,"%d HIERRO", mundo.jugador1.coste[0].getHierro());
			printxy(aux4,1100, 100);

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
			char aux1[500],aux2[500], aux3[500];
			int segundos=(tiempo-(int)tiempo)*60; 

			sprintf_s(aux1,"Comida: %d            Hierro: %d           Oro: %d",
				mundo.jugador1.almacen.getComida(),
				mundo.jugador1.almacen.getHierro(),
				mundo.jugador1.almacen.getOro());
				
			sprintf_s(aux2,"%d : %d",
			(int)tiempo,
				segundos);

			sprintf_s(aux3,"%d / %d                %d / %d                %d",
				mundo.jugador1.numero_actual[EDIFICIOS],
				mundo.jugador1.max_Type[EDIFICIOS],
				mundo.jugador1.numero_actual[COMBATIENTES],
				mundo.jugador1.max_Type[COMBATIENTES],
				mundo.numero);
			printxy(aux1,60 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			printxy(aux2,670 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			printxy(aux3,880 , glutGet(GLUT_WINDOW_HEIGHT)-60);
			
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
			setFont("fuentes/LemonMilk.otf",30);
			printxy("MUSICA      TECLA  M", 850, 600);
	
		setTextColor(0.5,0.8,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("EFECTOS     TECLA  K", 850,540);

		setTextColor(1,0,0);
			setFont("fuentes/LemonMilk.otf",30);
			printxy("VOLVER  - DEL -", 150,540);
	
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

void Menus :: creacion()
{
	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		setTextColor(1,0.8,0);
			setFont("fuentes/LemonMilk.otf",25);
			printxy("CLICK IZQUIERDO EN EL LUGAR DONDE QUIERAS GENERAR TU EDIFICIO", 40, 100);
	
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

	glEnable(GL_DEPTH_TEST);

}

void Menus :: bandera(Color& equipo)
{
	glPushMatrix();
	glColor3ub(102,51,0);
	glutSolidSphere(1,5,5);
	glColor3ub(0,0,0);
	glLineWidth(5.0f);
	glBegin(GL_LINE);
		glVertex3f(0,0,0);
		glVertex3f(0,0,4);
	glEnd();
	glColor3ub(equipo.getRed(),equipo.getGreen(),equipo.getBlue());
	glBegin(GL_POLYGON);
		glVertex3f(0,0,3);
		glVertex3f(0,0,4);
		glVertex3f(2,2,3.5);
	glEnd();
	glPopMatrix();
}