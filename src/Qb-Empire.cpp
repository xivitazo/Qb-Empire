#include "Mundo.h"
#include "glut.h"



Mundo mundo;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouse(int button, int state, int x, int y);
void OnMousePas(int x, int y);




int main(int argc,char* argv[])
{ 	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glRenderMode(GL_SELECT);
	 
	GLuint selectBuffer[100];
	
	glSelectBuffer(100,selectBuffer);
	
	glutInitWindowSize(1280,720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Qb-Empire");

	//habilitar luces y definir perspectiva
	
	GLfloat lightpos[] = {-50.5, 100.0, 501.0, 100.0};
	
	
	

  glEnable(GL_LIGHT0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
	/*GLfloat white[] = {0.4f, 0.4f,0.4f, 0.5f};		
	GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f}; 
	GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
	GLfloat cyan[] = {0.1f, .4f, .4f, 0.5f};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	GLfloat shininess[] = {100};
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);*/
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	//glDepthFunc(GL_EQUAL);

	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	gluPerspective( 40.0, 1280/720.0f, 0.1, 300); 


	glutFullScreen();




	/*
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 15.f);
	*/
	mundo.Inicializa();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouse);

	
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	glInitNames();
	glPushName(0);
	
	mundo.Dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.Tecla(key);
	switch(key){
	case 27:	exit(1); break;
	/*case 'd':
		fogDensity *= 1.10;
		glFogf(GL_FOG_DENSITY, fogDensity);
		glutPostRedisplay();
		break;
	case 'D':
		fogDensity /= 1.10;
		glFogf(GL_FOG_DENSITY, fogDensity);
		glutPostRedisplay();
		break;*/
	}

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	mundo.Timer(0.025f);

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
	//printf ("%d\t%d\n", vx, vy);
//	mundo.Raton(button, state, screenToWorldCoords(vx,vy));
	int vp[4];
	glGetIntegerv(GL_VIEWPORT,vp);
	
	gluPickMatrix(x,y,1, 1, vp);
	int hits=glRenderMode(GL_RENDER);
	glReadBuffer(GL_SELECT);
	printf("%d", hits);



}