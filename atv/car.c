#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

float up = 0.0;
float right = 0.0;
float theta = 0.0;

void imprimeMatriz()
{
    float matrix[16];
    int i, j;

    printf("\n\nM = \n");
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%f ", matrix[i + j * 4]);
        }
        printf("\n");
    }
    printf("\n");
}

void quadrado(float y)
{
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.25);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, -0.25);
    glVertex2f(-0.25, -0.25);
    glEnd();
}

void quadradoE(float e, float x, float y)
{
    glBegin(GL_POLYGON);
    glVertex2f(-0.15 * e + x, 0.15 * e + y);
    glVertex2f(0.15 * e + x, 0.15 * e + y);
    glVertex2f(0.15 * e + x, -0.15 * e + y);
    glVertex2f(-0.15 * e + x, -0.15 * e + y);
    glEnd();
}

int n = 50;
float ang = 0;

void cir()
{
    int i;
    glPointSize(6);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < n; i++)
    {
        glVertex2f(0.5 * cos(ang), 0.5 * sin(ang));
        ang = ang + (2 * M_PI) / n;
    }
    glEnd();
}

void cirmenor()
{
    int i;
    glPointSize(3);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < n; i++)
    {
        glVertex2f(0.5 * cos(ang), 0.5 * sin(ang));
        ang = ang + (2 * M_PI) / n;
    }
    glEnd();
}

void desenha()
{
    glClearColor(1, 1, 1, 1); // Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(right, 0.0, 0.0);

    glScalef(1.0, 1.0, 1.0);

    quadrado(0.1);

    glColor3f(1.0, 1.0, 1.0);
    quadradoE(0.5, -0.12, 0.1);
    quadradoE(0.5, 0.12, 0.1);
    glPushMatrix();

    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.25, -0.25, 0.0); // Move the center of cir
    glScalef(0.25, 0.25, 1.0);
    glRotatef(-theta, 0.0, 0.0, 1.0);
    cir();

    glColor3f(1.0, 0.0, 0.0);    // Change color to red
    glTranslatef(0.0, 0.0, 0.0); // Move back to the center of cir
    cirmenor();

    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.25, -0.25, 0.0);
    glScalef(0.25, 0.25, 1.0);
    glRotatef(-theta, 0.0, 0.0, 1.0);
    cir();

    glColor3f(1.0, 1.0, 0.0);    // Change color to red
    glTranslatef(0.0, 0.0, 0.0); // Move back to the center of cir
    cirmenor();

    glPopMatrix();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_RIGHT:
        theta += 2;
        right += 0.01;
        break;
    case GLUT_KEY_LEFT:
        theta -= 2;
        right -= 0.01;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Primeiro programa usando OpenGL");
    glutDisplayFunc(desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}