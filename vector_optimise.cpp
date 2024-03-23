#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Vertex
{
public:
    float x, y, z;
    Vertex(float a, float b, float c) : x(a), y(b), z(c){ }
    Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        cout << "Copied" << endl;
    }
};

int main()
{
    {
        vector<Vertex> v1;
        v1.push_back({1, 2, 3});
        v1.push_back({4, 5, 6});
        v1.push_back({7, 8, 9});
    }//�˴�����ܹ�Copied��6�Σ���3����vector�������ݣ�1->2->3,�ֱ���Ԫ��3��
    //���������ǽ���main����ջ�ϴ洢�����ݸ��Ƶ�vector�����Ĵ洢���򣬸�����3��
    {
        vector<Vertex> v2;
        v2.reserve(3);//Ԥ���ڴ棬�����˲���Ҫ�ĸ��ơ�

        v2.emplace_back(1, 2, 3);//��vector�ڴ������д���Vertex�࣬�����˴�main�����и��Ƶ�vector������
        v2.emplace_back(4, 5, 6);
        v2.emplace_back(7, 8, 9);

    }


    system("pause");
    return 0;
}