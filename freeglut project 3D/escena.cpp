/********************************************************************************
*																				*
*		Practica 1 IG - Pythagoras tree											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "escena.h"
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>


extern int WIDTH, HEIGHT;
extern GLdouble F,N;
escena* escena::AVE = NULL;


void escena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

	glFlush();
	glutSwapBuffers();
}
void escena::resize(int newWidth, int newHeight){

        //Resize Viewport
        WIDTH= newWidth;
        HEIGHT= newHeight;


        GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
        glViewport ( 0, 0, WIDTH, HEIGHT ) ;

        escena *_AVE= getAVEInstance();

        //Resize Scene Visible Area
        //Se actualiza el área visible de la escena
        //para que su ratio coincida con ratioViewPort

        GLdouble SVAWidth= _AVE->getxRight()- _AVE->getxLeft();

        GLdouble SVAHeight= _AVE->getyTop()-_AVE->getyBot();
        GLdouble SVARatio= SVAWidth/SVAHeight;
        if (SVARatio >= RatioViewPort) {
                // Increase SVAHeight
                GLdouble newHeight= SVAWidth/RatioViewPort;
                GLdouble yMiddle= ( _AVE->getyBot()+_AVE->getyTop() )/2.0;
                _AVE->setyTop(( yMiddle + newHeight)/2.0);
                _AVE->setyBot ((yMiddle - newHeight)/2.0);
        }
        else {
                //Increase SVAWidth
                GLdouble newWidth= SVAHeight*RatioViewPort;
                GLdouble xMiddle= ((_AVE->getxLeft()+_AVE->getxRight() )/2.0);
                _AVE->setxRight((xMiddle + newWidth)/2.0);
                _AVE->setxLeft(( xMiddle - newWidth)/2.0);
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();


        glOrtho(_AVE->xLeft, _AVE->xRight, _AVE->yBot, _AVE->yTop, N, F);

}

GLdouble escena::getxRight() const{
        return xRight;
}
void escena::setxRight(GLdouble new_xRight){
        xRight= new_xRight;
}

GLdouble escena::getyTop() const{
        return yTop;

}

void escena::setyTop(GLdouble new_ytop){
        yTop= new_ytop;
}


GLdouble escena::getxLeft() const{
        return xLeft;
}

void escena::setxLeft(GLdouble new_xleft){

        xLeft=new_xleft;

}

GLdouble escena::getyBot() const{
        return yBot;
}

void escena::setyBot(GLdouble new_ybot )
{
        yBot=new_ybot;
}

escena* escena::getAVEInstance()
{
        if(!AVE) {
                AVE= new escena();
                atexit(escena::_AVE_deleter);
        }
        return AVE;
}

escena* escena::getAVEInstance(GLdouble new_xleft, GLdouble new_yBot , GLdouble new_xright, GLdouble new_yTop)
{
        if (!AVE)

        {
                AVE=new escena(new_xleft,new_yBot, new_xright, new_yTop);
                atexit(escena::_AVE_deleter);
        }
        return AVE;
}