#include <glut.h>
#include <stdio.h>
#include <math.h>

int centerX = 0;
int centerY = 0;
int radius = 50;

// formula

void drawCircle(int cx, int cy, int r)
{
    glBegin(GL_POINTS);

    int x = r;
    int y = 0;
    int p = 1 - r;

    while (x >= y)
    {
        glVertex2i(cx + x, cy + y);
        glVertex2i(cx - x, cy + y);
        glVertex2i(cx + x, cy - y);
        glVertex2i(cx - x, cy - y);
        glVertex2i(cx + y, cy + x);
        glVertex2i(cx - y, cy + x);
        glVertex2i(cx + y, cy - x);
        glVertex2i(cx - y, cy - x);

        y++;

        if (p <= 0)
        {
            p += 2 * y + 1;
        }
        else
        {
            x--;
            p += 2 * (y - x) + 1;
        }
    }

    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(centerX, centerY, radius);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        centerX = x - glutGet(GLUT_WINDOW_WIDTH) / 2;
        centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2 - y;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == '+')
    {
        radius += 5;
        glutPostRedisplay();
    }
    else if (key == '-')
    {
        if (radius > 5)
        {
            radius -= 5;
            glutPostRedisplay();
        }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bresenham Circle Drawing");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
