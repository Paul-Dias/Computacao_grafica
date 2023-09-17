#include <GLFW/glfw3.h>
#include <stdlib.h>

// Largura e altura da janela
int windowWidth = 800;
int windowHeight = 600;

// Coordenadas normalizadas dos pontos iniciais e finais da linha
double startX = 0.0;
double startY = 0.0;
double endX = 0.0;
double endY = 0.0;

// Variável para controlar o estado de clique (inicial ou final)
int clickState = 0;

// Cor da linha

float lineColor[3] = {0.0f, 0.0f, 1.0f}; // Cor inicial: azul

// Função chamada quando um clique de botão do mouse ocorre
void mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) // mouse invertido
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if (clickState == 0)
        {
            // Define o ponto inicial da linha
            startX = (xpos / windowWidth) * 2 - 1;
            startY = -((ypos / windowHeight) * 2 - 1);
            clickState = 1;
        }
        else if (clickState == 1)
        {
            // Define o ponto final da linha
            endX = (xpos / windowWidth) * 2 - 1;
            endY = -((ypos / windowHeight) * 2 - 1);
            clickState = 0;
        }
    }
}

// Função para desenhar a linha
void drawLine()
{
    if (clickState == 1)
    {
        glBegin(GL_LINES);
        glColor3fv(lineColor);
        glVertex2d(startX, startY);
        glVertex2d(endX, endY);
        glEnd();
    }
}

void changeColor(int key)
{
    switch (key)
    {
    case GLFW_KEY_0:
        lineColor[0] = 1.0f;
        lineColor[1] = 0.0f;
        lineColor[2] = 0.0f; // Vermelho
        break;
    case GLFW_KEY_1:
        lineColor[0] = 0.0f;
        lineColor[1] = 1.0f;
        lineColor[2] = 0.0f; // Verde
        break;
    case GLFW_KEY_2:
        lineColor[0] = 0.0f;
        lineColor[1] = 0.0f;
        lineColor[2] = 1.0f; // Azul
        break;
    case GLFW_KEY_3:
        lineColor[0] = 1.0f;
        lineColor[1] = 1.0f;
        lineColor[2] = 0.0f; // Amarelo
        break;
    case GLFW_KEY_4:
        lineColor[0] = 1.0f;
        lineColor[1] = 0.0f;
        lineColor[2] = 1.0f; // Magenta
        break;
    case GLFW_KEY_5:
        lineColor[0] = 0.0f;
        lineColor[1] = 1.0f;
        lineColor[2] = 1.0f; // Ciano
        break;
    case GLFW_KEY_6:
        lineColor[0] = 1.0f;
        lineColor[1] = 0.5f;
        lineColor[2] = 0.0f; // Laranja
        break;
    case GLFW_KEY_7:
        lineColor[0] = 0.5f;
        lineColor[1] = 0.5f;
        lineColor[2] = 0.5f; // Cinza
        break;
    case GLFW_KEY_8:
        lineColor[0] = 0.0f;
        lineColor[1] = 0.5f;
        lineColor[2] = 0.0f; // Verde escuro
        break;
    case GLFW_KEY_9:
        lineColor[0] = 1.0f;
        lineColor[1] = 1.0f;
        lineColor[2] = 1.0f; // Branco
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

    GLFWwindow *window = glfwCreateWindow(800, 600, "Line Drawing Example", NULL, NULL);
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

        // Desenha a linha
        drawLine();

        glfwSwapBuffers(window);
        glfwPollEvents();

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