#include "Lista_de.h"


Lista_de::Lista_de(Vector ayuntamiento, Color equipo ):
	equipo(equipo)
{
	numero=0;
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
	}
	max_Type[EDIFICIOS]=4;
	max_Type[COMBATIENTES]=20;



	lista[numero++]=new Ayuntamiento (ayuntamiento);
	numero_generado[EDIFICIOS]++;
}

Lista_de::~Lista_de(void)
{

}

bool Lista_de:: Agregar (Type tipo, Vector posicion)
{
	if(numero<MAX&&numero_generado[EDIFICIOS]<max_Type[EDIFICIOS])
	{
		switch (tipo){
		case F_ORO : 
		case F_HIERRO : 
		case F_COMIDA : lista[numero++] = new Fabrica(tipo, posicion, nivel[tipo]); numero_generado[EDIFICIOS]++; return true;
		case CUARTEL : lista[numero++] = new Cuartel(posicion, nivel[tipo]); numero_generado[EDIFICIOS]++; return true;
		}

	}
	return false;
}

bool Lista_de :: Agregar (Luchadores tipo, Vector destino)
{
	for(int n=0;n<numero&&lista[numero]==0;n++)
	{
			lista[numero] = lista[n]->generar ( nivel[LUCHADOR+tipo], tipo, destino);
	}
	if (lista[numero]==0)
		return false;
	numero++;
	numero_generado[COMBATIENTES]++;
	return true;
}

void Lista_de :: Dibuja()
{
	for(int n=0; n<numero;n++)
	{
		lista[n]->Dibuja(equipo);
	}
	
}

void Lista_de :: Morir()
{
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
				numero_generado[COMBATIENTES]--;
				break;
			default:
				numero_generado[EDIFICIOS]--;
				break;
			}
			delete lista[n];
			numero--;
			for (int i=n;i<numero; i++)
			{
				lista[i]=lista[i+1];
				lista[i+1]=0;
			}
		}
	}
}

bool Lista_de :: subirNivel(Type tipo)
{
	if (nivel[tipo]<4)
	{
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
		return true;
	}
	return false;
}

bool Lista_de :: subirNivel(Luchadores tipo)
{
	nivel[tipo+LUCHADOR]++;
	for(int n=0; n<numero; n++)
	{
		if(lista[n]->especifico==tipo)
			lista[n]->subirNivel();
	}
	return true;
}

void Lista_de :: Timer (float t)
{
	Morir();
	Rebote();
	for(int n=0;n<numero;n++)
	{
		lista[n]->Timer(t);
	}
	generarRecursos();
}

void Lista_de :: Rebote()
{
	for (int n=0;n<numero-1;n++)
		for (int i=n+1; i<numero;i++)
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


