#include <stdlib.h>
#include <stdio.h>

#include "GL/freeglut.h"

static GLfloat width = 1024, height = 768;
static GLfloat zoom = 1, scale = 12;
static GLfloat angle_x = 0, angle_y = 0;
static GLfloat translate_x = 0, translate_y = 0;

void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, GLint x, GLint y);

void drawBox(void);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GL OGlut");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return EXIT_SUCCESS;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	if ((-1 * height / scale) < -1)
		gluLookAt(zoom, zoom, zoom * -1 * height / scale, 0 * zoom, 0 * zoom, 9999, 0, 1, 1);

	glRotatef(angle_x, 1, 0, 0);
	glRotatef(angle_y, 0, 1, 0);
	glTranslatef(translate_x, 0, 0);
	glTranslatef(0, translate_y, 0);
	drawBox();

	glFlush();
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	width = w;	height = h;
	glViewport(0, 0, width, height); 

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75, width / height, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard(unsigned char key, GLint x, GLint y)
{
	switch (key)
	{
	case '\033':
		exit(0);
		break;
	case '2':
		angle_x += 10;
		break;
	case '8':
		angle_x -= 10;
		break;
	case '4':
		angle_y += 10;
		break;
	case '6':
		angle_y -= 10;
		break;
	case '1':
		translate_x += 10;
		break;
	case '7':
		translate_x -= 10;
		break;
	case '3':
		translate_y += 10;
		break;
	case '9':
		translate_y -= 10;
		break;
	case '+':
		zoom += 0.01;
		break;
	case '-':
		zoom -= 0.01;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void drawBox(void)
{
	glBegin(GL_POLYGON);
	{
		glColor3f(255, 0, 255);
		glVertex3f(0.5 * scale, -0.5 * scale, -0.5 * scale);
		glVertex3f(0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(-0.5 * scale, -0.5 * scale, -0.5 * scale);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(255, 0, 0);
		glVertex3f(0.5 * scale, -0.5 * scale, 0.5 * scale);
		glVertex3f(0.5 * scale, 0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, -0.5 * scale, 0.5 * scale);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(0, 255, 0);
		glVertex3f(0.5 * scale, -0.5 * scale, -0.5 * scale);
		glVertex3f(0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(0.5 * scale, 0.5 * scale, 0.5 * scale);
		glVertex3f(0.5 * scale, -0.5 * scale, 0.5 * scale);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(0, 0, 255);
		glVertex3f(-0.5 * scale, -0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(-0.5 * scale, -0.5 * scale, -0.5 * scale);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(255, 255, 0);
		glVertex3f(0.5 * scale, 0.5 * scale, 0.5 * scale);
		glVertex3f(0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, -0.5 * scale);
		glVertex3f(-0.5 * scale, 0.5 * scale, 0.5 * scale);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glColor3f(0, 255, 255);
		glVertex3f(0.5 * scale, -0.5 * scale, -0.5 * scale);
		glVertex3f(0.5 * scale, -0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, -0.5 * scale, 0.5 * scale);
		glVertex3f(-0.5 * scale, -0.5 * scale, -0.5 * scale);
	}
	glEnd();
}