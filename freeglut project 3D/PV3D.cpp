/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/



#include <cmath>
#include "PV3D.h"

PV3D& PV3D::operator = (const PV3D &p)
{
	if(this!=&p){ 
		this->x = p.x;
		this->y = p.y;
		this->z= p.z;
		this->vector=p.vector;
	}
	return *this;
}

// TODO falta por implementar la multiplicacion.


//No tiene sentido sumar 2 puntos
PV3D&  PV3D::operator + (const PV3D &p) 
{
	if (p.vector==0 && this->vector==0)
		return *(new PV3D(this->x + p.x ,  this->y + p.y,
						this->z + p.z, true));
	else if (p.vector==0 || this->vector==0)
		return *(new PV3D(this->x + p.x ,  this->y + p.y,
						this->z + p.z, false));
	else return *this;
}

//O restas vectores y obtienes un vector o restas puntos y obtienes un vector
//Cualquier otra resta no tiene sentido.
PV3D&  PV3D::operator - (const PV3D &p)
{
	if (p.vector==0 && this->vector==0)
		return *( new PV3D( this->x - p.x ,  this->y - p.y,
						this->z-p.z, true));
	else if (p.vector==1 && this->vector==1)
		return *(new PV3D(this->x - p.x ,  this->y - p.y,
						this->z - p.z, true));
	else return *this;
}

PV3D& PV3D:: operator * (const GLdouble &p)
{
	if(this->vector==0)
		return *(new PV3D ( this->x*p ,  this->y*p,
						this->z*p, true));
	else
		return *(new PV3D ( this->x*p ,  this->y*p,
						this->z*p, false));
}


GLdouble PV3D:: distanciaEntrePuntos(const PV3D &punto)
{
	if (this->vector==0 || punto.vector==0)
		return -1;
	return sqrt(pow((x - punto.x),2.0)+
		pow((y - punto.y),2.0) + pow((z - punto.z),2.0) );
}

GLdouble PV3D:: productoEscalar(const PV3D &p)
{
	return (x*p.x+y*p.y+z*p.z);
}

PV3D PV3D:: normalizarVector()
{
	return PV3D (x*(1/moduloVector()), y*(1/moduloVector()),
				z*(1/moduloVector()),true);
}

GLdouble PV3D :: moduloVector()
{
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}