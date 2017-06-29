#include "Mundo.h"



Mundo::Mundo():jugador1(Vector(8, 37.5),Color(0, 0, 205)),
			jugador2 (Vector(217, 37.5),Color(179,36,40))
{
}

void Mundo::Dibuja()
{
	Menus :: superior(this->mundo);
	gluLookAt(ax_ojo, ay_ojo, az_ojo,  // posicion del ojo
		amiro_x, amiro_y, amiro_z,      // hacia que punto mira  (0,0,0) 
			0.0, 0, 1.0);      // definimos hacia arriba (eje Z)    

	//aqui es donde hay que poner el codigo de dibujo

	
	//dibujo del suelo
	map.Dibuja();
	jugador1.Dibuja();
	jugador2.Dibuja();
	
	
	//printf ("%d\t%d\n", jugador1.getNumero(), jugador2.getNumero());
	//printf("Comida:%d\tHierro:%d\tOro:%d\n", jugador1.getAlmacen().getComida(),jugador1.getAlmacen().getHierro(), jugador1.getAlmacen().getOro()); 
	//printf("%d\n", jugador1.getNivel(AYUNTAMIENTO));
	//printf("%d\n", jugador1.getMax(COMBATIENTES));
	//printf("%d\n", jugador1.getNumero());
	
	//Tenemos posibles coordenadas del mapa.
	/*printf("Posicion Ojo x:  %f",x_ojo);
	printf("\n");
	printf("Posicion Ojo y: %f",y_ojo);
	printf("\n");
	printf("Posicion Ojo z: %f",z_ojo);
	printf("\n");
	printf("Miro x:  %f", miro_x);
	printf("\n");
	printf("Miro y: %f", miro_y);
	printf("\n");
	printf("Miro z: %f", miro_z);
	printf("\n");*/
  
}

void Mundo::Timer(float t)
{
	for(int n=0; n<jugador1.getNumero();n++)
	{
		for(int i=0; i<jugador2.getNumero();i++)
			Interaccion :: Rebote(jugador1.getPosN(n),jugador2.getPosN(i));
	}
	jugador1.Timer(t);
	jugador2.Timer(t);
	for (int n=0; n<jugador1.getNumero(); n++)
	for(int i=0; i<jugador2.getNumero(); i++)
		{
			if (Interaccion ::Distancia (jugador1.getPosN(n), jugador2.getPosN(n))<jugador1.getPosN(n).getRango())
				jugador1.getPosN(n).Atacar(jugador2.getLista());
			if (Interaccion ::Distancia (jugador1.getPosN(n), jugador2.getPosN(n))<jugador2.getPosN(i).getRango())
				jugador2.getPosN(i).Atacar(jugador1.getLista());
		}
	movimientoCamara(t);

	//Para el sonido del disparo
	//ETSIDI::play("sonidos/impacto.wav");
	
	
}

void Mundo::Inicializa()
{
	Inicializa_vista();

	map.inicializa();

}

void Mundo::Tecla(unsigned char key)
{
	switch(key)
	{
	case 'a': x_ojo+=1; break;
	case 's': y_ojo+=1; break;
	case 'd': z_ojo+=1; break;
	case 'z': x_ojo-=1; break;
	case 'x': y_ojo-=1; break;
	case 'c': z_ojo-=1; break;
	case 'f': miro_x+=1; break;
	case 'g': miro_y+=1; break;
	case 'h': miro_z+=1; break;
	case 'v': miro_x-=1; break;
	case 'b': miro_y-=1; break;
	case 'n': miro_z-=1; break;
	case '1': setPerspectiva(-37.5,37.5,50,25,37.5,0); break; //Vista Poblado
	case '2': setPerspectiva(112.2,-28.5,60,112.5,27.5,0); break; //Vista Batalla
	case '3': setPerspectiva(-23,-47,50,50,25,0); break; //Vista General
	case '4': setPerspectiva(150-23,-47,50,175,25,0); break; //Vista Enemigo
	case 'p': jugador1.Agregar(CABALLERO, Vector(200,50)); break;
	case 'i': jugador1.Agregar(CUARTEL, Vector(10,20)); break;
	case 'o': jugador1.Agregar(F_ORO, Vector(50,50)); break;
	case 'u': jugador1.Agregar(F_COMIDA, Vector(75,68));  break;
	case 'y': jugador1.Agregar(F_HIERRO, Vector(30,68));  break;
	case 'q': jugador2.Agregar(CABALLERO, Vector(0,0)); break;
	case 'k': jugador2.Agregar(CUARTEL, Vector(225-10,75-20)); break;
	case 'l': jugador2.Agregar(F_ORO, Vector(225-50,75-50)); break;
	case 'j': jugador2.Agregar(F_COMIDA, Vector(225-75,75-68));  break;
	case 'm': jugador2.Agregar(F_HIERRO, Vector(225-30,75-68));  break;
	case '+': jugador1.subirNivel(AYUNTAMIENTO);  break;

	}

}

void Mundo::Raton(int button, int state, Vector pos)
{
	//printf("%f\t%f\n", pos.vx, pos.vy);
}

void Mundo:: RatonPasivo(int x, int y)
{

}

void Mundo:: setPerspectiva(float ojo_a, float ojo_b, float ojo_c, float miro_a, float miro_b, float miro_c)
{
	x_ojo=ojo_a;
	y_ojo=ojo_b;
	z_ojo=ojo_c;
	miro_x=miro_a;
	miro_y=miro_b;
	miro_z=miro_c;
}

void Mundo :: movimientoCamara (float t)
{
	Vector3D destino(x_ojo,y_ojo,z_ojo);
	Vector3D posicion (ax_ojo, ay_ojo, az_ojo);
	Vector3D destino_miro(miro_x, miro_y, miro_z);
	Vector3D posicion_miro(amiro_x, amiro_y, amiro_z);
	Vector3D velocidad;
	if((destino-posicion).modulo()>10)
	{
		velocidad=(destino-posicion).unitario()*100;
		//printf("velocidad: %f %f %f\n",velocidad.vx, velocidad.vy, velocidad.vz);
		
	}
	else if ((destino-posicion).modulo()<=10)
			velocidad = (destino-posicion)*10;
	posicion=posicion + velocidad*t;
	if((destino_miro-posicion_miro).modulo()>1)
	{
		velocidad=(destino_miro-posicion_miro).unitario()*10;
	}
	else if ((destino_miro-posicion_miro).modulo()<1)
			velocidad = (destino_miro-posicion_miro)*10;
	posicion_miro=posicion_miro+velocidad*t*5;
		amiro_x=posicion_miro.vx;
		amiro_y=posicion_miro.vy;
		amiro_z=posicion_miro.vz;
		ax_ojo=posicion.vx;
		ay_ojo=posicion.vy;
		az_ojo=posicion.vz;
	//printf("%f %f %f\n",ax_ojo, ay_ojo, az_ojo);
}

void Mundo :: Inicializa_vista()
{
	x_ojo=112.5;
	y_ojo=-175;
	z_ojo=50;
	miro_x=112.5;
	miro_y=37.5;
	miro_z=0;
	ax_ojo=112.5;
	ay_ojo=-37.5;
	az_ojo=50;
	amiro_x=112.5;
	amiro_y=37.5;
	amiro_z=0;
}