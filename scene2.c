#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
float x=0,y=0,z=1;

void timer1(int v){
    if(x<10&&y<10)
    {
    	x=x+0.0075;
	    y=y-0.1;
	    
    }
    
    if(z==3)
        z=1;
    else
    z=3;
	glutPostRedisplay();
 	glutTimerFunc(50,timer1,0);
}


void stars(){
		   glPointSize(z);

	glColor3f(1.0,1.0,0.9);
	//glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(30+x,91+y);
	glVertex2f(20+x,10+y);
	glVertex2f(80+x,91+y);
	glVertex2f(90+x,85+y);
	glVertex2f(20+x,10+y);
	glVertex2f(75+x,70+y);
	glVertex2f(5+x,85+y);
	glVertex2f(90+x,15+y);
	glVertex2f(2+x,15+y);
	glVertex2f(70+x,15+y);
	glVertex2f(90+x,35+y);
	glVertex2f(50+x,85+y);
	glEnd();		
}

ufo(){
	glPushMatrix();
	glColor3f(0.6,0.6,0.6);
	glTranslatef(70.0+y,80.8+y,0.0);
	glScalef(1,0.4,1);
	glutSolidSphere(6,200,200);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.7,0.7,0.6);
	glTranslatef(70.0+y,80.0+y,0.0);
	glScalef(1,0.20,1);
	glutSolidSphere(8,200,200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6,0.6,0.5);
	glTranslatef(70.0+y,80.0+y,0.0);
	glScalef(1,0.20,1);
	glutSolidSphere(8,200,200);
	glPopMatrix();	
}

void ufowindow(){
	glColor3f(1.0,1.0,1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(64+y,80+y);
	glVertex2f(66+y,80+y);
	glVertex2f(68+y,80+y);
	glVertex2f(70+y,80+y);
	glVertex2f(72+y,80+y);
	glVertex2f(74+y,80+y);
	glVertex2f(76+y,80+y);
	glEnd();		
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	stars();
	glColor3f(0.0,0.2,0.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(40.0+(0.25*x),40.0-(0.5*y),0.0);
	glRotatef(0-x,0,1,0); 
	glutSolidSphere(28,100,100);
	glPopMatrix();
	stars();
	ufo();
	ufowindow();
    glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	glutCreateWindow("Scene 1");
	glClearColor(0.0,0.0,0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(display);
	timer1(0);
	glutMainLoop();
	return 0;	
}



