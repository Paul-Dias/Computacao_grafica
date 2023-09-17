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

// Coordenadas normalizadas dos vértices do triângulo
double vertex1X, vertex1Y, vertex2X, vertex2Y, vertex3X, vertex3Y;

// Variável para controlar o estado de figura (0: linha, 1: triângulo)
int figureState = 0;

// Cor da figura
int clickState = 0;
float figureColor[3] = {0.0f, 0.0f, 1.0f}; // Cor inicial: azul

float lineColor[3] = {0.0f, 0.0f, 1.0f};

// Função chamada quando um clique de botão do mouse ocorre
void mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if (figureState == 0)
        {
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
        else if (figureState == 1)
        {
            if (vertex1X == 0.0 && vertex1Y == 0.0)
            {
                vertex1X = (xpos / windowWidth) * 2 - 1;
                vertex1Y = -((ypos / windowHeight) * 2 - 1);
            }
            else if (vertex2X == 0.0 && vertex2Y == 0.0)
            {
                vertex2X = (xpos / windowWidth) * 2 - 1;
                vertex2Y = -((ypos / windowHeight) * 2 - 1);
            }
            else if (vertex3X == 0.0 && vertex3Y == 0.0)
            {
                vertex3X = (xpos / windowWidth) * 2 - 1;
                vertex3Y = -((ypos / windowHeight) * 2 - 1);
            }
        }
    }
}

// Função para desenhar a figura
void drawFigure()
{
    if (figureState == 0)
    {
        glBegin(GL_LINES);
        glColor3fv(lineColor);
        glVertex2d(startX, startY);
        glVertex2d(endX, endY);
        glEnd();
    }
    else if (figureState == 1)
    {
        glBegin(GL_TRIANGLES);
        glColor3fv(figureColor);
        glVertex2d(vertex1X, vertex1Y);
        glVertex2d(vertex2X, vertex2Y);
        glVertex2d(vertex3X, vertex3Y);
        glEnd();
    }
}

void changeColor(int key)
{
    switch (key)
    {
    case GLFW_KEY_0:
        figureColor[0] = 1.0f;
        figureColor[1] = 0.0f;
        figureColor[2] = 0.0f; // Vermelho
        break;
    case GLFW_KEY_1:
        figureColor[0] = 0.0f;
        figureColor[1] = 1.0f;
        figureColor[2] = 0.0f; // Verde
        break;
    case GLFW_KEY_2:
        figureColor[0] = 0.0f;
        figureColor[1] = 0.0f;
        figureColor[2] = 1.0f; // Azul
        break;
    case GLFW_KEY_3:
        figureColor[0] = 1.0f;
        figureColor[1] = 1.0f;
        figureColor[2] = 0.0f; // Amarelo
        break;
    case GLFW_KEY_4:
        figureColor[0] = 1.0f;
        figureColor[1] = 0.0f;
        figureColor[2] = 1.0f; // Magenta
        break;
    case GLFW_KEY_5:
        figureColor[0] = 0.0f;
        figureColor[1] = 1.0f;
        figureColor[2] = 1.0f; // Ciano
        break;
    case GLFW_KEY_6:
        figureColor[0] = 1.0f;
        figureColor[1] = 0.5f;
        figureColor[2] = 0.0f; // Laranja
        break;
    case GLFW_KEY_7:
        figureColor[0] = 0.5f;
        figureColor[1] = 0.5f;
        figureColor[2] = 0.5f; // Cinza
        break;
    case GLFW_KEY_8:
        figureColor[0] = 0.0f;
        figureColor[1] = 0.5f;
        figureColor[2] = 0.0f; // Verde escuro
        break;
    case GLFW_KEY_9:
        figureColor[0] = 1.0f;
        figureColor[1] = 1.0f;
        figureColor[2] = 1.0f; // Branco
        break;
    default:
        break;
    }
}

void changeColorLine(int key)
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

    GLFWwindow *window = glfwCreateWindow(800, 600, "Shapes Drawing Example", NULL, NULL);
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

        // Desenha a figura
        drawFigure();

        glfwSwapBuffers(window);
        glfwPollEvents();

        // Verifica teclas pressionadas para alternar entre figura de linha (r) e triângulo (t)
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {
            figureState = 0;
            startX = startY = endX = endY = 0.0;
            vertex1X = vertex1Y = vertex2X = vertex2Y = vertex3X = vertex3Y = 0.0;
            clickState = 0; // Reseta o estado do clique
        }
        else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
        {
            figureState = 1;
            startX = startY = endX = endY = 0.0;
            clickState = 0; // Reseta o estado do clique
        }

        // Verifica teclas pressionadas para mudar a cor da figura
        for (int i = GLFW_KEY_0; i <= GLFW_KEY_9; i++)
        {
            if (glfwGetKey(window, i) == GLFW_PRESS)
            {
                changeColor(i);
                changeColorLine(i);
            }
        }
    }

    glfwTerminate();
    return 0;
}