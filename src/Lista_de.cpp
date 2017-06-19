#include "Lista_de.h"


Lista_de::Lista_de(unsigned char red, unsigned char green, unsigned char blue):
	equipo(red, green, blue)
{
	numero=0;
	cuarteles=0;
	fabricas=0;
	personajes=0;
	max_cuarteles=1;
	max_fabricas=1;
	max_personajes=1;
	for (int n=0;n<MAX; n++)
	{
		lista[n]=0;
		disparos[n]=0;
	}
	lista[numero++]=new Ayuntamiento ();
	lista[numero++]=new Cuartel ();
	lista [numero++]=new Fabrica (comida);
	lista [numero++]=new Fabrica (hierro);
	lista[numero++]=new Fabrica (oro);
}

Lista_de::~Lista_de(void)
{

}

bool Lista_de:: Agregar (unsigned int tipo,Type especifico, unsigned int cuartel)
{
	if(numero<MAX)
	{
		if (tipo==1 && cuarteles<max_cuarteles)
		{
			lista[numero++]=new Cuartel ;
			cuarteles++;
		}
		else if (tipo==2 && fabricas<max_fabricas)
		{
			lista[numero++]=new Fabrica (especifico);
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
	return true;
}

void Lista_de :: Dibuja()
{
	for(int n=0; n<numero;n++)
	{
		lista[n]->Dibuja(equipo);
		if (disparos[0]!=0)
			disparos[n]->Dibuja();
	}
}

/*void Lista_de :: choque()
{
	for(int n=0; n<numero;n++)
	{
		Interaccion
	}
}*/

int Lista_de :: Morir()
{
	int muertos=0;
	for (int n=0;n<numero;n++)
	{
		if (lista[n]->vida<=0)
		{
			delete lista[n];
			numero--;
			for (int i=n;i<numero; i++)
			{
				lista[i]=lista[i+1];
			}
			muertos++;
		}
	}
	return muertos;
}
void Lista_de :: subirNivel(unsigned int tipo, unsigned int especifico)
{
	int contador=0;
	for (int n=0;n<numero;n++)
	{
		if (lista[n]->tipo==tipo)
		{
			lista [n]->subirNivel(especifico);
			if (contador!=0)
			{
				lista[n]->nivel++;
				contador++;
			}
		}
	}
}
void Lista_de :: Timer (float t)
{
	for(int n=0;n<numero;n++)
	{
		lista[n]->Timer(t);
	}
	for(int n=0;1;n++)
	{
		if(disparos[n]==0)
			break;
		disparos[n]->Timer(t);
	}
	
}

void  Lista_de :: prueba()
{
	lista[numero++]=new Personaje (1);
}