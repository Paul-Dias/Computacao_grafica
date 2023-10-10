#include <glut.h>

GLUquadricObj *obj;

int objId = 1;
float angX = 0;
float angY = 0;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST); // habilita o teste de profundidade
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-7, 7, -7, 7, -7, 7);
    glPushMatrix();
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_FILL); // Use GLU_FILL para preencher a esfera
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpa o buffer
    glColor3f(0.984, 0.988f, 0.62f);

    glPopMatrix();
    glPushMatrix();

    glRotatef(angX, 1, 0, 0);
    glRotatef(angY, 0, 1, 0);

    switch (objId)
    {
    case 1:
        // Desenhe a esfera principal (cabeça)
        glutSolidSphere(3, 50, 50);

        // Posicione e desenhe o primeiro olho (à esquerda)
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);     // Defina a cor do olho como preto
        glTranslatef(-1.0, 1.0, 2.5); // Posicione o olho à esquerda
        glutSolidSphere(0.5, 50, 50); // Desenhe o olho
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-1.0, 1.0, 3.0);
        glutSolidSphere(0.25, 50, 50);
        glPopMatrix();

        // Posicione e desenhe o segundo olho (à direita)
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);     // Defina a cor do olho como preto
        glTranslatef(1.0, 1.0, 2.5);  // Posicione o olho à direita
        glutSolidSphere(0.5, 50, 50); // Desenhe o olho
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(1.0, 1.0, 3.0);
        glutSolidSphere(0.25, 50, 50);
        glPopMatrix();

        // red nose

        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-0.03, -0.25, 3.0);
        glutSolidSphere(0.50, 50, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-0.03, -1.8, 2.5);
        glutSolidSphere(0.25, 50, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);        // Defina a cor do cone como verde
        glTranslatef(0.0, 2.0, 0.0);     // Posicione o cone acima da esfera
        glRotatef(-90.0, 1.0, 0.0, 0.0); // Gire o cone para que fique apontando para cima
        glutSolidCone(1.5, 4.0, 50, 50); // Desenhe o cone
        glPopMatrix();

        break;
    }
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        objId = 1;
        break;
    }
    glutPostRedisplay();
}

void transformacoes(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        angX += 15;
        break;
    case GLUT_KEY_DOWN:
        angX -= 15;
        break;
    case GLUT_KEY_LEFT:
        angY -= 15;
        break;
    case GLUT_KEY_RIGHT:
        angY += 15;
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
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Joker");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(transformacoes);
    init();
    glutMainLoop();
}
