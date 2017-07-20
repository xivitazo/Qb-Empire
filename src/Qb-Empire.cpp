#include "Coordinador.h"
#include "glut.h"

#define BUFSIZE 512
static float  x=-87.5, y=-50, z=25, t=0.5;
Coordinador coordinator;
Vector inicial;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouse(int button, int state, int x, int y);
void OnMousePas(int x, int y);
int* click (int x, int y, int err_x, int err_y);
Color cielo;
/*
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective( 40.0, 1280/720.0f, 0.1, 300);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
}
*/
int main(int argc,char* argv[])
{ 	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1280,720);
	//glutInitWindowSize(1920,1080);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Qb-Empire");

	//habilitar luces y definir perspectiva	
	GLfloat lightpos[] = {-50.5, 100.0, 501.0, 100.0};
	
	
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	glEnable(GL_LIGHT0);
//	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	//glMatrixMode(GL_MODELVIEW);	
	//glLoadIdentity();				//	MH no las pone... ser� por algo
	//glDepthFunc(GL_EQUAL);

	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	gluPerspective( 40.0, 1280/720.0f, 0.1, 400);  
	//gluPerspective( 40.0, 1920/1080.f, 0.1, 300);
	//IDEA
	//Si usamos full Screen, flag=1. 
	//Si no usamos full screen, flag=0;
	//glutFullScreen();

	coordinator.Inicializa();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);	//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouse);
	glutMotionFunc(OnMousePas);
	//glutReshapeFunc(reshape);

	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	coordinator.dibujaCielo();
	//GLfloat position[] = { -87.5, -50, 25, 0.5 };
	//Definimos la iluminaci�n
	GLfloat position[] = { -15, 0, -5, 0.8 };
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv (GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
   
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
  

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	coordinator.Dibuja();

	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	coordinator.Tecla(key);
	switch(key){	
	case 27: exit(1); break;
	case '5': x+=1; break;
	case '6': x-=1; break;
	case '7': y+=1; break;
	case '8': y-=1;break;
	case '9': z+=0.1; break;
	case '0': z-=0.1; break;
	}
	//printf("%f\t%f\t%f\t%f\n", x, y, z, t);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
	coordinator.Timer(0.025f);

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int x, int y)
{
	/*
	GLdouble x,y,z,modelview[16],proyeccion[16];
	GLint viewport[4];
	printf("%d\t%d\t%d\t%d\n", button ,state, vx ,vy);
	glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
	glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
	glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
	gluUnProject(vx,vy,1,modelview,proyeccion,viewport,&x,&y,&z);//En x y z se guardan los valores de las coordenadas respecto del mundo
	mundo.Raton(button,state,(int)x,(int)y);
	printf("%lf\t%lf\t%lf\n", x,y,z);
	*/
	

	if ( state != GLUT_DOWN)
	{
		inicial=0;
		return;
	}
	inicial=Vector(x,y);
	int *nombres;
	int n;
	nombres=click(x,y,1,1);
	for(n=0;n<100&&nombres[n]!=0;n++);
	coordinator.Mouse(nombres,n,button);
	

}

void OnMousePas(int x, int y)
{
	Vector centro_cuadrado, err;
	int* nombres;
	int n;
	centro_cuadrado=((Vector(x,y)-inicial)/2)+inicial;
	err=(Vector(x,y)-inicial)/2;
	if(abs(err.vx)<=0.1f)
		err.vx=1;
	if(abs(err.vy)<=0.1f)
		err.vy=1;
	nombres=click(centro_cuadrado.vx,centro_cuadrado.vy,abs(err.vx),abs(err.vy));
	for(n=0;n<100&&nombres[n]!=0;n++);

	printf("%d\t%d\n",x,y);
	coordinator.Mouse(nombres,n,0);
	
	
}

int* click (int x, int y, int err_x, int err_y)
{
		//Empezamos con el Rat�n
	GLuint selectBuffer[BUFSIZE];
	GLint hits;
	GLint vp[4];
	float width=1280, height=720;
	//float width=1920, height=1080;

	glSelectBuffer(BUFSIZE,selectBuffer);

	(void) glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(1000);

	//Para definir el punto de vista
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT,vp);
	gluPickMatrix((GLdouble)x,(GLdouble)(height-y),err_x, err_y, vp);
	gluPerspective( 40.0, width/height, 0.1, 400); 
	//int x1=glutGet(GLUT_WINDOW_WIDTH);
	//int y1=glutGet(GLUT_WINDOW_HEIGHT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//glPopName();
	coordinator.Dibuja();

	glFlush();

	//Vuelvo a colocar la vista original
	//Aplico un RESHAPE. 
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective( 40.0, 1280/720.0f, 0.1, 300);
	gluPerspective( 40.0, width/height, 0.1, 400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	hits=glRenderMode(GL_RENDER);

	cout<<"Hits: "<<hits<<endl;

	GLuint hitnames[BUFSIZE];
	unsigned int hi = 0;
	GLuint *bufp = selectBuffer;
	GLuint name, numnames, z1, z2;
	int nombre[100];
	unsigned k=0;

	// [0x6]
	for(unsigned int j = 0; j < hits && *bufp<BUFSIZE; j++)
	{
		numnames = *bufp++;
		z1 = *bufp++;
		z2 = *bufp++;
		while(numnames--)
		{
			name = *bufp++;
			hitnames[hi++] = name;
			if(hitnames[hi-1]>=0 && hitnames[hi-1]<10000)
			{
				//Asumo que no daremos m�s de 1000 nombres. me parecen suficientes . tenemos el
				//problema de qe se cuele una direcci�n de memoria entre el 0 y el 1000... pero como es necesario leer todo el buffer para encontrar d�ndo
				//ha puesto el nombre el buffer, es la manera m�s sencilla que se me ocurre con un margen de error muy peque�o
				if(name!=99)
				{
					nombre[k++]=name;
					cout<<"Nombre"<<j<<": "<<nombre[k-1]<<endl;
				}
			}
		}
	}
	nombre[k]=0;
	return nombre;
}