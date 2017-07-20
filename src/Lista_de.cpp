#include "Lista_de.h"7
#include "ETSIDI.h"
using namespace ETSIDI;


Lista_de::Lista_de(Vector ayuntamiento, Color equipo ):
	equipo(equipo),
	almacen(20, 100, 0),
	numero_cola(0),
	numero(0),
	destino(120, 40)
{
	for(int n=0;n<COLA;n++)
	{
		cola_generar[n]=NINGUNO;
	}
	for (int n=0;n<MAX; n++)
	{
		lista[n]=0;
	}
	for(int n=0; n<MAX_TIPOS;n++)
	{
		nivel[n]=1;
	}
	for(int n=0; n<MAX_GENERAL;n++)
	{
		numero_generado[n]=0;
		numero_actual[n]=0;
	}
	max_Type[EDIFICIOS]=4;
	max_Type[COMBATIENTES]=20;
	inicializarCostes();

	lista[numero++]=new Ayuntamiento (ayuntamiento);
	numero_generado[EDIFICIOS]++;
	numero_actual[EDIFICIOS]++;
}

Lista_de::~Lista_de(void)
{

}

bool Lista_de:: Agregar (Type tipo, Vector posicion)
{
	if(numero_actual[EDIFICIOS]==8)
		coste[0]=coste[0]*2;
	else if(numero_actual[EDIFICIOS]==12)
		coste[0]=coste[0]*2;
	else if(numero_actual[EDIFICIOS]==15)
		coste[0]=coste[0]*2;
	if(numero<MAX && numero_actual[EDIFICIOS]<max_Type[EDIFICIOS]&& almacen>=coste[0]	)
	{
		almacen-=coste[0];
		switch (tipo){
		case F_ORO : 
		case F_HIERRO : 
		case F_COMIDA :
			lista[numero++] = new Fabrica(tipo, posicion, nivel[tipo]); 
			numero_generado[EDIFICIOS]++; 
			numero_actual[EDIFICIOS]++;
			return true;
		case CUARTEL :
			lista[numero++] = new Cuartel(posicion, nivel[tipo]); 
			numero_generado[EDIFICIOS]++;
			numero_actual[EDIFICIOS]++;
			return true;
		}

	}
	return false;
}

bool Lista_de :: Agregar (Luchadores tipo, Vector destino)
{
	if(numero_cola<COLA)
	{
		cola_generar[numero_cola++]=tipo;
		return true;
	}
	return false;
	
}

void Lista_de :: Dibuja()
{
	for(int n=0; n<numero;n++)
	{
		glPushName(n+100);
		lista[n]->Dibuja(equipo);
		glPopName();
	}
	
}

int Lista_de :: Morir()
{
	int muertos=0;
	for (int n=0;n<numero;n++)
	{
		if (lista[n]->vida<=0.0f)
		{
			switch (lista[n]->tipo){
			case AYUNTAMIENTO:
				//GAME OVER
				//Ya veremos como lo hacemos
				break;
			case LUCHADOR:
				numero_actual[COMBATIENTES]--;
				break;
			default:
				numero_actual[EDIFICIOS]--;
				break;
			}
			delete lista[n];
			numero--;
			for (int i=n;i<numero; i++)
			{
				lista[i]=lista[i+1];
				lista[i]->setNombre(i);
				//lista[i+1]=0;
			}
			lista[numero]=0;
			muertos++;
		}
	}
	return muertos;
}

bool Lista_de :: subirNivel(Type tipo)
{
	if(tipo!=AYUNTAMIENTO && nivel[tipo]>=nivel[AYUNTAMIENTO])
		return false;
	if (nivel[tipo]<4 && almacen.getOro()>=coste_nivel[tipo] )
	{
		AñadirOro(-coste_nivel[tipo]);
		nivel[tipo]++;
		if (tipo==AYUNTAMIENTO)
		{
			max_Type[COMBATIENTES]=max_Type[COMBATIENTES]*1.5;
			max_Type[EDIFICIOS]+=5;
		}
		for(int n=0; n<numero; n++)
		{
			if(lista[n]->tipo==tipo)
				lista[n]->subirNivel();
		}
		coste_nivel[tipo]*=2;
		return true;
			
	}
	return false;
}

bool Lista_de :: subirNivel(Luchadores tipo)
{
	if(almacen.getOro()>=coste_nivel[LUCHADOR+tipo] && nivel[LUCHADOR+tipo]<4)
	{
		AñadirOro(-coste_nivel[LUCHADOR+tipo]);
		nivel[tipo+LUCHADOR]++;
		for(int n=0; n<numero; n++)
		{
			if(lista[n]->especifico==tipo)
				lista[n]->subirNivel();
		}
		coste_nivel[LUCHADOR+tipo]*=2;
		return true;
	}
	return false;
}

void Lista_de :: Timer (float t)
{
	Rebote();
	for(int n=0;n<numero;n++)
	{
		lista[n]->Timer(t);
	}
	generarRecursos();
	generarCombatientes();
}

void Lista_de :: Rebote()
{
	for (int n=0;n<numero-1;n++)
		for (int i=n; i<numero;i++)
			Interaccion :: rebote (*lista[n], *lista[i]);
}

bool Lista_de :: generarRecursos()
{
	for(int n=0; n<numero; n++)
	{
		lista[n]->generar(almacen);
	}
	return true;
}

int Lista_de :: atacar(Disparo** disparos, Edificio** enemigos)
{
	int generado=0;
	for(int n=0;n<numero;n++)
	{
		generado+=lista[n]->Atacar(enemigos, disparos+generado);
	}
	return generado;
}

void Lista_de :: inicializarCostes()
{
	coste[0]=Recursos(0,50,0);
	coste[LUCHADOR+SOLDADO]=Recursos(4,1,0);
	coste[LUCHADOR+ARQUERA]=Recursos(4,1,0);
	coste[LUCHADOR+CABALLERO]=Recursos(8,4,0);
	coste[LUCHADOR+GUERRERO]=Recursos(8,4,0);
	coste[LUCHADOR+GIGANTE]=Recursos(10,2,0);
	coste_nivel[F_COMIDA]=50;
	coste_nivel[F_HIERRO]=75;
	coste_nivel[F_ORO]=100;
	coste_nivel[CUARTEL]=75;
	coste_nivel[AYUNTAMIENTO]=50;
	coste_nivel[LUCHADOR+SOLDADO]=100;
	coste_nivel[LUCHADOR+ARQUERA]=100;
	coste_nivel[LUCHADOR+CABALLERO]=125;
	coste_nivel[LUCHADOR+GUERRERO]=250;
	coste_nivel[LUCHADOR+GIGANTE]=375;
}

bool Lista_de :: generarCombatientes()
{
	if(cola_generar[0]==NINGUNO)
		return false;
	if(numero_actual[COMBATIENTES]<=max_Type[COMBATIENTES] && almacen>=coste[LUCHADOR+cola_generar[0]]*nivel[LUCHADOR+cola_generar[0]] )
	{
		for(int n=0;n<numero&&lista[numero]==0;n++)
		{
				lista[numero] = lista[n]->generar ( nivel[LUCHADOR+cola_generar[0]], cola_generar[0], destino);
		}
		if (lista[numero]==0)
			return false;
		
		almacen-=coste[LUCHADOR+cola_generar[0]]*nivel[LUCHADOR+cola_generar[0]];
		numero++;
		numero_generado[COMBATIENTES]++;
		numero_actual[COMBATIENTES]++;
		numero_cola--;
		for(int n=0;n<numero_cola;n++)
		{
			cola_generar[n]=cola_generar[n+1];
		}
		cola_generar[numero_cola]=NINGUNO;
		return true;
	}
	return false;
}

