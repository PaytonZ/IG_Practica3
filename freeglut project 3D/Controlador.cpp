#include "Controlador.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

void Controlador::key(unsigned char key, int x, int y){
        bool need_redisplay = true;
        switch (key) {
                case 27: /* Escape key */
                        //continue_in_main_loop = false; // (**)
                        //Freeglut's sentence for stopping glut's main loop (*)
                        glutLeaveMainLoop ();
                        break;                                         
                default:
                        need_redisplay = false;
                        break;
        }

        if (need_redisplay)
                glutPostRedisplay();
}