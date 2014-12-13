#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265f

char title[] = "Bouncing Ball (2D)";
int windowWidth  = 640;
int windowHeight = 480;
int windowPosX   = 50;
int windowPosY   = 50;

GLfloat ballRadius = 0.25f;
GLfloat xPos = 0.0f;
GLfloat yPos = 0.0f;
GLfloat xPosMax, xPosMin, yPosMax, yPosMin;
GLdouble xLeft, xRight, yBottom, yTop;
GLfloat xSpeed = 0.02f;
GLfloat ySpeed = 0.007f;
int refreshMillis = 30;

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0);
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glLoadIdentity();
   glTranslatef(xPos, yPos, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex2f(0.0f, 0.0f);
	  int numSegments = 100;
	  GLfloat angle;
	  for (int i = 0; i <= numSegments; i++)
	  {
		 angle = i * 2.0f * PI / numSegments;
		 glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	  }
   glEnd();

   glutSwapBuffers();

   xPos += xSpeed;
   yPos += ySpeed;

   if (xPos > xPosMax) {
	  xPos = xPosMax;
	  xSpeed = -xSpeed;
   } else if (xPos < xPosMin) {
	  xPos = xPosMin;
	  xSpeed = -xSpeed;
   }
   if (yPos > yPosMax) {
	  yPos = yPosMax;
	  ySpeed = -ySpeed;
   } else if (yPos < yPosMin) {
	  yPos = yPosMin;
	  ySpeed = -ySpeed;
   }
}


void reshape(GLsizei weight, GLsizei height) {
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)weight / height;

   glViewport(0, 0, weight, height);


   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (weight <= height) {
	  xLeft   = -1.0;
	  xRight  = 1.0;
	  yBottom = -1.0 / aspect;
	  yTop    = 1.0 / aspect;
   } else {
	  xLeft   = -1.0 * aspect;
	  xRight  = 1.0 * aspect;
	  yBottom = -1.0;
	  yTop    = 1.0;
   }
   gluOrtho2D(xLeft, xRight, yBottom, yTop);
   xPosMin = xLeft + ballRadius;
   xPosMax = xRight - ballRadius;
   yPosMin = yBottom + ballRadius;
   yPosMax = yTop - ballRadius;


   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(windowWidth, windowHeight);
   glutInitWindowPosition(windowPosX, windowPosY);
   glutCreateWindow(title);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutTimerFunc(0, Timer, 0);
   initGL();
   glutMainLoop();
   return 0;
}
