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
		case F_COMIDA : lista[numero++]= new Fabrica(tipo, posicion, nivel[tipo]); numero_generado[EDIFICIOS]++; return true;
		case CUARTEL : lista[numero++]=new Cuartel(posicion, nivel[tipo]); numero_generado[EDIFICIOS]++; return true;
		}

	}
	return false;
}
bool Lista_de :: Agregar (Luchadores tipo)
{
		for(int n=0; n<numero; n++)
		{
			if (lista[n]->tipo == CUARTEL && lista[n]->poderGenerar())
			{
				lista[n]-> generar (&lista[numero++], nivel[LUCHADOR+tipo], tipo);
				numero_generado[COMBATIENTES]++;
				return true;
			}
		}
		return false;
}

void Lista_de :: Dibuja()
{
	for(int n=0; n<numero;n++)
	{
		lista[n]->Dibuja(equipo);
	}
	
}

/*void Lista_de :: choque()
{
	for(int n=0; n<numero;n++)
	{
		Interaccion
	}
}*/

void Lista_de :: Morir()
{
	for (int n=0;n<numero;n++)
	{
		if (lista[n]->vida<=0)
		{
			numero_generado[lista[n]->tipo+lista[n]->especifico]--;
			delete lista[n];
			numero--;
			for (int i=n;i<numero; i++)
			{
				lista[i]=lista[i+1];
			}
		}
	}
}
bool Lista_de :: subirNivel(Type tipo)
{
	nivel[tipo]++;
	if (tipo==AYUNTAMIENTO)
	{
		max_Type[COMBATIENTES]=(int)((float)max_Type[COMBATIENTES]*1.5);
		max_Type[EDIFICIOS]+=5;
	}
	for(int n=0; n<numero; n++)
	{
		if(lista[n]->tipo==tipo&&lista[n]->especifico)
			lista[n]->subirNivel();
	}
	return true;
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
	for(int n=0;n<numero;n++)
	{
		lista[n]->Timer(t);
	}	
}

void Lista_de :: Rebote()
{
	for (int n=0;n<numero-1;n++)
		for (int i=n; i<numero;i++)
			Interaccion :: Rebote (*lista[n], *lista[i]);
}
bool Lista_de :: generarRecursos()
{
	for(int n=0; n<numero; n++)
	{
		lista[n]->generar();
	}
	return true;
}

