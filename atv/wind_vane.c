#include <glut.h>
#include <math.h>
#include <stdbool.h>

int leftMouseButtonState = GLUT_UP;
int rightMouseButtonState = GLUT_UP;

GLfloat maxSpeed = 10.0f;
GLfloat minSpeed = 0.0f;

// Variáveis para controlar a rotação e velocidade das hélices
GLfloat angulo1 = 0.0f;
GLfloat angulo2 = 120.0f;
GLfloat angulo3 = 240.0f;
GLfloat velocidade = 0.0f;
GLfloat aceleracao = 0.1f;
GLfloat baseY = -0.3f;

// Função de desenho das hélices
void desenharHelice(GLfloat angulo)
{
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 1.0f); // Cor azul
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix();
}
void base()
{
    glColor3f(0.0, 1.0, 0.0); // Cor verde para o retângulo
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, baseY - 0.25); // Canto inferior esquerdo
    glVertex2f(0.05, baseY - 0.25);  // Canto inferior direito
    glVertex2f(0.05, baseY + 0.25);  // Canto superior direito
    glVertex2f(-0.05, baseY + 0.25); // Canto superior esquerdo
    glEnd();
}

// Função de desenho
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    base();

    desenharHelice(angulo1);

    desenharHelice(angulo2);

    desenharHelice(angulo3);

    glutSwapBuffers();
}

void atualizarAnimacao(int value)
{
    angulo1 += velocidade;
    angulo2 += velocidade;
    angulo3 += velocidade;

    if (angulo1 >= 360.0f)
    {
        angulo1 -= 360.0f;
    }
    if (angulo2 >= 360.0f)
    {
        angulo2 -= 360.0f;
    }
    if (angulo3 >= 360.0f)
    {
        angulo3 -= 360.0f;
    }

    if (velocidade > maxSpeed)
    {
        velocidade = maxSpeed;
    }
    else if (velocidade < -maxSpeed)
    {
        velocidade = -maxSpeed;
    }

    glutPostRedisplay();
    glutTimerFunc(16, atualizarAnimacao, 0);
}

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        leftMouseButtonState = state;
        if (state == GLUT_DOWN)
        {
            velocidade = 10.0f;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        rightMouseButtonState = state;
        if (state == GLUT_DOWN)
        {

            velocidade = 0.0f;
        }
    }
}

// Função de controle das setas do teclado
void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a': // Seta esquerda
        velocidade += aceleracao;
        break;
    case 'd': // Seta direita
        velocidade -= aceleracao;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Catavento");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);

    glutMouseFunc(mouseClick);

    glutKeyboardFunc(teclado);
    glutTimerFunc(16, atualizarAnimacao, 0);

    glutMainLoop();

    return 0;
}
