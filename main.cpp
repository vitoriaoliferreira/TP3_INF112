#include <iostream>
#include "Maze.h"

int main()
{
    int n;

    std::cout << "Insira o tamanho do labirinto: ";
    std::cin >> n;

    Maze maze(n);
    maze.leMatriz();
    maze.imprimeLabirinto();
    maze.verificaSaidaLabirinto();

    if(maze.getResposta()){
        std::cout << "Ha uma saida do labirinto\n";
    }
    else {
        std::cout << "Nao ha uma saida do labirinto\n";
    }
    return 0;
}