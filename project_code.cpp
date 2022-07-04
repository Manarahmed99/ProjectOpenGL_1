#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <GL\freeglut.h>   
#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;
int faceNumber=4;
int angle;
int number = 2;
int times;



//-------------------------------------------------------------
void StepRot(int n) 
{
	glutTimerFunc(300, StepRot, n);
	n++;
	
	if (number == 1) {
		angle += 10;
	}
	else if (number == 2)
	{ angle -= 10; }
	glutPostRedisplay();

}
void windowKey(unsigned char key, int x, int y)
{
	switch (key) {
	case'C':
		faceNumber = 4.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case'H'://happy
		faceNumber = 1.0; 
		number = 1.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case'h':
		faceNumber = 1.0;
		number = 2.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case'S'://sad
		faceNumber = 2.0; 
		number = 1.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case's':
		faceNumber = 2.0;
		number = 2.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case'R'://suprise
		faceNumber = 3.0;
		number = 1.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	case'r':
		faceNumber = 3.0;
		number = 2.0;
		cout << "the new translate value:" << faceNumber << endl;
		break;
	default:
		cout << "wrong key" << endl;
		exit(0);
		break;
	}
	//glutPostRedisplay();
}
//------------------------------------------------------------------
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

}
//-------------mouth--------------------------
void mouth() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 3.14 / 180.f) * 0.07 + (0.035); // keep the axes radius same
		float y = sin(i * 3.14 / 180.f) * 0.04 - (-0.46);
		glVertex2f(x, y);
	}
	glEnd();
}
void sadmouth() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 105, 180);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 3.14 / 180.f) * 0.07 + (0.035); // keep the axes radius same
		float y = sin(i * 3.14 / 180.f) * 0.04 - (-0.448);
		glVertex2f(x, y);
	}
	glEnd();
}
void happymouth() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 105, 180);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 3.14 / 180.f) * 0.077 + 0.043;
		float y = sin(i * 3.14 / 180.f) * 0.05 - (-0.49);
		glVertex2f(x, y);
	}
	glEnd();
}
void Suprisemouth() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 105, 180);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 3.14 / 180.f) * 0.038 + (0.0); // keep the axes radius same
		float y = sin(i * 3.14 / 180.f) * 0.029 - (-0.428);
		glVertex2f(x, y);
	}
	glEnd();
}
void Suprisemouth2() {
	glBegin(GL_POLYGON);
	glColor3ub(255 ,250 ,250);
	for (GLfloat i = 0; i < 360; i++)
	{
		float x = cos(i * 3.14 / 180.f) * 0.045 + (0.0); // keep the axes radius same
		float y = sin(i * 3.14 / 180.f) * 0.034 - (-0.428);
		glVertex2f(x, y);
	}
	glEnd();
}
//-------------------------------------------
void face(void) {
	glColor3ub(255, 105, 180);
	float x = 0;
	float y = 0.4;
	float pi = 3.1416;
	float radius = 0.20;
	int amount = 40;
	float twicePi = 2.0 * pi;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (int i = 0; i <= amount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / amount)),
			y + (radius * sin(i * twicePi / amount)));
	}
	glEnd();
}
void DrawEllipse(float cx, float cy, float rx, float ry, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;

	float x = 1;
	float y = 0;

	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x * rx + cx, y * ry + cy);
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
void eye (float cx, float cy, float rx, float ry, int num_segments)
{
	glColor3ub(56 ,56 ,56);
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float x = 1;
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x * rx + cx, y * ry + cy);
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}
void quadDOWN(void) {
	glBegin(GL_QUADS);
	glColor3ub(205, 133, 63);

	glVertex2f(0.2f, -0.6f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.2f, -0.6f);
	glEnd();

}
void quadUP(void) {

	glBegin(GL_QUADS);
	glColor3ub(222, 184, 135);
	glVertex2f(0.4f, -0.3f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.4f, -0.3f);
	glEnd();

}
void line(void) {
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glColor3ub(69, 139 ,0);
	glVertex2f(0.0f, -0.2f);
	glVertex2f(0.0f, 0.3f);
	glEnd();
	
}
void plate(void) {
	glPushMatrix();
	glColor3f(1, 0.8, 0.6);
	DrawEllipse(0.0, 0.4, 0.2, 0.3, 40);
	glColor3f(1, 0.8, 0.6);
	DrawEllipse(0.0, 0.4, 0.3, 0.2, 40);
	glPopMatrix();
}
void pree(void) {
	glPushMatrix();
	glColor3ub(69, 139, 0);
	glRotatef(45, 0, 0, 1);
	glTranslatef(-0.2, -0.0, 0);
	DrawEllipse(0.0, 0.0,0.1, 0.3, 40);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-0.2, -0.2, 0);
	DrawEllipse(0.0, 0.0, 0.1, 0.3, 40);
	glPopMatrix();
}
void character(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//---------------------------------
	glPushMatrix();
	line();
	pree();
	quadUP();
	quadDOWN();
	plate();
	face();
	eye(0.1,0.4,0.01,0.01,30);
	eye(-0.1, 0.4, 0.01, 0.01, 30);

	glPopMatrix();
	//---------------------------------
	glFlush();
	glutSwapBuffers();
}
//---------------Face-----------------------
void happy() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//---------------------------------
	glPushMatrix();
	line();
	pree();
	quadUP();
	quadDOWN();
	plate();
	face();
	eye(0.1, 0.4, 0.01, 0.01, 30);
	eye(-0.1, 0.4, 0.01, 0.01, 30);
	glPushMatrix();
	glTranslatef(-0.01, -0.13, 0);
	mouth();
	happymouth();
	glPopMatrix();

	glPopMatrix();
	//---------------------------------
	glFlush();
	glutSwapBuffers();

}
void sad() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//---------------------------------
	glPushMatrix();
	line();
	pree();
	quadUP();
	quadDOWN();
	plate();
	face();
	eye(0.1, 0.4, 0.01, 0.01, 30);
	eye(-0.1, 0.4, 0.01, 0.01, 30);
	glPushMatrix();
	glTranslatef(-0.05, -0.15, 0);
	mouth();
	sadmouth();
	glPopMatrix();
	glPopMatrix();
	//---------------------------------
	glFlush();
	glutSwapBuffers();
	
}
void suprise() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//---------------------------------
	glPushMatrix();
	line();
	pree();
	quadUP();
	quadDOWN();
	plate();
	face();
	eye(0.1, 0.4, 0.01, 0.01, 30);
	eye(-0.1, 0.4, 0.01, 0.01, 30);
	glPushMatrix();
	glTranslatef(-0.0, -0.13, 0);
	Suprisemouth2();
	Suprisemouth();
	glPopMatrix();
	glPopMatrix();
	//---------------------------------
	glFlush();
	glutSwapBuffers();

}
//--------------------------------------
void face1(int T) {
	if (T == 1) {
		happy();
	}
	else if (T == 2) {
		sad();
	}
	else if (T == 3) {
		suprise();
	}
	else if (T == 4) {
		character();
	}

}
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	if (faceNumber == 1) {//happy
		glRotatef(angle, 0.0, 1.0, 0.0);
	}
	else if (faceNumber == 2) {//sad
		glRotatef(angle, 1.0, 0.0, 0.0);
	}
	else if (faceNumber == 3) {//suprise
		glRotatef(angle, 0.0, 0.0, 1.0);
	}
	else if (faceNumber == 4) {
		character();
	}
	face1(faceNumber);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	cout << "menu" << endl;
	cout << "Enter:'C' display face" << endl;
	cout << "Enter:'H' rotate happy face counterclockwise relative y-exix" << endl;
	cout << "Enter:'h' rotate happy face clockwise relative y-exix" << endl;
	cout << "Enter:'S' rotate sad face counterclockwise relative x - exix" << endl;
	cout << "Enter:'s' rotate sad face clockwise relative x - exix" << endl;
	cout << "Enter:'R' rotate suprise face counterclockwise relative z - exix" << endl;
	cout << "Enter:'r' rotate suprise face clockwise relative z- exix" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL H.W1");
    init();
	faceNumber=4;
	glutTimerFunc(150, StepRot, times);
	glutDisplayFunc(display);
	glutKeyboardFunc(windowKey);
    glutMainLoop();
    return 0;



}
