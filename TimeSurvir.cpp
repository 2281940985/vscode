#include<iostream>
#include<string>

using namespace std;

class Entity
{
public:
    Entity()
    {
        cout << "Constructed" << endl;
    }
    ~Entity()
    {
        cout << "Destructed" << endl;
    }
};
class ScopedPtr
{
private:
    Entity* MyPtr;
public:
    ScopedPtr(Entity* ptr) : MyPtr(ptr){}
    ~ScopedPtr()
    {
        delete MyPtr;
    }

};

int* CreatArry()
{
    //int arry[50];//在栈上定义的，出了这个函数的作用域后，内存会被清除
    //return arry;//指向栈中内存的指针

    //以下是正确写法：
    int* arry = new int[50];//在堆上创建的整型数组，出了函数作用域后仍然有效
    return arry;//此时返回的是指向堆中的内存的指针。
}


int main()
{
    {
        Entity e1;//构造函数执行
    }//析构函数执行，标记类已经被清除

    {
        Entity* e = new Entity();//我希望在超出这个作用域后清楚该堆上的内存，该如何操作？->作用域指针ScopedPtr
    }

    {
        ScopedPtr e3(new Entity());//正常对构造函数初始化，只不过用new在堆上开辟空间给MyPtr。
        // ScopedPtr e3 = new Entity();//隐式转换，把堆上分配的空间的地址赋值给ScopedPtr的成员变量MyPtr。
        //在ScopedPtr析构函数中,delete会将这个包装Entity的指针清除。因此清除了堆上的内存。
    }

    system("pause");
    return 0;
}