#include<iostream>
#include<string>

using namespace std;

class Entity
{
public:
    void Print() const { cout << "hello" << endl;}
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {}
    ~ScopedPtr()
    {
        delete m_Obj;
    }

    Entity* GetObject() {return m_Obj;}

    Entity* operator->() { return m_Obj;}
};

int main()
{
    Entity e1;
    e1.Print();

    Entity* ptr = &e1;//指针要用地址初始化，即用&取地址
    Entity& e2 = *(ptr);//左边是Entity类引用，ptr存放的是地址，因此要逆向引用即*ptr才是访问Entity类
    //*ptr.Print();//错误写法，.的优先级大于*
    (*ptr).Print();
    ptr ->Print();


    ScopedPtr entity = new Entity();//右边返回Entity类指针，初始化左边Scopedptr类，即将new返回的指针赋值给m_Obj，并且做了次隐式变换
    //ScopedPtr entity(new Entity());//也可以这样写,直接初始化，并没有隐式变换

    entity.GetObject() ->Print();//entity.GetObject()返回Entity类指针，在通过指针调用Entity类中的成员函数Print
    entity->Print();//利用->重载，使得在ScopedPtr类中直接调用Entity类中的函数，简化代码
    


    system("pause");
    return 0;
}