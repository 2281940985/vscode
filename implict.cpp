#include<iostream>
#include<string>

using namespace std;

class Entity
{
private:
    string MyName;
    int MyAge;
public:
    Entity(const string& name) : MyName(name), MyAge(-1) {}//两个构造函数分别传入不同的参数
    Entity(int age) : MyName("Unknow"), MyAge(age) {}//它会自动识别传入的参数，并执行对应的构造函数

    //explicit Entity(int age) : MyName("Unknow"), MyAge(age) {},标记该构造函数不能隐式转换即不能执行第26行代码
    void PrintEntity(const Entity& entity);
};

void Entity :: PrintEntity(const Entity& entity)
{
    cout << entity.MyName << " " << entity.MyAge << endl;
}
int main()
{
    Entity e1(22);
    e1.PrintEntity(24);//编译器认为22可以转换成Entity，因此没报错

    Entity e2("InitialZ");
    //e2.PrintEntity("InitialZ");"InitialZ"是const char 数组，要经过两次隐式转换才能成为Entity作为参数进入函数
    //const char arry -> string -> Entity,但隐式转换只能发生一次，因此运行报错

    e2.PrintEntity(string ("Lxd"));//直接将const char arry 转换为string，在做隐式转换就能运行成功。

    system("pause");
    return 0;
}