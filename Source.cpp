#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
	double x;
	double y;
};

vector<Point>points;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);

	glBegin(GL_POINTS);
	for (Point& t : points)
		glVertex2f(t.x, t.y);

	glEnd();
	glFlush();
}

void setstvar() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void unosKordinata()
{
	fstream datoteka("points.txt");
	Point temp;
	while (!datoteka.eof())
	{
		datoteka >> temp.x >> temp.y;
		points.push_back(temp);
	}
}

int main(int argc, char** argv) {

	unosKordinata();

	int w = 0, h = 0;
	for (Point& t : points)
	{
		if (t.x > w)
			w = t.x;
		if (t.y > h)
			h = t.y;
	}

	w = w + w * 0.15;
	h = h + h * 0.15;

	cout << "Width: " << w << endl;
	cout << "Height: " << h << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	setstvar();
	glutMainLoop();
}