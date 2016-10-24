#include <stdlib.h>
#include "../GL/glut.h"
#include<iostream>
using namespace std;

void init(void);
void display(void);
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void idle(void);
static double rotate_apple = 0.0f, rotate_pencil = 0.0f, rate = 0, cuba_x,cuba_y,cuba_z;
char key1 = 0;
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  //double cache ;RGB+alpha;depth cache
	glutCreateWindow("OpenGL Assignment 1");
	glutReshapeWindow(512, 512);                               //set assignment1 pixel= 512X512;
	cout << "Press Enter to aha ,press again to restart." << endl << "Press Esc to exit.";
	init();

	glutReshapeFunc(reshape);                                 //Glutreshapewindow发生时调用这函数，相当于构造函数
	glutDisplayFunc(display);
	glutIdleFunc(idle);                                 //系统空闲时调用的
	glutKeyboardFunc(keyboard);                            //输入keytokeyboard，xy代表pixel

	glutMainLoop();                                   //死循环
	return 0;
}

void init(void) {

	GLfloat position[] = { 1.0, 1.0, 5.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, 8.0, /* Eye pos XYZ */
		0.0, 0.0, 0.0, /* Target pos XYZ */
		0.0, 1.0, 0.0); /* Up vector */

						// do something awesome here

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND); // 打开混合
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); 
	glPushMatrix();
	glTranslated(0.0f, 1.75f, 0.0f);
	glRotatef(cuba_x, 1, 0, 0);
	glRotatef(cuba_y, 0, 1, 0);
	glRotatef(cuba_z, 0, 0, 1);


	
	glBegin(GL_QUADS);
	glColor4f(0.5f, 0.5f, 0.0, 0.8);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glColor4f(0.0, 0.5f, 0.0, 0.8);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor4f(0.0, 0.5f, 0.5f, 0.8);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor4f(0.5f, 0.5f, 0.5f, 0.8);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glColor4f(0.5f, 0.0, 0.5f, 0.8);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor4f(0.0, 0.0, 0.5f, 0.8);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor4f(0.5f, 0.0, 0.0, 0.8);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glColor4f(0.5f, 0.5f, 0.5f, 0.8);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor4f(0.0, 0.5f, 0.5f, 0.8);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor4f(0.0, 0.0, 0.5f, 0.8);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor4f(0.5f, 0.0, 0.5f, 0.8);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glColor4f(0.5f, 0.0, 0.0, 0.8);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor4f(0.0, 0.5f, 0.0, 0.8);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor4f(0.5f, 0.5f, 0.0, 0.8);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glColor4f(0.0, 0.5f, 0.5f, 0.8);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor4f(0.0, 0.5f, 0.0, 0.8);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor4f(0.0, 0.0, 0.5f, 0.8);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glColor4f(0.5f, 0.5f, 0.0, 0.8);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glColor4f(0.5f, 0.5f, 0.5f, 0.8);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor4f(0.5f, 0.0, 0.5f, 0.8);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor4f(0.5f, 0.0, 0.0, 0.8);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);


						
	if (key1 == 0) {
		glPushMatrix();
		glTranslatef(-2.0f, 0.0f, 0.0f);
		glRotatef(rotate_pencil, 0.2f, -3.2f, 0.0f);
		glRotatef(90, 10, 0, 0);
		//pencil
		GLUquadricObj *cylinder;
		cylinder = gluNewQuadric();
		gluCylinder(cylinder, 0.15f, 0.15f, 2.0f, 32, 5);//画圆柱
		glRotatef(180, 10, 0, 0);
		GLUquadricObj *tapered0;
		tapered0 = gluNewQuadric();
		gluCylinder(tapered0, 0.15f, 0, 0.5f, 32, 5);//画圆锥
		glPopMatrix();

		//apple
		glRotatef(-90, 1.0, 0, 0);
		glTranslatef(2.0f, 0.0f, -0.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidSphere(0.75f, 15, 15);                   //圆
		glTranslatef(0.0f, 0.0f, 0.75f);
		GLUquadricObj *tapered1;
		tapered1 = gluNewQuadric();
		gluCylinder(tapered1, 0.025f, 0, 0.5f, 32, 5);//画苹果上的第一个圆锥

		glPushMatrix();
		glRotatef(rotate_apple, 0.0f, 0.0f, 1.0f);
		glTranslatef(-0.25f, 0.2f, 0.4f);                         //根据sin60和cos60可算 1/2 和1/根号3，但为了效果适当缩小
		glRotatef(150, 0, 10, 0);
		glRotatef(20, 10, 0, 0);
		GLUquadricObj *tapered2;
		tapered2 = gluNewQuadric();
		gluCylinder(tapered2, 0.025f, 0, 0.5f, 32, 5);//画第二个圆锥
		glTranslatef(-1.0f, 0.0f, 1.f);
		glPopMatrix();
	}
	if (key1 == 1) {

		glPushMatrix();
		glTranslatef(-1.0f, 0.0f, 0.0f);
		glTranslatef(0.0, -0.5f, 0.0f);
		glRotatef(90, 10, 0, 0);
		glRotatef(-90, 00, 10, 0);
		glTranslatef(0.0, 0.0f, -rate);
		
		GLUquadricObj *cylinder;
		cylinder = gluNewQuadric();
		gluCylinder(cylinder, 0.15f, 0.15f, 2.0f, 32, 5);//画圆柱
		glRotatef(180, 10, 0, 0);
		GLUquadricObj *tapered0;
		tapered0 = gluNewQuadric();
		gluCylinder(tapered0, 0.15f, 0, 0.5f, 32, 5);//画圆锥
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-rate, 0.0f, 0.0f);
		glRotatef(-90, 1.0, 0, 0);
		glTranslatef(2.0f, 0.0f, -0.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glutSolidSphere(0.75f, 15, 15);                   
		glTranslatef(0.0f, 0.0f, 0.75f);                   //圆
		
		GLUquadricObj *tapered1;
		tapered1 = gluNewQuadric();
		gluCylinder(tapered1, 0.025f, 0, 0.5f, 32, 5);//画苹果上的第一个圆锥

		glTranslatef(-0.25f, 0.2f, 0.4f);                         //根据sin60和cos60可算 1/2 和1/根号3，但为了效果适当缩小
		glRotatef(150, 0, 10, 0);
		glRotatef(20, 10, 0, 0);
		GLUquadricObj *tapered2;
		tapered2 = gluNewQuadric();
		gluCylinder(tapered2, 0.025f, 0, 0.5f, 32, 5);//画第二个圆锥
		glTranslatef(-1.0f, 0.0f, 1.f);
		glPopMatrix();
	}

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 13:
	{   //enter
		rate = 0;
		if (key1 == 1)
			key1 = 0;
		else key1 = 1;
		break;
	}
	case 27:
	{   //ESC
		exit(0);
		break;
	}
	default:
		break;
	}
}

void idle(void)
{


	rotate_pencil += 0.05f;
	if (rotate_pencil >= 360)rotate_pencil = 0;

	rotate_apple += 0.02f;
	if (rotate_apple >= 360)rotate_apple = 0;
	glutPostRedisplay();
	if (rate <= 1.9)rate += 0.01;

	cuba_x += 0.01;
	cuba_y += 0.01;
	cuba_z += 0.01;
	glutPostRedisplay();
}