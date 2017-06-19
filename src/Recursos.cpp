#include "Recursos.h"

Recursos::Recursos(void):
	comida(0),
	hierro (0),
	oro(0)
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