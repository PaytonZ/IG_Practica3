/********************************************************************************
*																				*
*		Practica 3 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Satelite.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>


void Satelite :: dibuja()
{
	sat->dibuja();
	//El cuadrado de abajo.
	
		/*glColor3f(0.0,0.0,0.0); 
		for (int i=0; i<sat->numCaras;i++)
		{

			PV3D* debug;
			debug= sat->vertice[0]; // Estan los 4 vertices bien calculados -.-"
			debug= sat->vertice[1];
			debug= sat->vertice[2];
			debug= sat->vertice[3];
			for(int j=0; j<=sat->cara[i]->getNumeroVertices();j++)
			{
				int iV= sat->cara[i]->getIndiceVerticeK(j);
				int iVnext= sat->cara[i]->getIndiceVerticeK((j+1)%(sat->cara[i]->getNumeroVertices()+1)); 
				int iN= sat->cara[i]->getIndiceNormalK(j);
				int iNnext = sat->cara[i]->getIndiceNormalK((j+1)%(sat->cara[i]->getNumeroVertices()+1));
				debug= sat->vertice[iV];
				glBegin(GL_LINE);
					glNormal3f((float)sat->normal[iN]->x,(float)sat->normal[iN]->y,(float)sat->normal[iN]->z);			
					glVertex3f((float)sat->vertice[iV]->x,(float)sat->vertice[iV]->y,(float)sat->vertice[iV]->z);
					glNormal3f((float)sat->normal[iNnext]->x,(float)sat->normal[iNnext]->y,(float)sat->normal[iNnext]->z);
					glVertex3f((float)sat->vertice[iVnext]->x,(float)sat->vertice[iVnext]->y,(float)sat->vertice[iVnext]->z);
				glEnd();
			}
		}*/

	/*glLineWidth(1.0);
	for (int i=0; i<11; i++)
	{
		glBegin(GL_POLYGON);
		// Cara cero
		glNormal3f((float)sat->normal[i]->x,(float)sat->normal[i]->y,(float)sat->normal[i]->z);			
		glVertex3f((float)sat->vertice[i]->x,(float)sat->vertice[i]->y,(float)sat->vertice[i]->z);
		glNormal3f((float)sat->normal[i+4]->x,(float)sat->normal[i+4]->y,(float)sat->normal[i+4]->z);			
		glVertex3f((float)sat->vertice[i+4]->x,(float)sat->vertice[i+4]->y,(float)sat->vertice[i+4]->z);
		glNormal3f((float)sat->normal[i+5]->x,(float)sat->normal[i+5]->y,(float)sat->normal[i+5]->z);			
		glVertex3f((float)sat->vertice[i+5]->x,(float)sat->vertice[i+5]->y,(float)sat->vertice[i+5]->z);
		glNormal3f((float)sat->normal[i+1]->x,(float)sat->normal[i+1]->y,(float)sat->normal[i+1]->z);			
		glVertex3f((float)sat->vertice[i+1]->x,(float)sat->vertice[i+1]->y,(float)sat->vertice[i+1]->z);
	glEnd();
	}
	/*for (int i=11; i<12; i++)
	{
	glBegin(GL_LINE_LOOP);
		// Cara cero
		glNormal3f((float)sat->normal[i]->x,(float)sat->normal[i]->y,(float)sat->normal[i]->z);			
		glVertex3f((float)sat->vertice[i]->x,(float)sat->vertice[i]->y,(float)sat->vertice[i]->z);
		glNormal3f((float)sat->normal[i+4]->x,(float)sat->normal[i+4]->y,(float)sat->normal[i+4]->z);			
		glVertex3f((float)sat->vertice[i+4]->x,(float)sat->vertice[i+4]->y,(float)sat->vertice[i+4]->z);
		glNormal3f((float)sat->normal[i+5]->x,(float)sat->normal[i+5]->y,(float)sat->normal[i+5]->z);			
		glVertex3f((float)sat->vertice[i+5]->x,(float)sat->vertice[i+5]->y,(float)sat->vertice[i+5]->z);
		glNormal3f((float)sat->normal[i+1]->x,(float)sat->normal[i+1]->y,(float)sat->normal[i+1]->z);			
		glVertex3f((float)sat->vertice[i+1]->x,(float)sat->vertice[i+1]->y,(float)sat->vertice[i+1]->z);
	glEnd();
	}*/
	
	/*
	glBegin(GL_LINE_LOOP);
		//Cara uno
		glNormal3f((float)sat->normal[1]->x,(float)sat->normal[1]->y,(float)sat->normal[1]->z);			
		glVertex3f((float)sat->vertice[1]->x,(float)sat->vertice[1]->y,(float)sat->vertice[1]->z);
		glNormal3f((float)sat->normal[5]->x,(float)sat->normal[5]->y,(float)sat->normal[5]->z);			
		glVertex3f((float)sat->vertice[5]->x,(float)sat->vertice[5]->y,(float)sat->vertice[5]->z);
		glNormal3f((float)sat->normal[6]->x,(float)sat->normal[6]->y,(float)sat->normal[6]->z);			
		glVertex3f((float)sat->vertice[6]->x,(float)sat->vertice[6]->y,(float)sat->vertice[6]->z);
		glNormal3f((float)sat->normal[2]->x,(float)sat->normal[2]->y,(float)sat->normal[2]->z);			
		glVertex3f((float)sat->vertice[2]->x,(float)sat->vertice[2]->y,(float)sat->vertice[2]->z);
	glEnd();
	glBegin(GL_LINE_LOOP);
		//Cara dos
		glNormal3f((float)sat->normal[2]->x,(float)sat->normal[2]->y,(float)sat->normal[2]->z);			
		glVertex3f((float)sat->vertice[2]->x,(float)sat->vertice[2]->y,(float)sat->vertice[2]->z);
		glNormal3f((float)sat->normal[6]->x,(float)sat->normal[6]->y,(float)sat->normal[6]->z);			
		glVertex3f((float)sat->vertice[6]->x,(float)sat->vertice[6]->y,(float)sat->vertice[6]->z);
		glNormal3f((float)sat->normal[7]->x,(float)sat->normal[7]->y,(float)sat->normal[7]->z);			
		glVertex3f((float)sat->vertice[7]->x,(float)sat->vertice[7]->y,(float)sat->vertice[7]->z);
		glNormal3f((float)sat->normal[3]->x,(float)sat->normal[3]->y,(float)sat->normal[3]->z);			
		glVertex3f((float)sat->vertice[3]->x,(float)sat->vertice[3]->y,(float)sat->vertice[3]->z);
	glEnd();*/
}