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
		numero_generado[n]=0;
		nivel[n]=1;
		max_Type[n]=50;
	}



	lista[numero++]=new Ayuntamiento (ayuntamiento);
}

Lista_de::~Lista_de(void)
{

}

bool Lista_de:: Agregar (Type tipo, Vector posicion)
{
	if(numero<MAX&&numero_generado[tipo]<max_Type[tipo])
	{
		switch (tipo){
		case F_ORO : 
		case F_HIERRO : 
		case F_COMIDA : lista[numero++]= new Fabrica(tipo, posicion, nivel[tipo]); return true;
		case CUARTEL : lista[numero++]=new Cuartel(posicion, nivel[tipo]); return true;
		}

	}
	return false;
}
bool Lista_de :: Agregar (Luchadores especifico)
{
		for(int n=0; n<numero; n++)
		{
			if (lista[n]->tipo == CUARTEL && lista[n]->poderGenerar(LUCHADOR))
			{
				lista[n]-> generar (&lista[numero++], nivel[LUCHADOR+especifico], especifico);
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

