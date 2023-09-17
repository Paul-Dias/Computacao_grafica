#include <GLFW/glfw3.h>
#include <stdlib.h>

// Coordenadas normalizadas do ponto

// https://www.glfw.org/docs/latest/group__keys.html#gae12a010d33c309a67ab9460c51eb2462

double pointX = 0.0;
double pointY = 0.0;

// Largura e altura da janela
int windowWidth = 800;
int windowHeight = 600;

// Cor atual do ponto
float pointColor[3] = {0.0f, 0.0f, 1.0f}; // Cor inicial: azul

// Função chamada quando um clique de botão do mouse ocorre
void mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) // mouse invertido
    {
        // Obtém as coordenadas do clique do mouse em pixels
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // Converte as coordenadas do pixel para coordenadas normalizadas
        pointX = (xpos / windowWidth) * 2 - 1;
        pointY = -((ypos / windowHeight) * 2 - 1);
    }
}

// Função para desenhar o ponto
void drawPoint()
{
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3fv(pointColor);
    glVertex2d(pointX, pointY);
    glEnd();
}

// Função para mudar a cor do ponto com base na tecla pressionada
void changeColor(int key)
{
    switch (key)
    {
    case GLFW_KEY_0:
        pointColor[0] = 1.0f;
        pointColor[1] = 0.0f;
        pointColor[2] = 0.0f; // Vermelho
        break;
    case GLFW_KEY_1:
        pointColor[0] = 0.0f;
        pointColor[1] = 1.0f;
        pointColor[2] = 0.0f; // Verde
        break;
    case GLFW_KEY_2:
        pointColor[0] = 0.0f;
        pointColor[1] = 0.0f;
        pointColor[2] = 1.0f; // Azul
        break;
    case GLFW_KEY_3:
        pointColor[0] = 1.0f;
        pointColor[1] = 1.0f;
        pointColor[2] = 0.0f; // Amarelo
        break;
    case GLFW_KEY_4:
        pointColor[0] = 1.0f;
        pointColor[1] = 0.0f;
        pointColor[2] = 1.0f; // Magenta
        break;
    case GLFW_KEY_5:
        pointColor[0] = 0.0f;
        pointColor[1] = 1.0f;
        pointColor[2] = 1.0f; // Ciano
        break;
    case GLFW_KEY_6:
        pointColor[0] = 1.0f;
        pointColor[1] = 0.5f;
        pointColor[2] = 0.0f; // Laranja
        break;
    case GLFW_KEY_7:
        pointColor[0] = 0.5f;
        pointColor[1] = 0.5f;
        pointColor[2] = 0.5f; // Cinza
        break;
    case GLFW_KEY_8:
        pointColor[0] = 0.0f;
        pointColor[1] = 0.5f;
        pointColor[2] = 0.0f; // Verde escuro
        break;
    case GLFW_KEY_9:
        pointColor[0] = 1.0f;
        pointColor[1] = 1.0f;
        pointColor[2] = 1.0f; // Branco
        break;
    default:
        break;
    }
}

int main()
{
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "Mouse and Keyboard Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Define a função de callback para cliques do mouse
    glfwSetMouseButtonCallback(window, mouse_callback);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Desenha o ponto na posição do clique
        drawPoint();

        glfwSwapBuffers(window);
        glfwPollEvents();

        // Verifica se uma tecla foi pressionada
        for (int i = GLFW_KEY_0; i <= GLFW_KEY_9; i++)
        {
            if (glfwGetKey(window, i) == GLFW_PRESS)
            {
                changeColor(i);
            }
        }
    }

    glfwTerminate();
    return 0;
}
