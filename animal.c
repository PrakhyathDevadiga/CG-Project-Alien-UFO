#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
int m=0;
int i;
int points; 
GLdouble delTheta;
GLdouble theta;
#define PI 3.1416

void circle(GLdouble rad)
{
     points = 50;
     delTheta = (2.0 * PI) / (GLdouble)points;
     theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}
 
void hare()
{
    /**-----------Head------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 360 + 2 * m, 245 + 100, 1);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScalef(.5, .7, .5);
    glTranslatef(110 + 350 + 2 * m, 245 + 100, 1);
    circle(5);
    glPopMatrix();
    
    /**-----------Neck-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(210 + 360 + 2 * m, 180 + 100, 1);
    glRotatef(20, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-70, 90, 1);
    glVertex3f(-70, 50, 1);
    glVertex3f(-50, 50, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    
    /**-----------Leg1-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(230 + 350 + 2 * m, 110 + 100, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();
    
    /**-----------LEg2-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 345 + 2 * m, 110 + 100, 1);
    //glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-80, 90, 1);
    glVertex3f(-85, 70, 1);
    glVertex3f(-45, 70, 1);
    glVertex3f(-50, 90, 1);
    glEnd();
    glPopMatrix();

    /**-----------Body-----------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 200 + 2 * m, 120 + 200, 1);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 270 + 2 * m, 110 + 215, 1);
    circle(35);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 350 + 2 * m, 110 + 100, 1);
    //glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-80, 150, 1);
    glVertex3f(-85, 80, 1);
    glVertex3f(-145, 80, 1);
    glVertex3f(-150, 130, 1);
    glEnd();
    glPopMatrix();
    
    /**tail**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 350 + 2 * m, 110 + 100, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(-55, 110);
    glVertex2i(-30, 120);
    glVertex2i(-55, 90);
    glEnd();
    glPopMatrix();
    
    /**ear**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(300 + 235 + 2 * m, 110 + 145, 1);
    glBegin(GL_TRIANGLES);
    glVertex2i(-55, 110);
    glVertex2i(-25, 120);
    glVertex2i(-55, 90);

    glVertex2i(-55, 110);
    glVertex2i(-25, 135);
    glVertex2i(-55, 90);
    glEnd();
    glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.3);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();		
	hare();
    glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	glutCreateWindow("Scene 2");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500.0,500.0,-500.0,500.0,-500.0,500.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;	
}


