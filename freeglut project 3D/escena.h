/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/



#pragma once
#ifndef ESCENA_H
#define ESCENA_H

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>




extern int WIDTH, HEIGHT ;


class escena
{

public:

	

	static void resize(int newWidth, int newHeight);
	static void display();
	static escena* getAVEInstance();
    static escena* getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop);
	GLdouble getxRight() const;
        void setxRight(GLdouble);

        GLdouble getxLeft() const;
        void setxLeft(GLdouble);

        GLdouble getyTop() const;
        void setyTop(GLdouble);

        GLdouble getyBot() const;
        void setyBot(GLdouble);

	

		
private:

	escena() {}
	escena(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop):
		xLeft(new_xleft) , xRight(new_xright) ,  yBot(new_yBot) , yTop(new_yTop) {
		
		
			
	}

	static escena* AVE;
	static void _AVE_deleter() { 
	delete AVE; }
			
	GLdouble xLeft;
	GLdouble xRight;

	GLdouble yBot;
	GLdouble yTop;


};

#endif // !ESCENA_H

