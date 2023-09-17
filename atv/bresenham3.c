#include <glut.h>
#include <stdlib.h>
#include <stdio.h>

int colorIndex = 0;
int LineIndex = 0;

int paint = 0;
int thickLine = 0; // Variable to control line thickness
int line = 0;

float colors[10][3] = {
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {1.0, 0.0, 1.0},
    {0.5, 0.5, 0.5},
    {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0},
    {0.0, 0.0, 0.5}};

float lineThickness[10] = {1.0, 3.0, 2.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

int start_x = 0, start_y = 0;
int end_x = 0, end_y = 0;
int var = 0;
int drawTriangle = 0;
int trianglePoints[3][2];
int trianglePointCount = 0;

void Bresenham(int x1, int y1, int x2, int y2)
{
    glColor3fv(colors[colorIndex]);
    glLineWidth(lineThickness[LineIndex]);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        glBegin(GL_POINTS);
        glVertex2i(x1, y1);
        glEnd();

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    glFlush();
}

void drawTriangleBresenham(int x1, int y1, int x2, int y2)
{
    Bresenham(x1, y1, x2, y2);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (drawTriangle)
    {
        glColor3fv(colors[colorIndex]);
        glLineWidth(lineThickness[LineIndex]);

        for (int i = 0; i < trianglePointCount - 1; i++)
        {
            Bresenham(trianglePoints[i][0], trianglePoints[i][1], trianglePoints[i + 1][0], trianglePoints[i + 1][1]);
        }
        if (trianglePointCount == 3)
        {
            Bresenham(trianglePoints[2][0], trianglePoints[2][1], trianglePoints[0][0], trianglePoints[0][1]);
        }
    }
    else
    {
        glColor3fv(colors[colorIndex]);
        glLineWidth(lineThickness[thickLine]); // Set line thickness based on the thickLine variable
        Bresenham(start_x, start_y, end_x, end_y);
        glLineWidth(1.0); // Reset line thickness to default
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    printf("%c", key);
    if (key == 'r' || key == 'R')
    {
        drawTriangle = 0;
        colorIndex = 0; // Reset the color when switching to drawing lines
    }
    else if (key == 't' || key == 'T')
    {
        drawTriangle = 1;
        trianglePointCount = 0;
        colorIndex = 0; // Reset the color when switching to drawing triangles
    }
    else if ((key == 'k' || key == 'K') && !thickLine)
    {
        paint = 1;
        if (key >= '0' && key <= '9')
        {
            colorIndex = key - '0';
            paint = 0;
            glutPostRedisplay();
        }
    }
    else if ((key == 'e' || key == 'E') && !paint)
    {
        line = 1;
        thickLine = !thickLine; // Toggle between line thicknesses
        if (key >= '0' && key <= '9')
        {
            LineIndex = key - '0';
            line = 0;
            glutPostRedisplay();
        }
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (!drawTriangle)
        {
            if (!var)
            {
                start_x = end_x = x;
                start_y = end_y = glutGet(GLUT_WINDOW_HEIGHT) - y;
                var = 1;
            }
            else if (var)
            {
                end_x = x;
                end_y = glutGet(GLUT_WINDOW_HEIGHT) - y;
                glutPostRedisplay();
                var = 0;
            }
        }
        else
        {
            if (trianglePointCount < 3)
            {
                trianglePoints[trianglePointCount][0] = x;
                trianglePoints[trianglePointCount][1] = glutGet(GLUT_WINDOW_HEIGHT) - y;
                trianglePointCount++;
                if (trianglePointCount == 3)
                {
                    glutPostRedisplay();
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Line and Triangle Drawer");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
