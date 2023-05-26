#ifdef FIGURE_H
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

char title[] = "parallelepiped";
float angle = 0.0f;
float zoom_p = -5.0;

void initGL(void)
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, zoom_p);
	glRotatef(angle, 1, 0, 0);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex3f(2.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(2.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 1.0f); // Magenta
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void update(int)
{
	angle += 0.5f;
	if (angle > 360)
	angle -= 360;

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}
