/*


Alunos:

        Murilo Capozzi dos Santos       RA: 149425
        Pedro Henrique Barauna          RA: 156672
        Paulo Henrique Silva Dias       RA: 156648

Turma: N


*/

#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

float thetaX = 0.0;
float thetaY = 0.0;
int girando = 0;
float moveZ = 0.0, moveX = 0.0;
float angulo, X = 0.0, Z = 0.0;
float angX = 0.0;
float angBraco = 0.0;
float inc = 1.0;

void chao()
{
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    glScalef(3.5, 0.5, 3.5);

    glColor3f(0.5, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
    glPopMatrix();
}

void cubo()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glEnd();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glEnd();
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glEnd();
}

void corpo()
{
    glPushMatrix();
    glScalef(0.5, 0.6, 0.3);
    cubo();

    glPopMatrix();
}

void cabeca()
{
    glPushMatrix();
    glTranslatef(0.0, 0.25, 0.0);
    glScalef(0.25, 0.25, 0.25);
    cubo();
    glPopMatrix();
}

void pescoco()
{
    glPushMatrix();
    glTranslatef(0.0, 0.20, 0.0);
    glScalef(0.08, 0.30, 0.08);
    cubo();
    glPopMatrix();
}

void bracoDireito()
{
    glPushMatrix();
    glTranslatef(0.16, 0.0, 0.0);
    glRotatef(thetaX, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.4, 0.2);
    cubo();
    glPopMatrix();
}

void bracoEsquerdo()
{
    glPushMatrix();
    glTranslatef(-0.16, 0.0, 0.0);
    glRotatef(-thetaX, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.4, 0.2);
    cubo();
    glPopMatrix();
}

void pernaDireita()
{
    glPushMatrix();
    glTranslatef(-0.05, -0.25, 0.0);
    glRotatef(-thetaX, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.4, 0.2);
    cubo();
    glPopMatrix();
}

void pernaEsquerda()
{
    glPushMatrix();
    glTranslatef(0.05, -0.25, 0.0);
    glRotatef(thetaX, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.4, 0.2);
    cubo();
    glPopMatrix();
}

void robo()
{
    cabeca();
    pescoco();
    corpo();
    bracoDireito();
    bracoEsquerdo();
    pernaDireita();
    pernaEsquerda();
}

void desenha()
{
    glClearColor(0, 0, 0, 0); // Preto
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-15.0, 1.0, 1.0, 0.0);
    glRotatef(thetaY, 0.0, 1.0, 0.0);

    glPushMatrix();
    chao();
    glPopMatrix();

    glPushMatrix();
    printf("ang = %f\n", thetaX);
    if (girando)
    {
        glTranslatef(X, 0.0, Z);
        glRotatef(angX, 0.0, 1.0, 0.0);
        angulo = angX;
    }
    else
    {
        glTranslatef(X, 0.0, Z);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        X += moveZ * sin(angX * PI / 180);
        Z += moveZ * cos(angX * PI / 180);
    }
    robo();
    glPopMatrix();

    glFlush();
}

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        girando = 0;
        moveZ = 0.01;
        break;
    case 'a':
    case 'A':
        girando = 1;
        moveZ = -0.01;
        angX -= 1;
        break;
    case 's':
    case 'S':
        girando = 0;
        moveZ = -0.01;
        break;
    case 'd':
    case 'D':
        girando = 1;
        moveZ = 0.01;
        angX += 1;
        break;
    default:
        break;
    }
    if (thetaX >= 12)
        inc = -1.0;
    else if (thetaX <= -12)
        inc = 1.0;
    thetaX += inc;
    glutPostRedisplay();
}

void tecladoEspecial(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_RIGHT:
        thetaY += 2;
        break;
    case GLUT_KEY_LEFT:
        thetaY -= 2;
        break;
    case GLUT_KEY_UP:
        thetaX += 2;
        break;
    case GLUT_KEY_DOWN:
        thetaX -= 2;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cubo");
    glutDisplayFunc(desenha);
    glutSpecialFunc(tecladoEspecial);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}