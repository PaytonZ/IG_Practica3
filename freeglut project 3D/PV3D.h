/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#ifndef PUNTO_H
#define PUNTO_H
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>


class PV3D
{
public:

//Variables de la calse:
GLdouble x;
GLdouble y;
GLdouble z;
GLdouble vector;

//Constructor - destructor.
	PV3D(GLdouble nx, GLdouble ny, GLdouble nz,bool esVector):
		x(nx),y(ny),z(nz){
			if (esVector)
				vector=0;
			else vector=1;
	}
	PV3D()
	{
		x=0;y=0;z=0;vector=0;
	}
	~PV3D(void){}

//Sobrecarga de operadores
	//PV3D& operator = (const PV3D &p);
	PV3D& operator * (const GLdouble &p);
	PV3D& operator * (const PV3D &p);
	PV3D& operator + (const PV3D &p);
	PV3D& operator - (const PV3D &p);
	PV3D& operator / (const GLdouble &p);

//Otras operaciones sobre Puntos
	GLdouble distanciaEntrePuntos(const PV3D &punto);
//Otras operaciones sobre Vectores
	GLdouble productoEscalar(const PV3D &p);
	PV3D normalizarVector();	
	GLdouble moduloVector ();
	
};

#endif // !PUNTO_H