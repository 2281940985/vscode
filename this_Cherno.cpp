#include<iostream>
#include<string>

using namespace std;

class Entity
{
public:
    int x,y;
    void PrintEntity_ptr(Entity* e);
    void PrintEntity_ref(Entity& e);
    Entity(int x, int y)
    {
        Entity* e = this;
        e ->x = x;
        e ->y = y;
        //上面三行代码与下面两行意思相同
        this ->x = x;
        this ->y = y;
        //同样效果相同
        (*this).x = x;
        (*this).y = y;//括号，*与. 顺序不能弄错

        PrintEntity_ptr(this);
        PrintEntity_ref(*this);
    }
};
void Entity :: PrintEntity_ptr(Entity* e)//传入指针，this就是指向当前实例的指针
{
    //print
    cout << e ->x << " 传入ptr " << e ->y << endl;
}
void Entity :: PrintEntity_ref(Entity& e)//传入引用，this是指针，因此必须加上&来引用this所指向的内容
{
    cout << e.x << " 传入ref " << e.y << endl;
}

int main()
{
    Entity e1(2,5);
    system("pause");
    return 0;
}