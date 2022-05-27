#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>

void output(char *s)
{
	int k;
	for(k=0;k<strlen(s);k++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glRasterPos3f(14.0,90.0,0.0);
	output("MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
	glRasterPos3f(16.0,80.0,0.0);
	output("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
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
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(1,1);
	glutCreateWindow("Alien UFO");
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;	
}
