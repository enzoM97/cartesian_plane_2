#include "GL/freeglut.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

//Initialize OpenGL 
void init(void)
{
	// color de la ventana, negro
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//  proyección de la imagen en la ventana devisualización
}

void drawSquare() {
	glBegin(GL_QUADS);
	glColor3f(0.6f, 1.0f, 0.0f);
	glVertex2f(-0.4f, -0.3f);	// v0
	glVertex2f(-0.1f, -0.3f);	// v1
	glVertex2f(-0.1f, -0.6f);	// v2
	glVertex2f(-0.4f, -0.6f);	// v3
	glEnd();
}

void drawDiamond(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 0.8f);
	glVertex2f(-0.7f, -0.5f);	// v0
	glVertex2f(-0.5f, -0.7f);	// v1
	glVertex2f(-0.7f, -0.9f);	// v2
	glVertex2f(-0.9f, -0.7f);	// v3
	glEnd();
}

void drawTriangles(void)
{	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.4);
	glVertex3f(-0.8f, 0.5f, 0.0f);	// v0
	glVertex3f(-0.6f, 0.7f, 0.0f);	// v1
	glVertex3f(-0.4f, 0.5f, 0.0f);	// v2

	glColor3f(0.2, 1.0, 0.9);
	glVertex3f(-0.2f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.4f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glEnd();
}

void drawTriangleStrip(void)
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.6f, 0.0f);	// v0
	glVertex3f(0.6f, -0.6f, 0.0f);	// v1
	glVertex3f(0.4f, -0.4f, 0.0f);	// v2

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.6f, -0.6f, 0.0f);	// v1
	glVertex3f(0.8f, -0.4f, 0.0f);	// v3
	glVertex3f(0.4f, -0.4f, 0.0f);	// v2
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.8f, -0.4f, 0.0f);	// v3
	glVertex3f(0.6f, -0.2f, 0.0f);	// v4
	glVertex3f(0.4f, -0.4f, 0.0f);	// v2
	glEnd();
}

void drawHexagon(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.7f, 0.4f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.3f, 0.4f);
	glVertex2f(0.4f, 0.2f);
	glEnd();
}

void drawCartesianPlane(void)
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	float x = -1.0, y = 1.0, z = 0.0;

	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);

	glBegin(GL_POINTS);
	for (float i = -1.0; i < 1.0; i += 0.01) {
		glBegin(GL_POINTS);
		glColor3f(x, y, z);
		glVertex2d(x, 0);
		glVertex2d(0, y);
		x += 0.02f;
		y -= 0.02f;
		z += 0.02f;
	}
	glEnd();

	// first plane
	drawHexagon();
	// second plane
	drawTriangles();
	// third plane
	drawSquare();
	drawDiamond();
	// fourth plane
	drawTriangleStrip();
	glFlush();
}

int main(int argc, char** argv)
{
	srand(GetTickCount());
	glutInit(&argc, argv); //inicializa la libreria de glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//selecciona el RGB y single buffering
	glutInitWindowSize(512, 512);//fija el tamanho de la ventana
	glutInitWindowPosition(400, 150);//fija la posicion de la ventana
	glutCreateWindow("tarea#2");//crea la ventana con el nombre							
	//Llamar a la funcion init
	init();
	//declara los callbacks
	glutDisplayFunc(drawCartesianPlane);
	//entra en el loop de reconocimientos de eventos
	glutMainLoop();
	return 0;
}
