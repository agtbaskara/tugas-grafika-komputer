//#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	int x1 = 150;
	int y1 = 150;
	int x2 = 0;
	int y2 = 0;
	int r = 100;
	int l = 0;
	float step = 0.001;
	
	glBegin(GL_POINTS);

	//Lingkaran 1 (x1,y1)
	float i = 0;
	while(i<=x1+2*r){
		int t = (sqrt(r*r-(i-x1)*(i-x1)));
			glVertex2f(i, y1+t);
			glVertex2f(i, y1-t);
		i+=step;
		//std::cout << i << std::endl;
	}

	//Lingkaran 2 (x2,y2)
	float j = 0;
	while(j<=x2+2*r){
		int t = (sqrt(r*r-(j-x2)*(j-x2)));
			glVertex2f(j, y2+t);
			glVertex2f(j, y2-t);
		j+=step;
		//std::cout << j << std::endl;
	}

	//Tangent Line
	//--TO-DO--

	glEnd();
	glFlush();
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 1000);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;
}