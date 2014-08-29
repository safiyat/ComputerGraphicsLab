#ifdef __APPLE__ 
#include<GLUT/glut.h> 
#include<openGL/openGL.h> 

#else 
#include<GL/glut.h> 
#endif 

#include <cmath>
#include <cstdio>
float x_1=1.0,x_2=1.0;
float y_1=1.0,y_2=1.0;
float x_3=1.0;
float px=x_3;
float a1=0.0,a2=0.0,step=0.0005;

void initRendering() 
{ 
    glEnable(GL_DEPTH_TEST); 
} 

void reshape(int w,int h) 
{ 
    glViewport(0,0,w,h); 
    
    glMatrixMode(GL_PROJECTION); 
    
    glLoadIdentity(); 
    
    gluPerspective(45,w/h,1,200); 
    
} 

void keyPressed(int key,int x,int y) 
{ 
    if(key==GLUT_KEY_LEFT) 
    {} 
} 

void drawMainBall() 
{ 
    glColor3f(0.3,0.3,0.3); 
    
    glPushMatrix(); 
    
    glTranslatef(0.0,0.0,-5.0); 
    
    glutSolidSphere(0.8,120,120); 
    
    glPopMatrix(); 
    
}

void drawBalls() 
{ 
    glColor3f(0.3,1.0,0.0);
    
    glPushMatrix(); 
    
    glTranslatef(x_1,y_1,-5.0); 
    
    glutSolidSphere(0.2,20,20); 
    
    glPopMatrix(); 
    
    glColor3f(1.0,0.0,0.0); 
    
    glPushMatrix(); 
    
    glTranslatef(x_2,y_2,-5.0); 
    
    glutSolidSphere(0.2,20,20); 
    
    glPopMatrix();
    
} 

void drawWireBall()
{
    glColor3f(0.3,0.0,1.0); 
    
    glPushMatrix(); 
    
    glTranslatef(x_3,x_3,-5.0); 
    
    glutWireSphere(0.2,20,20); 
    
    glPopMatrix();
}


void update() 
{
    a1+=step;
    a2-=step;
    
    x_1=cos(a1); 
    y_1=sin(a1);
    x_2=cos(a2);
    y_2=sin(a2);
    x_3=cos(a2);
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
    
    glMatrixMode(GL_MODELVIEW); 
    
    glLoadIdentity(); 
    
    //glShadeModel(GL_SMOOTH);
    if(px>x_3)
    {
        drawMainBall();
        drawWireBall();
    }
    else
    {
        drawWireBall();
        drawMainBall();
    }
    px=x_3;
    drawBalls();
    update(); 
    
    glutSwapBuffers(); 
} 


int main(int argc,char **argv) 
{ 
    glutInit(&argc,argv); 
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 
    
    glutInitWindowSize(800,800); 
    
    glutCreateWindow("Collision Window"); 
    
    //initRendering();    //initialize 3d rendering  
    
    glutDisplayFunc(display); 
    
    glutIdleFunc(display); 
    
    glutReshapeFunc(reshape); 
    
    glutSpecialFunc(keyPressed); 
    
    glutMainLoop(); 
    
    return(0); 
}