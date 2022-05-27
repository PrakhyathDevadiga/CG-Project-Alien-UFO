#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
float x=0,y=0;

void timer1(int v){
    if(x<50.0&&y<10)
    {
    	x=x+0.1;
	    y=y-0.1;
    }
	glutPostRedisplay();
 	glutTimerFunc(50,timer1,0);
}


void stars(){
	glColor3f(0.9,0.7,0.1);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(30+x,91);
	glVertex2f(20,10-y);
	glVertex2f(80+x,91);
	glVertex2f(90,85-y);
	glVertex2f(20+x,10);
	glVertex2f(75,70-y);
	glVertex2f(5+x,85-y);
	glVertex2f(90+x,15);
	glVertex2f(2,15-y);
	glVertex2f(70,15+y);
	glVertex2f(90-x,35);
	glVertex2f(50,85-y);
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
	glColor3f(0.2,0.7,0.9);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(40.0+(0.25*x),40.0-(0.5*y),0.0);
	glRotatef(0-x,0,1,0); 
	glutWireSphere(28+(0.5*x),100,100);
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
