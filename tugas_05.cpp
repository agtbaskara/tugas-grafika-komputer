//Baskara - 16/398499/PA/17460

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
    glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
  glEnd();

  glFlush();
}

void init() {
  glClearColor(0, 0, 0, 0);
  glColor3f(1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-2, 2, -1.5, 1.5, 1, 40);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3);
  glRotatef(20, 1, 0, 0);
  glRotatef(40, 0, 1, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
    glutCreateWindow("Tugas 05");
	glutDisplayFunc(display);
    init();
	glutMainLoop();
	return 0;
}