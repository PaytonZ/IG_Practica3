/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#pragma once

/*
Esta clase tiene que tener una tabla de vetices otra de normales y otra de caras.
*/


#include "PV3D.h"
#include "Cara.h"

class Malla
{
protected: 

public:
	//De momento esto esta publico para poder debugear y ver el valorde desde clases externas.
	int numVertices;
	PV3D** vertice;
	int numNormales;
	PV3D** normal;
	int numCaras;
	Cara** cara;
	int iVertice,iNormal,iCara;



	Malla(int numV, int numN, int numC): numVertices(numV), numNormales(numN), numCaras(numC)
	{
		vertice = new PV3D*[numVertices];
		normal = new PV3D*[numNormales];
		cara= new Cara*[numCaras];
		iVertice=0;
		iNormal=0;
		iCara=0;
	}
	~Malla(void)
	{
		for(int i=0; i<numVertices; i++)

			delete []vertice[i];

		for(int i=0; i<numNormales; i++)
			delete []normal[i];

		for(int i=0; i<numCaras; i++)
			delete []cara[i];
	}


	void dibuja();
	PV3D* calculoVectorNormalPorNewell(Cara c);
	bool anadirVertice( PV3D*);
	bool anadirNormal( PV3D*);
	bool anadirCara(Cara *);
};

