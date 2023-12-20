#include <iostream>
#define SIZE 10
#define VERYBIGINT 1000000000
class Graph
{
public:
    Graph()
    {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                matrix[i][j] = 0;
        vertexCount = 0;
    }
    // добавление вершины
    void addVertex(int vnumber)
    {
        vertexes[vertexCount] = vnumber;
        vertexCount++;
    }
    // добавление ребра
    void addEdge(int v1, int v2, int weight)
    {
        matrix[v1][v2] = weight;
        matrix[v2][v1] = weight;
    }
    // удаление вершины
    void delVertex(int vnumber)
    {
        int T = 0;
        for (int i = 0; i < SIZE; i++)
        {
            matrix[vnumber][i] = 0;
            matrix[i][vnumber] = 0;
            if (T == 1)
                vertexes[i - 1] = vertexes[i];
            if (vertexes[i] == vnumber)
                T = 1;
        }
        vertexCount--;
    }
    void delEdge(int v1, int v2)
    {
        matrix[v1][v2] = 0;
        matrix[v2][v1] = 0;
    }
    int findMinDistancesFloyd()
    {
        int weights[SIZE][SIZE]; // матрица путей
        // инициализаци матрицы
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i == j)
                {
                    weights[i][j] = 0; // путь до самой себя равен 0
                }
                else
                {
                    if (!edgeExists(i, j))
                    {
                        weights[i][j] = VERYBIGINT; // если ребра нет
                    }
                    else
                    {
                        weights[i][j] = matrix[i][j]; // если ребро есть
                    }
                }
            }
        }

        for (int k = 0; k < vertexCount; k++) // итерации по k
        {
            int ck = vertexes[k]; // возьмем номер вершины
            for (int i = 0; i < vertexCount; i++)
            {
                if (i == k)
                    continue;
                int ci = vertexes[i];
                for (int j = 0; j < vertexCount; j++)
                {
                    if (j == k)
                        continue;
                    int cj = vertexes[j];
                    if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
                    {
                        // пересчет мматрицы путей
                        weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                    }
                }
            }
        }
        int kol = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (weights[i][j] <= 3 and weights[i][j] > 0)
                    kol++;
            }
        }
        return kol / 2;
    }
    int vertexCount;

private:
    bool edgeExists(int v1, int v2)
    {
        return matrix[v1][v2] > 0;
    }
    bool vertexExists(int v)
    {
        for (int i = 0; i < vertexCount; i++)
            if (vertexes[i] == v)
                return true;
        return false;
    }
    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
};

int main()
{
    Graph g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 6, 1);
    g.addEdge(0, 5, 1);
    g.addEdge(1, 6, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(5, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    int u = g.findMinDistancesFloyd();
    std::cout << u + g.vertexCount << std::endl;
    return 0;
}