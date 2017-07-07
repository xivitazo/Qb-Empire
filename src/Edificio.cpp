#include "Edificio.h"
#include <math.h>


Edificio::Edificio(unsigned int v, unsigned int _altura, Color _color, Planta planta, Vector _superficie):
	Objeto(_altura, _color, planta, _superficie)
{
	rango_visibilidad=20;
	vida_max=v;
	vida=vida_max;
}

Edificio :: Edificio (const Edificio* copia)
{
}

Edificio::~Edificio(void)
{
}

void Edificio :: setTipo (Type tipo)
{
	this->tipo=tipo;
}

void Edificio :: Timer (float t)
{
	color_vida();
}

void Edificio :: Dibuja (Color equipo)
{
}

void Edificio :: Tecla ()
{
}

void Edificio :: casita (Vector posicion, Color tejado, Color pared, Vector dimension, int altura)
{
	glPushMatrix();
	glutWireCube(0.001); 
	
	//Esta gilipollez mantiene las luces en su sitio, no sé muy bien cómo ni porqué... ha sido prueba y error
	//es un cubo ínfimo que mantiene las luces encendidas por la manera en la que se dibuja (usando glut), pues
	// usando solo los glvertex la luz por defecto se desactiva a no ser que dibujemos con una matriz
	//Lo cual no he podido averiguar cómo se hace por falta de apuntes
	glTranslatef(posicion.vx, posicion.vy, 0);
	dimension=dimension/2;
	
	//Existe distinción entre el comando GL_QUADS y el GL_POLYGON.
	//AL parecer se renderiza mucho más rápido y ligero el GL_QUADS
	//Pero por motivos que desconozco no es capaz de dibujarme los tejados
	//por lo que uso polygon para ellos y quads para los planos restantes

	//Pared eje X
	glBegin(GL_QUADS);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(-dimension.vx,-dimension.vy,0);
		glVertex3f(-dimension.vx, -dimension.vy,(float)altura);
		glVertex3f(dimension.vx, -dimension.vy, (float)altura);	
		glVertex3f(dimension.vx, -dimension.vy, 0);
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(pared.getRed()-30, pared.getGreen()-30, pared.getBlue()-19);
		glVertex3f(-dimension.vx,-dimension.vy,0);
		glVertex3f(-dimension.vx, -dimension.vy,(float)altura);
		glVertex3f(dimension.vx, -dimension.vy, (float)altura);	
		glVertex3f(dimension.vx, -dimension.vy, 0);
		//glVertex3f(-dimension.vx,-dimension.vy,0);
	glEnd();
	//Pared Eje Y
	glBegin(GL_QUADS);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(-dimension.vx,-dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(-dimension.vx,-dimension.vy,(float)altura);
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(pared.getRed()-30, pared.getGreen()-30, pared.getBlue()-19);
		glVertex3f(-dimension.vx,-dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(-dimension.vx,-dimension.vy,(float)altura);
	glEnd();
	//Pared Eje XFondo
	glBegin(GL_QUADS);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(-dimension.vx,dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,dimension.vy,0);
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(pared.getRed()-30, pared.getGreen()-30, pared.getBlue()-19);
		glVertex3f(-dimension.vx,dimension.vy,0);
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,dimension.vy,0);
	glEnd();
	//Pared Eje YFondo
	glBegin(GL_QUADS);
		glColor3ub(pared.getRed(), pared.getGreen(), pared.getBlue());
		glVertex3f(dimension.vx,dimension.vy,0);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,-dimension.vy,0);
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(pared.getRed()-30, pared.getGreen()-30, pared.getBlue()-19);
		glVertex3f(dimension.vx,dimension.vy,0);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);	
		glVertex3f(dimension.vx,-dimension.vy,0);
	glEnd();
	// Techo Eje X
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(-dimension.vx, -dimension.vy,(float)altura);
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);	
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(0,0,0);
		glVertex3f(-dimension.vx, -dimension.vy,(float)altura);
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);	
	glEnd();
	//Techo Eje y
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(-dimension.vx, dimension.vy,(float)altura);
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(-dimension.vx,-dimension.vy,(float)altura);	
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(0,0,0);
		glVertex3f(-dimension.vx, dimension.vy,(float)altura);
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(-dimension.vx,-dimension.vy,(float)altura);	
	glEnd();
	//Techo Eje Xfondo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(0,0,0);
		glVertex3f(-dimension.vx,dimension.vy,(float)altura);	
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	//Techo Eje YFondo
	glBegin(GL_POLYGON);
		glColor3ub(tejado.getRed(), tejado.getGreen(), tejado.getBlue());
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);		
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	glBegin(GL_LINES);
		glColor3ub(0,0,0);
		glVertex3f(dimension.vx,-dimension.vy,(float)altura);		
		glVertex3f(0,0,(float)altura+3.0f);
		glVertex3f(dimension.vx,dimension.vy,(float)altura);	
	glEnd();
	glLineWidth(0.4f);
	glPopMatrix();
	
}

void Edificio :: color_vida()
{
	color.set(color.getRed()*(vida/vida_max),color.getGreen()*(vida/vida_max),color.getBlue()*(vida/vida_max));
}

bool Edificio :: poderGenerar ()
{
	return true;
}

void Edificio :: subirNivel()
{
}