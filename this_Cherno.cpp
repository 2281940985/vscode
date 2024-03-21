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
        //�������д���������������˼��ͬ
        this ->x = x;
        this ->y = y;
        //ͬ��Ч����ͬ
        (*this).x = x;
        (*this).y = y;//���ţ�*��. ˳����Ū��

        PrintEntity_ptr(this);
        PrintEntity_ref(*this);
    }
};
void Entity :: PrintEntity_ptr(Entity* e)//����ָ�룬this����ָ��ǰʵ����ָ��
{
    //print
    cout << e ->x << " ����ptr " << e ->y << endl;
}
void Entity :: PrintEntity_ref(Entity& e)//�������ã�this��ָ�룬��˱������&������this��ָ�������
{
    cout << e.x << " ����ref " << e.y << endl;
}

int main()
{
    Entity e1(2,5);
    system("pause");
    return 0;
}