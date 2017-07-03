#include "Lista_de.h"
#include "Mapa.h"
#include "Vector3D.h"


	
class Mundo
{
	Mapa map;
	Lista_de jugador1, jugador2;
	
public: 
	Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void Inicializa_vista();
	void Timer(float t);
	void Dibuja();
	void Raton (int button, int state, Vector pos);
	void RatonPasivo(int x, int y);
	void setPerspectiva(float ojo_a, float ojo_b, float ojo_c, float miro_a, float miro_b, float miro_c);
	void movimientoCamara(float t);

	float x_ojo;
	float y_ojo;
	float z_ojo;
	float miro_x, miro_y, miro_z;
	float ax_ojo;
	float ay_ojo;
	float az_ojo;
	float amiro_x, amiro_y, amiro_z;
	
	friend class Mapa;
};
