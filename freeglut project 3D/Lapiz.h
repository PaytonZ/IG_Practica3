/********************************************************************************
*																				*
*		Practica 2 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "PV3D.h"

class Lapiz
{
public:
	Lapiz()
	{
		pos= PV3D (0,0,0,false);
	}

	Lapiz(PV3D p, GLdouble d): pos(p),dir(d){}

	~Lapiz(void){}

	void moveTo(PV3D,bool);
	void turnTo(GLdouble);
	//Este metodo ahora solo sirve para dibujar en el plano XZ.
	void forward(GLdouble,bool);

	PV3D pos;
	GLdouble dir;
private:
	
};
