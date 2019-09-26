//Baskara - 16/398499/PA/17460

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void drawtriangle(float ax, float ay, float bx, float by, float cx, float cy){
    glBegin(GL_LINES);
        glVertex2f(ax, ay);
        glVertex2f(bx, by);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(bx, by);
        glVertex2f(cx, cy);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(cx, cy);
        glVertex2f(ax, ay);
    glEnd();
}

void drawline(float ax, float ay, float bx, float by){
    glBegin(GL_LINES);
        glVertex2f(ax, ay);
        glVertex2f(bx, by);
    glEnd();
}

float mirror_x(float a, float b, float ax, float ay, float bx, float by){
    float p = ay - by;
    float q = bx - ax;
    float r = ax*by-bx*ay;

    float x = (a*q*q-b*p*q-p*r)/(p*p+q*q);
    float y = (q/p)*((a*q*q-b*p*q-p*r)/(p*p+q*q))+((b*p-a*q)/p);

    float jarak_x = abs(a-x);
    float jarak_y = abs(b-y);

    return abs(x+jarak_x);
}

float mirror_y(float a, float b, float ax, float ay, float bx, float by){
    float p = ay - by;
    float q = bx - ax;
    float r = ax*by-bx*ay;

    float x = (a*q*q-b*p*q-p*r)/(p*p+q*q);
    float y = (q/p)*((a*q*q-b*p*q-p*r)/(p*p+q*q))+((b*p-a*q)/p);
    
    float jarak_x = abs(a-x);
    float jarak_y = abs(b-y);

    return abs(y+jarak_y);
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    int px = 10;
    int py = 50;
    int qx = 10;
    int qy = 80;
    int rx = 30;
    int ry = 50;
 
	drawtriangle(px, py, qx, qy, rx, ry);

    int ax = 40;
    int ay = 0;
    int bx = 55;
    int by = 100;

    drawline(ax, ay, bx, by);

    float mirror_px = mirror_x(px, py, ax, ay, bx, by);
    float mirror_py = mirror_y(px, py, ax, ay, bx, by);
    float mirror_qx = mirror_x(qx, qy, ax, ay, bx, by);
    float mirror_qy = mirror_y(qx, qy, ax, ay, bx, by);
    float mirror_rx = mirror_x(rx, ry, ax, ay, bx, by);
    float mirror_ry = mirror_y(rx, ry, ax, ay, bx, by);

    cout << mirror_px << mirror_py << mirror_qx << mirror_qy << mirror_rx << mirror_ry << endl;
    drawtriangle(mirror_px, mirror_py, mirror_qx, mirror_qy, mirror_rx, mirror_ry);
 
	glFlush();
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Tugas 03 - Baskara");
	glutInitWindowSize(100, 100);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 100, 0, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}