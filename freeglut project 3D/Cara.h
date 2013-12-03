/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "VerticeNormal.h"


class Cara
{
public:
	Cara(int numV):numVetices(numV)
	{
		arrayVN= new VerticeNormal[numVetices];
	}
	Cara(){numVetices=0;}
	~Cara(void);
	void setValor(int i, int v, int n); // i= indice del array, v lo que quieres en la Vertice y n a la normal.
	void setnumVertices(int nv);
private:
	int numVetices;
	VerticeNormal* arrayVN; // El tio quiere un **
};

