/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/



#include "Cara.h"





Cara::~Cara(void)
{
}

void Cara:: setnumVertices(int nv)
{
	if (arrayVN)
		delete(arrayVN);
	arrayVN= new VerticeNormal[numVetices];
}