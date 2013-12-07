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
	*arrayVN = new VerticeNormal[numVetices];
}

int Cara:: getNumeroVertices()
{
	return numVetices;
}

int Cara:: getIndiceNormalK(int i)
{
	return arrayVN[i]->indiceN;
}

int Cara:: getIndiceVerticeK(int i)
{
	return arrayVN[i]->indiceV;
}


