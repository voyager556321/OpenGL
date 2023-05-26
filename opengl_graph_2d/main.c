#ifdef _HM6_H 
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float a = 1.5f;
float zoom_p = -7.0;
float zoom_delta = 0.1;
float axis_scale = 1.0f;

void initGL(void)
{
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void display()
{
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f); 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, zoom_p);

    // Drawing the function graph
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    for (float t = 0; t <= 5 * M_PI; t += 0.1) {
        float x = a * t * cos(t);
        float y = a * t * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    // Drawing the coordinate axes
    glColor3f(0.0f, 0.0f, 1.0f); // Green color
    glPushMatrix();
    glScalef(axis_scale, axis_scale, 1.0f); // Scale the coordinate axes
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glPopMatrix();

    // Drawing the tick marks on the coordinate axes
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glPushMatrix();
    glScalef(axis_scale, axis_scale, 1.0f); // Scale the tick marks
    for (float x = -1.0; x <= 1.0; x += 0.1) {
        glBegin(GL_LINES);
        glVertex2f(x, -0.05);
        glVertex2f(x, 0.05);
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += 0.1) {
        glBegin(GL_LINES);
        glVertex2f(-0.05, y);
        glVertex2f(0.05, y);
        glEnd();
    }
    glPopMatrix();

    glFlush(); // Perform drawing
    glutSwapBuffers();
}

void reshape(int width, int height) 
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'w') {
        zoom_p += zoom_delta;
        axis_scale -= zoom_delta; // Decrease the axis scale
    } else if (key == 's') {
        zoom_p -= zoom_delta;
        axis_scale += zoom_delta; // Increase the axis scale
    }
    glutPostRedisplay();
}

void MouseWheelHandler(int wheel, int direction, int x, int y)
{
	wheel = 0;
	if (direction == -1) {
		a -= 0.5f;
	} else if (direction == +1) {
		a += 0.5f;
	}
	glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600); // Set the window's width and height
    glutInitWindowPosition(0, 0); // Set the window's position
    glutCreateWindow("HW6, 12 Variant, Laskarzhevsky V."); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback function
    glutTimerFunc(0, timer, 0);
    glutReshapeFunc(reshape);
    glutMouseWheelFunc(MouseWheelHandler);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop(); // Enter the event processing loop
    return 0;
}
