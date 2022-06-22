#include<GL/freeglut.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include <math.h>

ufo(){
glPushMatrix();
glColor3f(0.6,0.7,0.6);
glTranslatef(70.0-17.45,102-35.1,0.0);
glScalef(1,0.50,1);
glutSolidSphere(14,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.6,0.6,0.6);
glTranslatef(70.0-17.45,102-35.1,0.0);
glScalef(1,0.30,1);
glutSolidSphere(18,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.7,0.7,0.6);
glTranslatef(70.0-17.45,100.0-35.1,0.0);
glScalef(1,0.24,1);
glutSolidSphere(16,100,100);
glPopMatrix();

glPushMatrix();
glColor3f(0.6,0.5,0.5);
glTranslatef(70.0-17.45,100.0-35.1,0.0);
glScalef(1,0.20,1);
glutSolidSphere(15,100,100);
glPopMatrix();
}

void ufowindow(){
glColor3f(1.0,1.0,1.0);
glPointSize(10);
glBegin(GL_POINTS);
glVertex2f(54-17.45,103-35.1);
glVertex2f(58-17.45,104-35.1);
glVertex2f(62-17.45,105-35.1);
glVertex2f(66-17.45,106-35.1);
glVertex2f(70-17.45,106.5-35.1);
glVertex2f(74-17.45,106-35.1);
glVertex2f(78-17.45,105-35.1);
glVertex2f(82-17.45,104-35.1);
glVertex2f(86-17.45,103-35.1);
glEnd();
}

void nightStars(){
glColor3f(0.9,0.7,0.1);
glPointSize(3);
glBegin(GL_POINTS);
glVertex2f(50,91);
glVertex2f(20,70);
glVertex2f(10,91);
glVertex2f(90,85);
glVertex2f(10,70);
glVertex2f(75,70);
glEnd();
}

void trees(){
glColor3f(0.7,0.3,0.1);
glBegin(GL_QUADS);
//bark1
glVertex2f(10,20);
glVertex2f(10,40);
glVertex2f(14,40);
glVertex2f(14,20);

//bark2
glVertex2f(80,20);
glVertex2f(80,40);
glVertex2f(84,40);
glVertex2f(84,20);

//bark3
glVertex2f(30,30);
glVertex2f(30,50);
glVertex2f(34,50);
glVertex2f(34,30);

//bark4
glVertex2f(50,30);
glVertex2f(50,50);
glVertex2f(54,50);
glVertex2f(54,30);

//bark5
glVertex2f(60,30);
glVertex2f(60,50);
glVertex2f(64,50);
glVertex2f(64,30);

//bark6
glVertex2f(20,32);
glVertex2f(20,60);
glVertex2f(24,60);
glVertex2f(24,32);

//bark7
glVertex2f(4,32);
glVertex2f(4,57);
glVertex2f(8,57);
glVertex2f(8,32);

//bark8
glVertex2f(38.5,32);
glVertex2f(38.5,57);
glVertex2f(42.5,57);
glVertex2f(42.5,32);

//bark9
glVertex2f(70,32);
glVertex2f(70,57);
glVertex2f(74,57);
glVertex2f(74,32);

//bark10
glVertex2f(94,32);
glVertex2f(94,57);
glVertex2f(98,57);
glVertex2f(98,32);
glEnd();

//leafs1
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(80.0,40.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(85.0,42.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(82.0,45.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

//leafs2
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(8.0,40.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(15.0,42.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(12.0,45.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

//leafs3
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(28.0,47.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(33.0,48.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(31.0,51.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

//leafs4
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(58.0,47.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(63.0,48.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(61.0,51.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

//leafs5
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(49.0,52.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(55.0,56.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(52.0,54.0,0.0);
glutSolidSphere(6,200,200);
glPopMatrix();

//leafs6
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(18.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(23.0,58.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(20.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

//leafs7
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(3.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(9.0,58.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(6.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

//leafs8
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(37.5,59.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(42.5,59.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(40.0,62.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

//leafs9
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(69.5,59.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(76.5,59.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(72.5,62.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

//leafs10
glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(93.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(99.0,58.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.0,0.4,0.3);
glTranslatef(96.0,54.0,0.0);
glutSolidSphere(7,200,200);
glPopMatrix();
}

void moon(){
glPushMatrix();
glColor3f(1.0,1.0,1.0);
glTranslatef(70.0,90.0,0.0);
glScalef(1,0.9,1);
glutSolidSphere(4,200,200);
glPopMatrix();
}

void mountains(){
glPushMatrix();
glColor3f(0.4,0.1,0.0);
glTranslatef(10.0,30.0,0.0);
glScalef(1,0.3,1);
glutSolidSphere(25,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.4,0.1,0.0);
glTranslatef(40.0,30.0,0.0);
glScalef(1,0.5,1);
glutSolidSphere(25,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.4,0.1,0.0);
glTranslatef(70.0,30.0,0.0);
glScalef(1,0.5,1);
glutSolidSphere(25,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.4,0.1,0.0);
glTranslatef(85.0,30.0,0.0);
glScalef(1,0.5,1);
glutSolidSphere(25,200,200);
glPopMatrix();
}

void beam(){
	glColor3f(0.1,0.9,0.9);
	
	glBegin(GL_POLYGON);
		glVertex2f(44,70);
		glVertex2f(62,70);
		glVertex2f(68,10);
		glVertex2f(38,10);
	glEnd();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.3);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
mountains();
//grassland
glBegin(GL_POLYGON);
glColor3f(0.0,0.3,0.0);
glVertex2f(0,0);
glColor3f(0.1,0.4,0.0);

glVertex2f(0,35);
glColor3f(0.2,0.5,0.0);

glVertex2f(100,35);
glColor3f(0.3,0.6,0.0);

glVertex2f(100,0);
glEnd();
moon();
nightStars();
trees();
beam();
ufo();
ufowindow();
    glFlush();
}

int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(1,1);
glutCreateWindow("Scene 4");
glClearColor(0.0,0.0,0.1,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
glutDisplayFunc(display);

glutMainLoop();
return 0;
}
