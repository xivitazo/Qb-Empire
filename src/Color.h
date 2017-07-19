#pragma once
#include "glut.h"

class Color
{
	unsigned int red, green, blue;
public:
	Color(unsigned int red, unsigned int green=0, unsigned int blue=0);
	Color();//constructor por defecto
	virtual ~Color(void);
	void set(unsigned int red, unsigned int green, unsigned int blue);
	unsigned int getRed ();
	unsigned int getGreen ();
	unsigned int getBlue ();
};

