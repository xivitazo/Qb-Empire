#include "Lista_de.h"


Lista_de::Lista_de(unsigned char red, unsigned char green, unsigned char blue):
	equipo(red, green, blue)
{
	numero=0;
	cuarteles=0;
	fabricas=0;
	personajes=0;
	for (int n=0;n<MAX; n++)
	{
		lista[n]=0;
		disparos[n]=0;
	}
	for(int n=0; n<MAX_TIPOS;n++)
	{
		numero_generado[n]=0;
		nivel[n]=1;
		max_Type[n]=0;
	}




	lista[numero++]=new Ayuntamiento ();
	lista[numero++]=new Cuartel (4);
	lista [numero++]=new Fabrica (F_COMIDA,1);
	lista [numero++]=new Fabrica (F_HIERRO,2);
	lista[numero++]=new Fabrica (F_ORO,3);
}

Lista_de::~Lista_de(void)
{

}

bool Lista_de:: Agregar (Type tipo, Luchadores especifico, unsigned int cuartel)
{
	if (especifico!=NINGUNO && tipo != LUCHADOR)
			return false;
	if(numero<MAX&&numero_generado[especifico+tipo]<max_Type[tipo+especifico])
	{
		switch (tipo){
		case F_ORO : 
		case F_HIERRO : 
		case F_COMIDA : lista[numero++]= new Fabrica(tipo, nivel[tipo]); return true;
		case CUARTEL : lista[numero++]=new Cuartel(nivel[tipo]); return true;
		}
		if (especifico != NINGUNO)
		{
			lista[numero]=new Personaje (especifico,nivel[tipo+especifico]);
			lista[numero++]->setPosicion(lista[cuartel]->posicion.vx,lista[cuartel]->posicion.vy);
		}

	}
	return false;
		/*
		if (tipo==CUARTEL && cuarteles<max[CUARTEL])
		{
			lista[numero++]=new Cuartel ;
			cuarteles++;
		}
		else if (tipo==F_ORO && fabricas(F_ORO)<max[F_ORO])
		{
			lista[numero++]=new Fabrica ();
			fabricas++;
		}
		else if (tipo ==3 && personajes<max_personajes && cuarteles>=1 && lista[cuartel]->poderGenerar())
		{
			lista[numero++]=new Personaje (especifico);
			personajes++;
		}
		else return false;
	}
	else return false;
	return true;*/
}

void Lista_de :: Dibuja()
{
	for(int n=0; n<numero;n++)
	{
		lista[n]->Dibuja(equipo);
	}
	for (int n=0; n<MAX;n++)
	{
		if (disparos[0]==0)
		{
			break;
		}
		disparos[n]->Dibuja();
		continue;
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
bool Lista_de :: subirNivel(Type tipo, Luchadores especifico)
{
	if(especifico!=NINGUNO && tipo!= CUARTEL)
		return 0;
	nivel[tipo+especifico]++;
	for(int n=0; n<numero; n++)
	{
		if(lista[n]->tipo==tipo&&lista[n]->especifico)
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
	for(int n=0;n<MAX;n++)
	{
		if(disparos[n]==0)
			break;
		if(disparos[n]->Mueve())
			Interaccion :: Ataque (disparos[n]);

	}
	
}

void Lista_de :: Rebote()
{
	for (int n=0;n<numero-1;n++)
		for (int i=n; i<numero;i++)
			Interaccion :: Rebote (*lista[n], *lista[i]);
}

