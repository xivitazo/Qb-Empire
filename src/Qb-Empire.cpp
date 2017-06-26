#include "Coordinador.h"
#include "glut.h"

static float  x=-87.5, y=-50, z=25, t=0.5;
Coordinador coordinator;


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
	
	glutInitWindowSize(1280,720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Qb-Empire");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
//	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	//glMatrixMode(GL_MODELVIEW);	
	//glLoadIdentity();				//	MH no las pone... será por algo
	//glDepthFunc(GL_EQUAL);

	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	
	gluPerspective( 40.0, 1280/720.0f, 0.1, 300);  
//	glutFullScreen();

	coordinator.Inicializa();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);	//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
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
	//GLfloat position[] = { -87.5, -50, 25, 0.5 };
	//Definimos la iluminación
	GLfloat position[] = { -87.5, -50, 25, 0.5 };
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
	//poner aqui el código de teclado
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
//poner aqui el código de animacion
	coordinator.Timer(0.025f);

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int vx, int vy)
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
}


