#include <glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846

float leftArmY = 0.2;  // Posição inicial do braço esquerdo
float rightArmY = 0.2; // Posição inicial do braço direito
float armSpeed = 0.01; // Velocidade de movimento dos braços

float leftLegAngle = 0.0;     // Ângulo inicial da perna esquerda
float rightLegAngle = 0.0;    // Ângulo inicial da perna direita
float legRotationSpeed = 5.0; // Velocidade de rotação das pernas
float legDirection = 1.0;     // Direção inicial do movimento das pernas (para frente)

void drawRectangle()
{
    glColor3f(0.0, 1.0, 0.0); // Cor verde para o retângulo
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.6); // Canto inferior esquerdo
    glVertex2f(0.2, -0.6);  // Canto inferior direito
    glVertex2f(0.2, 0.6);   // Canto superior direito
    glVertex2f(-0.2, 0.6);  // Canto superior esquerdo
    glEnd();

    // Desenha dois retângulos como braços
    glColor3f(0.0, 0.0, 1.0); // Cor azul para os braços

    // Braço esquerdo
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, leftArmY); // Canto inferior esquerdo
    glVertex2f(-0.2, leftArmY); // Canto inferior direito
    glVertex2f(-0.2, 0.6);      // Canto superior direito
    glVertex2f(-0.4, 0.6);      // Canto superior esquerdo
    glEnd();

    // Braço direito
    glBegin(GL_POLYGON);
    glVertex2f(0.2, rightArmY); // Canto inferior esquerdo
    glVertex2f(0.4, rightArmY); // Canto inferior direito
    glVertex2f(0.4, 0.6);       // Canto superior direito
    glVertex2f(0.2, 0.6);       // Canto superior esquerdo
    glEnd();

    // Desenha duas pernas como retângulos
    glColor3f(1.0, 0.0, 0.0); // Cor vermelha para as pernas

    // Perna esquerda
    glPushMatrix();
    glTranslatef(-0.2, -0.6, 0.0);          // Translada para a posição da perna esquerda
    glRotatef(leftLegAngle, 0.0, 0.0, 1.0); // Rotaciona a perna esquerda
    glTranslatef(0.2, 0.6, 0.0);            // Translada de volta para a posição original
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, -0.6); // Canto inferior esquerdo
    glVertex2f(-0.05, -0.6); // Canto inferior direito
    glVertex2f(-0.05, -1.0); // Canto superior direito
    glVertex2f(-0.15, -1.0); // Canto superior esquerdo
    glEnd();
    glPopMatrix();

    // Perna direita
    glPushMatrix();
    glTranslatef(0.2, -0.6, 0.0);            // Translada para a posição da perna direita
    glRotatef(rightLegAngle, 0.0, 0.0, 1.0); // Rotaciona a perna direita
    glTranslatef(-0.2, 0.6, 0.0);            // Translada de volta para a posição original
    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.6); // Canto inferior esquerdo
    glVertex2f(0.15, -0.6); // Canto inferior direito
    glVertex2f(0.15, -1.0); // Canto superior direito
    glVertex2f(0.05, -1.0); // Canto superior esquerdo
    glEnd();
    glPopMatrix();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glColor3f(1.0, 0.0, 0.0); // Cor vermelha para o círculo
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 3.0f * M_PI * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();

    // Desenha dois quadrados como olhos
    glColor3f(1.0, 1.0, 1.0); // Cor branca para os olhos

    // Olho esquerdo
    glBegin(GL_POLYGON);
    glVertex2f(cx - 0.05, cy + 0.1);
    glVertex2f(cx - 0.15, cy + 0.1);
    glVertex2f(cx - 0.15, cy + 0.2);
    glVertex2f(cx - 0.05, cy + 0.2);
    glEnd();

    // Olho direito
    glBegin(GL_POLYGON);
    glVertex2f(cx + 0.05, cy + 0.1);
    glVertex2f(cx + 0.15, cy + 0.1);
    glVertex2f(cx + 0.15, cy + 0.2);
    glVertex2f(cx + 0.05, cy + 0.2);
    glEnd();
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        // Tecla "Seta para a Esquerda" pressionada, move o braço esquerdo para cima
        leftArmY += armSpeed;
        break;
    case GLUT_KEY_RIGHT:
        // Tecla "Seta para a Direita" pressionada, move o braço direito para cima
        rightArmY += armSpeed;
        break;
    case GLUT_KEY_UP:
        // Tecla "Seta para Cima" pressionada, faz as pernas se moverem para frente
        leftLegAngle += legDirection * legRotationSpeed;
        rightLegAngle -= legDirection * legRotationSpeed;
        break;
    case GLUT_KEY_DOWN:
        // Tecla "Seta para Baixo" pressionada, faz as pernas se moverem para trás
        leftLegAngle -= legDirection * legRotationSpeed;
        rightLegAngle += legDirection * legRotationSpeed;
        break;
    case GLUT_KEY_PAGE_UP:
        // Tecla "Page Up" pressionada, inverte a direção do movimento das pernas
        legDirection *= -1.0;
        break;
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o retângulo com os braços
    drawRectangle();

    // Posiciona e desenha o círculo no topo do retângulo
    drawCircle(0.0, 0.7, 0.2, 50);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Retângulo com Círculo e Braços Interativos GLUT");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys); // Função para lidar com teclas especiais
    glutMainLoop();
    return 0;
}
