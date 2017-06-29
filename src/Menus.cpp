#include "Menus.h"


Menus::Menus()
{
}


Menus::~Menus(void)
{
}

void Menus :: seleccion (Type tipo, Lista_de &player)
{
	if(tipo==AYUNTAMIENTO){
	glPushMatrix();
		GLdouble x,y,z,modelview[16],proyeccion[16];
		GLint viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
		glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
		glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
		gluUnProject(0, 100,1,modelview,proyeccion,viewport,&x,&y,&z);
		glTranslatef(x,y,z);
		setTextColor(0.5,0.8,0.5);
		setFont("fuentes/Bitwise.ttf",10);		
		char aux[500];
		sprintf(aux,"SUBIR NIVEL -  (%d)",player.nivel[AYUNTAMIENTO]);
		printxy(aux,0,0);
	glPopMatrix();
	}
	if(tipo==F_ORO){
		glPushMatrix();
		GLdouble x,y,z,modelview[16],proyeccion[16];
		GLint viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
		glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
		glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
		gluUnProject(0, 100,1,modelview,proyeccion,viewport,&x,&y,&z);
		glTranslatef(x,y,z);
		setTextColor(1,0.8,0);
		setFont("fuentes/Bitwise.ttf",20);		
		char aux[500];
		sprintf(aux,"SUBIR NIVEL -  (%d)", player.nivel[F_ORO]);
		printxy(aux,0,0);
	glPopMatrix();
	}
}

void Menus :: construccion(Lista_de &player)
{
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
		sprintf(aux,"SUBIR NIVEL -  (%d)", player.nivel[F_ORO]);
		printxy(aux,0,0);
	glPopMatrix();
}

void Menus :: superior(Lista_de &player)
{
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
	
		
}

void Menus :: Timer (float t)
{
}