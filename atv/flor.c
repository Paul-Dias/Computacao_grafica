#include <glut.h>
#include <math.h>

#define M_PI 3.14159265358979323846

float angle = 0.0; // Ângulo de rotação das pétalas

void miolo()
{
    glColor3f(1.0, 1.0, 0.0); // Amarelo para o miolo
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float radian = i * (M_PI / 180);
        float x = 0.1 * cos(radian);
        float y = 0.1 * sin(radian);
        glVertex2f(x, y);
    }
    glEnd();
}

void petala(float radius, float angle)
{
    glColor3f(1.0, 0.0, 0.0); // Vermelho para as pétalas
    glBegin(GL_POLYGON);
    for (int i = 0; i < 25; i++) // Desenha cada pétala como um arco de 45 graus
    {
        float radian = (angle + i * 6) * (M_PI / 180);
        float x = radius * cos(radian);
        float y = radius * sin(radian);
        glVertex2f(x, y);
    }
    glEnd();
}

void desenha()
{
    glClearColor(1, 1, 1, 1); // Fundo branco
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    miolo();

    for (int i = 0; i < 6; i++) // Desenha 6 pétalas
    {
        glPushMatrix();
        glRotatef(angle + i * 60, 0.0, 0.0, 1.0); // Rotaciona cada pétala em 60 graus
        glTranslatef(0.3, 0.0, 0.0);              // Translada para a posição das pétalas
        petala(0.2, 30);                          // Desenha uma pétala
        glPopMatrix();
    }

    glPopMatrix();

    angle += 1.0; // Incrementa o ângulo de rotação das pétalas
    if (angle >= 360.0)
        angle = 0.0;

    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Flor Giratoria");
    glutDisplayFunc(desenha);
    glutIdleFunc(desenha); // Chama a função desenha quando inativo
    glutMainLoop();
    return 0;
}
