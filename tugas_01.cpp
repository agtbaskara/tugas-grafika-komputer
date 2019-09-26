//Baskara - 16/398499/PA/17460

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

void drawcircle(int x, int y, int r){
	float i = 0;
	while(i<=x+r){
		float t = (sqrt(pow(r,2)-pow((i-x),2)));
			glVertex2f(i, y+t);
			glVertex2f(i, y-t);
		i+=0.001; //step
	}
}

void drawline(float x1, float y1, float x2, float y2){
	float dx = x2 - x1; 
    float dy = y2 - y1; 
  
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    float X = x1; 
    float Y = y1; 
    for (float i = 0; i <= steps; i++) { 
        glVertex2f(X, Y);
        X += Xinc;
        Y += Yinc;
    } 
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	int x1 = 400;
	int y1 = 800;
	int r1 = 200;

	int x2 = 640;
	int y2 = 150;
	int r2 = 150;
	
	glBegin(GL_POINTS);

	//Lingkaran 1 (x1,y1)
	drawcircle(x1, y1, r1);

	//Lingkaran 2 (x2,y2)
	drawcircle(x2, y2, r2);

	//Tangent Line
	float distance = 0;
	float alpha = 0;
	float beta = 0;
	float gamma = 0;
	
	distance = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

	if(x1<x2){
		alpha = abs((3.14159265358979323846 / 180.0)*(atan((y2-y1)/(x2-x1))));
	}else{
		alpha = 180 - abs((3.14159265358979323846 / 180.0)*(atan((y2-y1)/(x2-x1))));
	}

	beta = abs((3.14159265358979323846 / 180.0)*(asin((r1+r2)/distance)));
	gamma = alpha - beta;

	float x1_tan = x1-(r1*cos((180.0 / 3.14159265358979323846)*(gamma)));
	float y1_tan = y1-(r1*sin((180.0 / 3.14159265358979323846)*(gamma)));
	float x2_tan = x2+(r2*cos((180.0 / 3.14159265358979323846)*(gamma)));
	float y2_tan = y2+(r2*sin((180.0 / 3.14159265358979323846)*(gamma)));

    drawline(x1_tan, y1_tan, x2_tan, y2_tan);

	glEnd();
	glFlush();
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Tugas 01");
	glutInitWindowSize(1000, 1000);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 1000);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}