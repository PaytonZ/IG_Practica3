/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
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
		glBegin(GL_POLYGON); //glBegin(GL_LINE_LOOP);
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

PV3D Malla :: calculoVectorNormalPorNewell(Cara c)
{
	PV3D n, verticeActual,verticeSiguiente;
	for (int i=0; i<c.getNumeroVertices();i++)
	{
		verticeActual=*vertice[c.getIndiceVerticeK(i)];
		verticeSiguiente=*vertice[c.getIndiceVerticeK((i+1)%c.getNumeroVertices())];
		n.x+=(verticeActual.y-verticeSiguiente.y)*(verticeActual.z-verticeSiguiente.z);
		n.y+=(verticeActual.z-verticeSiguiente.z)*(verticeActual.x-verticeSiguiente.x);
		n.z+=(verticeActual.x-verticeSiguiente.x)*(verticeActual.y-verticeSiguiente.y);
	}

	return n.normalizarVector();

}