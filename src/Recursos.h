#pragma once
class Recursos
{
	unsigned int comida,hierro,oro;
public:
	void set (unsigned int comida=0, unsigned int hierro=0, unsigned int oro=0);
	unsigned int getComida();
	unsigned int getHierro();
	unsigned int getOro();
	Recursos(unsigned int comida=0, unsigned int hierro=0, unsigned int oro=0);
	~Recursos(void);
	bool operator >= (Recursos&);
	bool operator <=(Recursos&);
	Recursos operator * (float);
	void operator -= (Recursos&);
	void operator += (Recursos&);

//	friend class Menus;
};
