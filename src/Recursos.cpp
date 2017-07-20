#include "Recursos.h"

Recursos::Recursos(unsigned int comida, unsigned int hierro, unsigned int oro):
	comida(comida),
	hierro (hierro),
	oro(oro)
{
}

Recursos::~Recursos(void)
{
}

void Recursos :: set(unsigned int comida, unsigned int hierro, unsigned int oro)
{
	this->comida=comida;
	this ->hierro=hierro;
	this -> oro=oro;
}

unsigned int Recursos:: getComida()
{
	return comida;
}

unsigned int Recursos:: getHierro()
{
	return hierro;
}

unsigned int Recursos:: getOro()
{
	return oro;
}

bool Recursos :: operator>= (Recursos &r)
{
	if(comida>=r.getComida() && hierro>=r.getHierro() && oro>=r.getOro())
		return true;
	return false;
}
bool Recursos :: operator<= (Recursos &r)
{
	if(comida<=r.getComida() && hierro<=r.getHierro() && oro<=r.getOro())
		return true;
	return false;
}
Recursos Recursos :: operator * (float n)
{
	Recursos aux;
	aux.set(comida*n,hierro*n,oro*n);
	return  aux;
}

void Recursos :: operator -= (Recursos& r)
{
	comida-=r.getComida();
	hierro-=r.getHierro();
	oro-=r.getOro();
}

void Recursos :: operator += (Recursos& r)
{
	comida+=r.getComida();
	hierro+=r.getHierro();
	oro+=r.getOro();
}