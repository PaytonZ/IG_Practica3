/********************************************************************************
*																				*
*		Practica 1 IG - Planeta y satelite										*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <iostream>
using namespace std;

class Planeta
{
public:
	Planeta(void){
		//esfera=GLUnewQuadric();
	}
	~Planeta(void);

private:
	GLUquadricObj* esfera;
};

