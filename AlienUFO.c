#include<GL/freeglut.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>

void output(char *s);
void continueString(char *s);
void display();
void keyboard(unsigned char key,int x, int y);

void ufoTimer(int v);
void spaceStars();
void ufo();
void ufowindow();
void intro();
void scene1();
void scene1Display();

void incomingUfoTimer(int v);
void incomingUfo();
void incomingUfowindow();
void nightStars();
void trees();
void moon();
void mountains();
void circle(GLdouble rad);
void hare();
void rabbit();
void Hare();
void scene2();
void scene2Display();

void hoveringUfo();
void hoveringUfowindow();
void beam();
void beamTimer();
void scene3();
void scene3Display();

void scene4();
void scene4Display();

void outgoingTimer(int v);
void scene5();
void scene5Display();

//void ending();

int window;

float ufoX=0,ufoY=0,ufoZ=1;

int z=0;
float incomingUfoX=0,incomingUfoY=0;
int m=0;
int i,beamCount=0;
int points; 
GLdouble delTheta;
GLdouble theta;
#define PI 3.1416
float rabbitY=0;

float count=0;

float outgoingUfoX=0,outgoingUfoY=0;

void output(char *s)
{
	int k;
	for(k=0;k<strlen(s);k++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
}

void continueString(char *s){
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glRasterPos3f(77.0,10.0,0.0);
	output(s);
	glPopMatrix();
	glFlush();
	
}

void ufoTimer(int v){
    if(ufoX<20&&ufoY<5)
    {
    	ufoX=ufoX+0.0075;
	    ufoY=ufoY-0.01;
	    
    }
    
    if(ufoZ==3)
        ufoZ=1;
    else
    ufoZ=3;
	glutPostRedisplay();
 	glutTimerFunc(500,ufoTimer,0);
}

void incomingUfoTimer(int v){
    if(incomingUfoY<=35)
    {
    	incomingUfoX=incomingUfoX-0.05;
	    incomingUfoY=incomingUfoY+0.1; 
	   
    }
	glutPostRedisplay();
 	glutTimerFunc(500,incomingUfoTimer,0);
}

void beamTimer(int v){
	beamCount++;
	if(beamCount>75){
		beam();
    	hoveringUfo();
		hoveringUfowindow();
    	rabbit();
	}
	glutPostRedisplay();
 	glutTimerFunc(15,beamTimer,0);
}

void rabbitTimer(){
	//printf("%f",rabbitY);
	count++;
	if(count>8 && count<=65){
		rabbitY+=0.9;
	}
	glutPostRedisplay();
}

void outgoingTimer(int v){
    if(outgoingUfoY<=45)
    {
    	outgoingUfoX=outgoingUfoX-0.05;
	    outgoingUfoY=outgoingUfoY+0.1; 
	   
    }
	glutPostRedisplay();
 	glutTimerFunc(50,outgoingTimer,0);
}

void spaceStars(){
	glPointSize(ufoZ);

	glColor3f(1.0,1.0,0.9);
	//glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(30,91);
	glVertex2f(20,10);
	glVertex2f(80,91);
	glVertex2f(90,85);
	glVertex2f(20,10);
	glVertex2f(75,70);
	glVertex2f(5,85);
	glVertex2f(90,15);
	glVertex2f(2,15);
	glVertex2f(70,15);
	glVertex2f(90,35);
	glVertex2f(50,85);
	glEnd();		
}

void ufo(){
	glPushMatrix();
	glColor3f(0.6,0.6,0.6);
	glTranslatef(70.0+ufoY,80.8+ufoY,0.0);
	glScalef(1,0.4,1);
	glutSolidSphere(6,200,200);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7,0.7,0.6);
	glTranslatef(70.0+ufoY,80.0+ufoY,0.0);
	glScalef(1,0.20,1);
	glutSolidSphere(8,200,200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6,0.6,0.5);
	glTranslatef(70.0+ufoY,80.0+ufoY,0.0);
	glScalef(1,0.20,1);
	glutSolidSphere(8,200,200);
	glPopMatrix();	
}

void ufowindow(){
	glColor3f(1.0,1.0,1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(64+ufoY,80+ufoY);
	glVertex2f(66+ufoY,80+ufoY);
	glVertex2f(68+ufoY,80+ufoY);
	glVertex2f(70+ufoY,80+ufoY);
	glVertex2f(72+ufoY,80+ufoY);
	glVertex2f(74+ufoY,80+ufoY);
	glVertex2f(76+ufoY,80+ufoY);
	glEnd();		
}

void incomingUfo(){
	glPushMatrix();
	glColor3f(0.6,0.7,0.6);
	glTranslatef(70.0+incomingUfoX,102-incomingUfoY,0.0);
	glScalef(1,0.50,1);
	glutSolidSphere(14,200,200);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.6,0.6,0.6);
	glTranslatef(70.0+incomingUfoX,102-incomingUfoY,0.0);
	glScalef(1,0.30,1);
	glutSolidSphere(18,200,200);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7,0.7,0.6);
	glTranslatef(70.0+incomingUfoX,100.0-incomingUfoY,0.0);
	glScalef(1,0.24,1);
	glutSolidSphere(16,100,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6,0.5,0.5);
	glTranslatef(70.0+incomingUfoX,100.0-incomingUfoY,0.0);
	glScalef(1,0.20,1);
	glutSolidSphere(15,100,100);
	glPopMatrix();	
}

void incomingUfowindow(){
	glColor3f(1.0,1.0,1.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(54+incomingUfoX,103-incomingUfoY);
	glVertex2f(58+incomingUfoX,104-incomingUfoY);
	glVertex2f(62+incomingUfoX,105-incomingUfoY);
	glVertex2f(66+incomingUfoX,106-incomingUfoY);
	glVertex2f(70+incomingUfoX,106.5-incomingUfoY);
	glVertex2f(74+incomingUfoX,106-incomingUfoY);
	glVertex2f(78+incomingUfoX,105-incomingUfoY);
	glVertex2f(82+incomingUfoX,104-incomingUfoY);
	glVertex2f(86+incomingUfoX,103-incomingUfoY);
	glEnd();		
}

void nightStars(){
	glColor3f(0.9,0.7,0.1);
	glPointSize(3+z);
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
	glColor3f(0.9,1.0,0.1);

	glBegin(GL_POLYGON);
	
		glVertex2f(44,70);
		glColor3f(0.9,1.0,0.2);
		glVertex2f(62,70);
		glColor3f(0.9,1.0,0.6);
		glVertex2f(68,10);
		glColor3f(0.9,1.0,0.7);
		glVertex2f(38,10);
	glEnd();
}

void hoveringUfo(){
glPushMatrix();
glColor3f(0.6,0.7,0.6);
glTranslatef(70.0-17.45+outgoingUfoX,102-35.1+outgoingUfoY,0.0);
glScalef(1,0.50,1);
glutSolidSphere(14,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.6,0.6,0.6);
glTranslatef(70.0-17.45+outgoingUfoX,102-35.1+outgoingUfoY,0.0);
glScalef(1,0.30,1);
glutSolidSphere(18,200,200);
glPopMatrix();

glPushMatrix();
glColor3f(0.7,0.7,0.6);
glTranslatef(70.0-17.45+outgoingUfoX,100.0-35.1+outgoingUfoY,0.0);
glScalef(1,0.24,1);
glutSolidSphere(16,100,100);
glPopMatrix();

glPushMatrix();
glColor3f(0.6,0.5,0.5);
glTranslatef(70.0-17.45+outgoingUfoX,100.0-35.1+outgoingUfoY,0.0);
glScalef(1,0.20,1);
glutSolidSphere(15,100,100);
glPopMatrix();
}

void hoveringUfowindow(){
glColor3f(1.0,1.0,1.0);
glPointSize(10);
glBegin(GL_POINTS);
glVertex2f(54-17.45+outgoingUfoX,103-35.1+outgoingUfoY);
glVertex2f(58-17.45+outgoingUfoX,104-35.1+outgoingUfoY);
glVertex2f(62-17.45+outgoingUfoX,105-35.1+outgoingUfoY);
glVertex2f(66-17.45+outgoingUfoX,106-35.1+outgoingUfoY);
glVertex2f(70-17.45+outgoingUfoX,106.5-35.1+outgoingUfoY);
glVertex2f(74-17.45+outgoingUfoX,106-35.1+outgoingUfoY);
glVertex2f(78-17.45+outgoingUfoX,105-35.1+outgoingUfoY);
glVertex2f(82-17.45+outgoingUfoX,104-35.1+outgoingUfoY);
glVertex2f(86-17.45+outgoingUfoX,103-35.1+outgoingUfoY);
glEnd();
}

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
    glScalef(0.6,0.5,1);
    glTranslatef(146,38,0);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScalef(0.6,0.5,0);
    glTranslatef(145,38.5,0);
    circle(1);
    glPopMatrix();
    
    /**-----------Neck-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.6,0.6,0);
    glTranslatef(96,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,30,0);
    glVertex3f(50,34,0);
    glVertex3f(54,30,0);
    glVertex3f(54,27,0);
    glEnd();
    glPopMatrix();
    
    /**-----------Leg1-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(127,-7,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,30,0);
    glVertex3f(51,33,0);
    glVertex3f(54,33,0);
    glVertex3f(55,30,0);
    glEnd();
    glPopMatrix();
    
    /**-----------LEg2-----------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(132,-7,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,30,0);
    glVertex3f(51,33,0);
    glVertex3f(54,33,0);
    glVertex3f(55,30,0);
    glEnd();
    glPopMatrix();

    /**-----------Body-----------------**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.6,0.5,1);
    glTranslatef(149,36.5,0);
    circle(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.7,0.6,1);
    glTranslatef(131,32,0);
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(128,-5,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,30,0);
    glVertex3f(50,33,0);
    glVertex3f(56,35.5,0);
    glVertex3f(56,29,0);
    glEnd();
    glPopMatrix();
    
    /**tail**/
     glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(135,-3,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,30,0);
    glVertex3f(50,27,0);
    glVertex3f(55,31.5,0);
    glEnd();
    glPopMatrix();
    /**ear**/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(126,-2,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,31.5,0);
    glVertex3f(53,34,0);
    glVertex3f(51,30,0);
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(125,-2,0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(125,-2,0);
    glBegin(GL_POLYGON);
    glVertex3f(50,31.5,0);
    glVertex3f(51,34,0);
    glVertex3f(51,30,0);
    glColor3f(1, 1, 1);
    glScalef(.5, .7, .5);
    glTranslatef(125,-2,0);
    glEnd();
    glPopMatrix();
}

void rabbit(){
	//body
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(53.0,14+rabbitY,0.0);
	glScalef(0.4,0.8,1);
	glutSolidSphere(5,200,200);
	glPopMatrix();

	//head
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(53.0,16.0+rabbitY,0.0);
	//glScalef(1,0.8,1);
	glutSolidSphere(2.3,200,200);
	glPopMatrix();

	//First leg
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(52.0,10.0+rabbitY,0.0);
	glScalef(1,0.8,1);
	glutSolidSphere(0.8,200,200);
	glPopMatrix();

	//Second leg
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(54.0,10.0+rabbitY,0.0);
	glScalef(1,0.8,1);
	glutSolidSphere(0.8,200,200);
	glPopMatrix();

	//Tail
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(55.0,12+rabbitY,0.0);
	//glScalef(1,0.8,1);
	glutSolidSphere(0.7,200,200);
	glPopMatrix();

	//Eyes
	glColor3f(0.0,0.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(52.3,16+rabbitY);
		glVertex2f(53.7,16+rabbitY);
	glEnd();

	//Ear right
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(54.0,18.4+rabbitY,0.0);
	glScalef(0.5,0.9,1);
	glutSolidSphere(1.5,200,200);
	glPopMatrix();

	//Ear left
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(52.0,18.4+rabbitY,0.0);
	glScalef(0.5,0.9,1);
	glutSolidSphere(1.5,200,200);
	glPopMatrix();
}

void Hare() {

	float x,y;
	float t;

	//Rabbit
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(5,21+4);
	glVertex2i(6,21+4);
	glVertex2i(7,22+4);
	glVertex2i(7,23+4);
	glVertex2i(6,24+4);
	glVertex2i(5,24+4);
	glVertex2i(4,23+4);
	glVertex2i(4,22+4);
	glEnd();

	glBegin(GL_LINES);
	for(t=0;t<=36;t++) {
		x=7.8+0.9*cos(t);
		y=27.3+0.9*sin(t);
		glVertex2f(7,26);
		glVertex2f(x,y);
	}
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(7.8,27.3);
	glEnd();

	//Rabbit Ears
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(t=0;t<=36;t++) {
		x=7.4+0.4*cos(t);
		y=29.5+0.4*sin(t);
		glVertex2f(7,27);
		glVertex2f(x,y);
	}
	glEnd();
}

void intro(){
	glColor3f(0.3,0.0,1.0);
	glPushMatrix();
	glRasterPos3f(14.0,90.0,0.0);
	output("MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
	glRasterPos3f(16.0,80.0,0.0);
	output("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glRasterPos3f(43.0,65.0,0.0);
	output("CG PROJECT ON");
	glRasterPos3f(45.0,60.0,0.0);
	output("ALIEN UFO");
	glRasterPos3f(7.0,40.0,0.0);
	output("NITHISH");
	glRasterPos3f(5.0,36.0,0.0);
	output("4MT19CS098");
	glRasterPos3f(65.0,40.0,0.0);
	output("PRAKHYATH B DEVADIGA");
	glRasterPos3f(73.0,36.0,0.0);
	output("4MT19CS109");
	glRasterPos3f(39.0,20.0,0.0);
	output("Under The Guidence of");
	glRasterPos3f(43.0,15.0,0.0);
	output("SUNITHA N V");
	glPopMatrix();
	
	continueString("Press B to continue");
	
	glFlush();
}

void scene1(){
	glutDestroyWindow(window);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Scene 1");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(scene1Display);
	glutKeyboardFunc(keyboard);
}

void scene1Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	spaceStars();
	glColor3f(0.0,0.2,0.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(40.0,40.0,0.0);
	glRotatef(0-ufoX,0,1,0); 
	glutSolidSphere(28,100,100);
	glPopMatrix();
	//spaceStars();
	ufo();
	ufowindow();
	ufoTimer(0);
	continueString("Press C to continue");
    glFlush();
}

void scene2(){
	glutDestroyWindow(window);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Scene 2");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(scene2Display);
	glutKeyboardFunc(keyboard);
}

void scene2Display(){
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
	incomingUfo();
	incomingUfowindow();
    hare();
    Hare();
    rabbit();
    incomingUfoTimer(0);
    continueString("Press D to continue");
	glFlush();
}

void scene3(){
	glutDestroyWindow(window);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Scene 3");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(scene3Display);
	glutKeyboardFunc(keyboard);
}

void scene3Display(){
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
	hoveringUfo();
	hoveringUfowindow();
    hare();
    Hare();
    rabbit();
    beamTimer(0);
    continueString("Press E to continue");
	glFlush();
}

void scene4(){
	glutDestroyWindow(window);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Scene 4");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(scene4Display);
	glutKeyboardFunc(keyboard);
}

void scene4Display(){
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
	Hare();
	beam();
	rabbit();
	hoveringUfo();
	hoveringUfowindow();
	hare();
	rabbitTimer();
	continueString("Press F to pay respects");
    glFlush();
}

void scene5(){
	glutDestroyWindow(window);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Scene 5");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(scene5Display);
	glutKeyboardFunc(keyboard);
}

void scene5Display(){
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
	hoveringUfo();
	hoveringUfowindow();
    hare();
    Hare();
    outgoingTimer(0);

  //  continueString("Press G to end");
	glFlush();
}

void ending(){
//	glutDestroyWindow(window);
//	glutInitWindowSize(1000,1000);
//	glutInitWindowPosition(1,1);
//	window=glutCreateWindow("Ending");
//	glClearColor(0.0,0.0,0.1,0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
//	glColor3f(1.0,1.0,1.0);
//	glPushMatrix();
//	glRasterPos3f(45.0,60.0,0.0);
//	output("THANKYOU");
//	glRasterPos3f(7.0,40.0,0.0);
//	output("NITHISH");
//	glRasterPos3f(5.0,36.0,0.0);
//	output("4MT19CS098");
//	glRasterPos3f(65.0,40.0,0.0);
//	output("PRAKHYATH B DEVADIGA");
//	glRasterPos3f(73.0,36.0,0.0);
//	output("4MT19CS109");
//	glPopMatrix();
//	glFlush();
//glClearColor(0.0,0.0,0.0,0.0);
//glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,1.0,1.0);
	glPushMatrix();

	glRasterPos3f(45.0,60.0,0.0);
	output("THANK YOU");
	glRasterPos3f(7.0,40.0,0.0);
	output("NITHISH");
	glRasterPos3f(5.0,36.0,0.0);
	output("4MT19CS098");
	glRasterPos3f(65.0,40.0,0.0);
	output("PRAKHYATH B DEVADIGA");
	glRasterPos3f(73.0,36.0,0.0);
	output("4MT19CS109");
	glPopMatrix();
	glFlush();
}


void keyboard(unsigned char key,int x, int y){
	if(key=='A'|key=='a')
		intro();
	
	if(key=='B'|key=='b')
		scene1();

	if(key=='C'|key=='c')
		scene2();	
	
	if(key=='D'|key=='d')
		scene3();
		
	if(key=='E'|key=='e')
		scene4();
		
	if(key=='F'|key=='f')
		scene5();
		
     if(key=='G'|key=='g')
		ending();	
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	window=glutCreateWindow("Alien UFO");
	glClearColor(1.0,0.9,0.6,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	continueString("Press A to Start");
	glutMainLoop();
	return 0;	
}
