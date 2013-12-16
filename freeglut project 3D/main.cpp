#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
#include "Satelite.h"
#include "CirculoEspiral.h"

using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=100, xLeft=-xRight, yTop=100, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

//Satelite
Satelite* miSatelite;

//Esfera
GLUquadricObj* q;

CirculoEspiral* esp;

//Angulo movimiento satelite;
int anguloSatelite=0;

//Angulo planeta
int anguloPlaneta=0;

//X de la espiral
double xEspiral=0;

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

    // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();
	//miSatelite= new Satelite(5,10,2);
	//q=gluNewQuadric();
	//gluQuadricDrawStyle(q, GLU_LINE);

	esp = new CirculoEspiral(100,4,3);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);        
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(200, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 200, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 200);	     
	glEnd();

	
	/*glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(cos(xEspiral)+xEspiral*sin(xEspiral),0,sin(xEspiral)-xEspiral*cos(xEspiral));
	glRotatef(anguloPlaneta,0.0,-1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	gluSphere(q,20,20,20);
	glPushMatrix();
	glRotatef(anguloSatelite,0,1,0);
	glTranslatef(40,0,0);
	glRotatef(100,0,0,1);
	glColor3f(1.0,1.0,0.0);	
	miSatelite->dibuja();
	glPopMatrix();
	glPopMatrix();*/

	esp->pintar();
	
	/*glBegin(GL_LINES);
	int i=0;
			glVertex3d(esp->espiral->vertice[i]->x,esp->espiral->vertice[i]->y,esp->espiral->vertice[i]->z);
			glVertex3d(esp->espiral->vertice[i+1]->x,esp->espiral->vertice[i+1]->y,esp->espiral->vertice[i+1]->z);

			glVertex3d(esp->espiral->vertice[i+1]->x,esp->espiral->vertice[i+1]->y,esp->espiral->vertice[i+1]->z);
			glVertex3d(esp->espiral->vertice[i+2]->x,esp->espiral->vertice[i+2]->y,esp->espiral->vertice[i+2]->z);

			glVertex3d(esp->espiral->vertice[i+2]->x,esp->espiral->vertice[i+2]->y,esp->espiral->vertice[i+2]->z);
			glVertex3d(esp->espiral->vertice[i+3]->x,esp->espiral->vertice[i+3]->y,esp->espiral->vertice[i+3]->z);

			glVertex3d(esp->espiral->vertice[i+3]->x,esp->espiral->vertice[i+3]->y,esp->espiral->vertice[i+3]->z);
			glVertex3d(esp->espiral->vertice[i]->x,esp->espiral->vertice[i]->y,esp->espiral->vertice[i]->z);
	

		glVertex3d(esp->espiral->vertice[4]->x,esp->espiral->vertice[4]->y,esp->espiral->vertice[4]->z);
		glVertex3d(esp->espiral->vertice[5]->x,esp->espiral->vertice[5]->y,esp->espiral->vertice[5]->z);
		glVertex3d(esp->espiral->vertice[5]->x,esp->espiral->vertice[5]->y,esp->espiral->vertice[5]->z);
		glVertex3d(esp->espiral->vertice[6]->x,esp->espiral->vertice[6]->y,esp->espiral->vertice[6]->z);
		glVertex3d(esp->espiral->vertice[6]->x,esp->espiral->vertice[6]->y,esp->espiral->vertice[6]->z);
		glVertex3d(esp->espiral->vertice[7]->x,esp->espiral->vertice[7]->y,esp->espiral->vertice[7]->z);
		glVertex3d(esp->espiral->vertice[7]->x,esp->espiral->vertice[7]->y,esp->espiral->vertice[7]->z);
		glVertex3d(esp->espiral->vertice[4]->x,esp->espiral->vertice[4]->y,esp->espiral->vertice[4]->z);

		glVertex3d(esp->espiral->vertice[8]->x,esp->espiral->vertice[8]->y,esp->espiral->vertice[8]->z);
		glVertex3d(esp->espiral->vertice[9]->x,esp->espiral->vertice[9]->y,esp->espiral->vertice[9]->z);
		glVertex3d(esp->espiral->vertice[9]->x,esp->espiral->vertice[9]->y,esp->espiral->vertice[9]->z);
		glVertex3d(esp->espiral->vertice[10]->x,esp->espiral->vertice[10]->y,esp->espiral->vertice[10]->z);
		glVertex3d(esp->espiral->vertice[10]->x,esp->espiral->vertice[10]->y,esp->espiral->vertice[10]->z);
		glVertex3d(esp->espiral->vertice[11]->x,esp->espiral->vertice[11]->y,esp->espiral->vertice[11]->z);
		glVertex3d(esp->espiral->vertice[11]->x,esp->espiral->vertice[11]->y,esp->espiral->vertice[11]->z);
		glVertex3d(esp->espiral->vertice[8]->x,esp->espiral->vertice[8]->y,esp->espiral->vertice[8]->z);
	glEnd();*/
	
	

	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;	
		case 'a':
			anguloSatelite=(anguloSatelite+2)%360;
			anguloPlaneta=(anguloPlaneta+1)%360;
			xEspiral=xEspiral+0.1;
			display();
			break;
		case 's':
			anguloSatelite=(anguloSatelite+2)%360;
			display();
			break;
		case 'd':
			anguloPlaneta=(anguloPlaneta+1)%360;
			display();
			break;
		case 'f':
			xEspiral=xEspiral+0.1;
			display();
			break;
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;


	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}
