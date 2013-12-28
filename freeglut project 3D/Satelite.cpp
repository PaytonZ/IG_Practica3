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
}

void Satelite :: dibujaAspas()
{
	aspas1->dibuja();
	aspas2->dibuja();
}