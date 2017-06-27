#include "Menus.h"


Menus::Menus(void)
{
}


Menus::~Menus(void)
{
}

void Menus :: seleccion (Type tipo)
{
	if(tipo==AYUNTAMIENTO){

	}

}

void Menus :: construccion()
{

}

void Menus :: superior(Mundo &mundo)
{/*
	Vector3D pos_o(112.5,-175,50);
	Vector3D miro_o(112.5,37.5,0);
	Vector3D seniala=(miro_o-pos_o).unitario();
	Vector3D amiro_ojo(mundo.amiro_x, mundo.amiro_y, mundo.amiro_z);
	Vector3D aojo(mundo.ax_ojo, mundo.ay_ojo, mundo.az_ojo);

	Vector3D pos(aojo-(aojo-amiro_ojo).unitario()*5);
	Vector3D sen=(amiro_ojo-pos).unitario();
	//Vector3D giro(seniala^pos);
	//Vector3D giro(pos^sen);
	Vector3D giro(pos^seniala);
	float angulo=cos(pos*seniala/5);
	//float angulo=cos(pos*sen/5);

	*/
	/*
	Vector3D amiro_ojo(mundo.amiro_x, mundo.amiro_y, mundo.amiro_z);
	Vector3D aojo(mundo.ax_ojo, mundo.ay_ojo, mundo.az_ojo);
	Vector3D pos(aojo-(aojo-amiro_ojo).unitario()*5);
	Vector3D sen=(amiro_ojo-pos).unitario();
	Vector3D giro(pos^sen);
	float angulo=cos (pos*sen);
	glPushMatrix();
		setTextColor(1,1,0);
		glTranslatef(pos.vx, pos.vy, pos.vz );
		//glTranslatef(pos.vx, pos.vy, pos.vz);
		//glRotatef(angulo*180/3.14159265358979,giro.vx,giro.vy,giro.vz);
		glColor3ub(255, 200, 0);
		glutSolidIcosahedron();
		setFont("fuentes/Bitwise.ttf",100);		
		printxy("ESTE SERA EL MENU SUPERIOR", 50, 300);
	glPopMatrix();
	*/
	glPushMatrix();
		GLdouble x,y,z,modelview[16],proyeccion[16];
		GLint viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX,modelview);//Coges la matriz Modelview
		glGetDoublev(GL_PROJECTION_MATRIX,proyeccion);//Coges la matriz proyeccion
		glGetIntegerv(GL_VIEWPORT,viewport);//Coges el punto de vista
		gluUnProject(0, 700,1,modelview,proyeccion,viewport,&x,&y,&z);
		glTranslatef(x,y,z);
		setTextColor(1,0.8,0);
		//glMatrixMode(GL_PROJECTION);
		//gluPerspective( 40.0, 1280/720.0f, 0.1, 300);  
		//glTranslatef(pos.vx, pos.vy, pos.vz);
		//glRotatef(angulo*180/3.14159265358979,giro.vx,giro.vy,giro.vz);
		//glColor3ub(255, 200, 0);
		setFont("fuentes/Bitwise.ttf",20);		
		printxy("Jugador1\tHierro:%f\t Oro:%f\t, Comida:%f",0,0);
		//glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}

void Menus :: Timer (float t)
{
}