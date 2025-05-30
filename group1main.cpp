#include <GL/gl.h>
#include <GL/glut.h>
#include "group1game.h"
#include<stdlib.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver=false;

int score=0;

void timer_callback(int);
void display_callback();
void reshape_callback(int,int);
void keyboard_callback(int,int,int);

void init()
{
   glClearColor(0.0,0.0,0.0,1.0);
   initGrid(COLUMNS,ROWS);	
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Corrected: &argc instead of $argc
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // Corrected: glutInitDisplayMode instead of glutInitDisplsyMode
    glutInitWindowSize(500, 500);
    glutCreateWindow("SNAKE");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
     init();
    glutMainLoop(); // Added to start the GLUT event loop
   
    return 0;
}
int index=0;

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers(); // Corrected: glutSwapBuffers instead of glutSwaBuffers
    if(gameOver)
    {
    	char _score[10];
    	itoa(score,_score,10);
    	char text[50]= "your score:";
    	strcat(text,_score);
    	 MessageBox(NULL,text, "GAME OVER",0);
    	 exit(0);
	}
}
void reshape_callback(int w,int h)
{
  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
  glMatrixMode(GL_MODELVIEW);	
}
void timer_callback(int)
{
     glutPostRedisplay();
	 glutTimerFunc(1000/FPS,timer_callback,0);
}
void keyboard_callback(int key,int,int)
{
   switch(key)
   {
   	case GLUT_KEY_UP:
   		if(sDirection!=DOWN)
   		  sDirection=UP;
   		break;
   	case GLUT_KEY_DOWN:
	   if(sDirection!=UP)
	     sDirection=DOWN;
	   break;
	case GLUT_KEY_RIGHT:
	   if(sDirection!=LEFT)
	   	 sDirection=RIGHT;
	   break;
    case GLUT_KEY_LEFT:
       if(sDirection!=RIGHT)
         sDirection=LEFT;
        break;
	   }	
 } 

