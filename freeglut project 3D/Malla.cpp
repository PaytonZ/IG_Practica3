/********************************************************************************
*																				*
*		Practica 3 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#include "Malla.h"

void Malla :: dibuja()
{
	
	for (int i=0;i<numCaras; i++)
	{
		glLineWidth(1.0);
		//glBegin(GL_POLYGON); 
		glBegin(GL_LINE_LOOP);
		for (int j=0; j<cara[i]->getNumeroVertices();j++)
		{
			int iN=cara[i]->getIndiceNormalK(j);
			int iV=cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->x,normal[iN]->y,normal[iN]->z);
			glVertex3f(vertice[iV]->x,vertice[iV]->y, vertice[iV]->z); 
		}
		glEnd();
		
	}
}

PV3D* Malla :: calculoVectorNormalPorNewell(Cara c)
{
	PV3D* n = new PV3D( 0,0,0,false);
	PV3D* verticeActual;
	PV3D* verticeSiguiente;
	for (int i=0; i<c.getNumeroVertices();i++)
	{
		verticeActual=vertice[c.getIndiceVerticeK(i)];
		verticeSiguiente=vertice[c.getIndiceVerticeK((i+1)%c.getNumeroVertices())];
		n->x+=(verticeActual->y-verticeSiguiente->y)*(verticeActual->z+verticeSiguiente->z);
		n->y+=(verticeActual->z-verticeSiguiente->z)*(verticeActual->x+verticeSiguiente->x);
		n->z+=(verticeActual->x-verticeSiguiente->x)*(verticeActual->y+verticeSiguiente->y);
	}
	n->normalizarVector();
	return n;
}

bool Malla :: anadirVertice(PV3D * v)
{
	if (iVertice>numVertices)
		return false;
	vertice[iVertice]=v;
	iVertice++;
	return true;
}

bool Malla :: anadirNormal(PV3D *n)
{
	if (iNormal>numNormales)
		return false;
	normal[iNormal]=n;
	iNormal++;
	return true;
}

bool Malla :: anadirCara( Cara *c)
{
	if (iCara>numCaras)
		return false;
	cara[iCara]=c;
	iCara++;
	return true;
}

