#pragma once
class Recursos
{
	unsigned int comida,hierro,oro;
public:
	void set (unsigned int comida=0, unsigned int hierro=0, unsigned int oro=0);
	unsigned int getComida();
	unsigned int getHierro();
	unsigned int getOro();
	Recursos(void);
	~Recursos(void);
	friend class Menus;
};
