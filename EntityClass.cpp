#include<iostream>
#include<string>

using namespace std;
class Entity
{
private:
    string MyName;
public:
    Entity() : MyName("Unkonw"){}
    Entity(const string& Name) : MyName(Name) {}
    const string& GetName() const { return MyName;}
};


int main()
{   
    Entity e1;
    cout << e1.GetName() << endl;

    Entity e2("InitialZ");
    cout << e2.GetName() << endl;

    Entity* e3;
    e3 = &e2;
    cout << e3 ->GetName() << endl;

    Entity* e4 = new Entity("Lxd");//new不仅能在堆上分配连续的内存，也可以调用构造函数。
//==Entity* e4 = (Entity*)malloc(sizeof(Entity));这行代码仅仅只分配内存，不调用构造函数
    cout << e4 ->GetName() << endl;

    Entity* e5 = new Entity[50];//创建50个Entity，返回首地址给e5
    delete[] e5;//new []分配内存，必须使用delete[]来释放内存

    int *b = new int[50];
    Entity* e6 = new(b) Entity();//调用构造函数，并在一个指定的地址中初始化Entity(),指定内存地址为b(200 bytes)
    delete[] e6;


    system("pause");
    return 0;
}
