#include<iostream>
using namespace std;
#define inf -1
class Graph
{
private:
    int Vertices;
    int **Edges;
    public:
    Graph(int vertices);
    ~Graph();
    void AddEdge(int u, int v, int w);
    void PrintGraph();
};
Graph::Graph(int vertices)
{
    this ->Vertices = vertices;
    Edges = new int*[vertices];//创建int*数组，因为Edges是二维数组（双指针）,可以理解为矩阵的列
    for(int i = 0; i < vertices; i++)//i相当于行
    {
        Edges[i] = new int[vertices];//列中的每一行都能指向矩阵中其他列的元素
        for(int j = 0; j < vertices; j++)
        {
            Edges[i][j] = inf;//j相当于列
        }
    }
}
Graph ::~Graph()
{
    for(int i = 0; i < Vertices; i++)
    {
        delete[] Edges[i];
    }
    delete[] Edges;//因为Edges是二维数组，所以要先删除每一行，再删除整个数组
}
void Graph::AddEdge(int u, int v, int w)
{
    Edges[u][v] = w;
}
void Graph::PrintGraph()
{
    for(int i = 0; i < Vertices; ++i)
    {
        for(int j = 0; j < Vertices; ++j)
        {
            cout << Edges[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int vertice = 5;
    Graph g(vertice);
    g.AddEdge(0, 1, 2);
    g.AddEdge(0, 4, 3);
    g.AddEdge(1, 2, 4);
    g.AddEdge(1, 3, 5);
    g.AddEdge(1, 4, 6);
    g.AddEdge(2, 3, 7);
    g.AddEdge(3, 4, 8);
    g.PrintGraph();
    system("pause");
    return 0;
}

