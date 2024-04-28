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
    Edges = new int*[vertices];//����int*���飬��ΪEdges�Ƕ�ά���飨˫ָ�룩,�������Ϊ�������
    for(int i = 0; i < vertices; i++)//i�൱����
    {
        Edges[i] = new int[vertices];//���е�ÿһ�ж���ָ������������е�Ԫ��
        for(int j = 0; j < vertices; j++)
        {
            Edges[i][j] = inf;//j�൱����
        }
    }
}
Graph ::~Graph()
{
    for(int i = 0; i < Vertices; i++)
    {
        delete[] Edges[i];
    }
    delete[] Edges;//��ΪEdges�Ƕ�ά���飬����Ҫ��ɾ��ÿһ�У���ɾ����������
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

