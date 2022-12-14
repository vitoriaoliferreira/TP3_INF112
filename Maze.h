class Maze
{

private:
    int n;
    int i;
    int j;
    int **maze;
    bool resposta;

public:
    Maze(int n);
    void leMatriz();
    void imprimeLabirinto();
    void verificaSaidaLabirinto();
    bool getResposta();
    ~Maze();
};