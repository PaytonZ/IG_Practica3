/********************************************************************************
*																				*
*		Practica 2 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


#include "Lapiz.h"
#include <cmath>
const GLdouble M_PI = 3.1415926535897932384626433832795;


void Lapiz :: moveTo(PV3D p, bool draw)
{
	if (draw)
	{
		 glBegin(GL_LINES);
                glVertex3d(pos.x, pos.y,pos.z);
                glVertex3d(p.x, p.y,p.z);
         glEnd();
	}

	pos=p;
}

void Lapiz::turnTo(GLdouble a)
{
	dir+=a;
}

//Este metodo ahora solo sirve para dibujar en el plano XZ.
void Lapiz :: forward(GLdouble dist,bool draw)
{
	PV3D nuevo_punto;
	GLdouble pasoRadianes= M_PI*dir/180.00;
	nuevo_punto.x= pos.x + dist*cos(pasoRadianes);
	nuevo_punto.y=pos.y;
	nuevo_punto.z=pos.z + dist*sin(pasoRadianes);
	pos=nuevo_punto;
}