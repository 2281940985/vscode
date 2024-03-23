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
    }//此代码块总共Copied了6次，有3次是vector数组扩容，1->2->3,分别复制元素3次
    //另外三次是将在main函数栈上存储的数据复制到vector函数的存储区域，复制了3次
    {
        vector<Vertex> v2;
        v2.reserve(3);//预留内存，避免了不必要的复制。

        v2.emplace_back(1, 2, 3);//在vector内存区域中创建Vertex类，避免了从main函数中复制到vector区域内
        v2.emplace_back(4, 5, 6);
        v2.emplace_back(7, 8, 9);

    }


    system("pause");
    return 0;
}