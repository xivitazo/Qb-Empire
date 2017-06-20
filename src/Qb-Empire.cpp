#include "Mundo.h"
#include "glut.h"



Mundo mundo;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void OnMouse(int button, int state, int x, int y);
void OnMousePas(int x, int y);
Vector screenToWorldCoords(int iX,int iY);

/*GLfloat angle = 0.0;

void cube (void) {
    glRotatef(angle, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(2);
}

void init (void) {
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();  
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    cube();
    glutSwapBuffers();
    angle ++;
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}*/


int main(int argc,char* argv[])
{ 
	/*glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A basic OpenGL Window");
    init ();
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;*/
	
	
	
	
	
	
	
	
	
	
	
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	
	glutInitWindowSize(1280,720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Qb-Empire");
	//glLighti(GL_LIGHT1,GL_QUADRATIC_ATTENUATION,GL_3D_COLOR_TEXTURE);

	//habilitar luces y definir perspectiva
	// glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);*/
	/*GLfloat lightpos[] = {.5, 1., 1., 0.};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);*/
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	
	/*GLfloat white[] = {0.4f, 0.4f,0.4f, 0.5f};		//GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};  GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
	GLfloat cyan[] = {0.1f, .4f, .4f, 0.5f};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	GLfloat shininess[] = {100};
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);*/
	//glShadeModel(GL_FLAT);
	

	gluPerspective( 40.0, 1280/720.0f, 0.1, 300);
	glutFullScreen();
	


	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouse);

	mundo.Inicializa();
		
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
	
	mundo.Dibuja();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.Tecla(key);
	if(key=='q')
		exit(1);


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
	printf ("%d\t%d\n", vx, vy);
	mundo.Raton(button, state, screenToWorldCoords(vx,vy));
}
Vector screenToWorldCoords(
  int iX,
  int iY
)
{
  GLdouble
    posX1,
    posY1,
    posZ1,
    posX2,
    posY2,
    posZ2,
    modelview[16],
    projection[16];
  GLint
    viewport[4];

  // Get matrices
  glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
  glGetDoublev(GL_PROJECTION_MATRIX, projection);
  glGetIntegerv(GL_VIEWPORT, viewport);
 
  // Create ray
  gluUnProject( iX, iY, 0, modelview, projection, viewport, &posX1, &posY1, &posZ1);  // Near plane
  gluUnProject( iX, iY, 1, modelview, projection, viewport, &posX2, &posY2, &posZ2);  // Far plane

 

  // Calculate the point where Z = 0
  float
    fT = posZ1 / (posZ2 - posZ1),
    fX = (posX1 + ((posX1 - posX2) * fT)),
    fY = posY1 + ((posY2 - posY1) * fT);

  return Vector(fX, fY);
}


