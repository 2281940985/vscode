#include<iostream>
#include<string>
#include<memory>

using namespace std;
class Entity
{
public:
    Entity()
    {
        cout << "Create Entity" << endl;
    }
    ~Entity()
    {
        cout << "Destroyed Entity" << endl;
    }
    void Print(){}
};

int main()
{
    {
        //unique_ptr<Entity> entity = new Entity();//不能这样使用，因为unique_ptr的构造函数是explicit，需要显示调用
        //Entity -> make_unique -> unique_ptr
        unique_ptr<Entity> entity = make_unique<Entity>();//这样转换后为显示调用，符合操作。并且更安全。
        //unique_ptr<Entity> entity(new Entity());//直接传入指针，符合操作
        entity ->Print();

        //unique_ptr<Entity> e0 = entity;//unique_ptr中删除了拷贝构造函数和拷贝构造函数操作符
    }

    system("pause");
}
// 网址：   https://learn.microsoft.com/zh-cn/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170