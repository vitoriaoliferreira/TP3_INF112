#include "Maze.h"
#include <iostream>

Maze::Maze(int n)
{
    this->n = n;

    //valores usados na recursividade

    this->i = 2;
    this->j = 1;
    this->resposta = false;

    // alocando a matriz dinamicamente

    maze = new int *[n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        maze[i] = new int[n + 2];
    }
}

void Maze::leMatriz()
{
    std::cout << "Insira o labirinto: ";
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
            {
                maze[i][j] = 1;
            }
            else
            {
                std::cin >> maze[i][j];
            }
        }
    }
}

void Maze::imprimeLabirinto()
{
    std::cout << "---- LABIRINTO ----\n";
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

void Maze::verificaSaidaLabirinto()
{
    if (maze[i][j] == 7)
    {
        this->resposta = true;
    }

    // atualiza a posicao para 1 para fazer a poda

    maze[i][j] = 1;

    if (maze[i + 1][j] == 0 || maze[i + 1][j] == 7)
    {
        i++;
        verificaSaidaLabirinto();
        i--;
    }
    if (maze[i - 1][j] == 0 || maze[i - 1][j] == 7)
    {
        i--;
        verificaSaidaLabirinto();
        i++;
    }
    if (maze[i][j + 1] == 0 || maze[i][j + 1] == 7)
    {
        j++;
        verificaSaidaLabirinto();
        j--;
    }
    if (maze[i][j - 1] == 0 || maze[i][j - 1] == 7)
    {
        j--;
        verificaSaidaLabirinto();
        j++;
    }
}

bool Maze::getResposta()
{
    return this->resposta;
}

Maze::~Maze()
{
    //desalocando a matriz
    
    for (int i = 0; i < n + 2; i++)
    {
        delete[] maze[i];
    }
    delete maze;
}
