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
    //int arry[50];//��ջ�϶���ģ����������������������ڴ�ᱻ���
    //return arry;//ָ��ջ���ڴ��ָ��

    //��������ȷд����
    int* arry = new int[50];//�ڶ��ϴ������������飬���˺������������Ȼ��Ч
    return arry;//��ʱ���ص���ָ����е��ڴ��ָ�롣
}


int main()
{
    {
        Entity e1;//���캯��ִ��
    }//��������ִ�У�������Ѿ������

    {
        Entity* e = new Entity();//��ϣ���ڳ�����������������ö��ϵ��ڴ棬����β�����->������ָ��ScopedPtr
    }

    {
        ScopedPtr e3(new Entity());//�����Թ��캯����ʼ����ֻ������new�ڶ��Ͽ��ٿռ��MyPtr��
        // ScopedPtr e3 = new Entity();//��ʽת�����Ѷ��Ϸ���Ŀռ�ĵ�ַ��ֵ��ScopedPtr�ĳ�Ա����MyPtr��
        //��ScopedPtr����������,delete�Ὣ�����װEntity��ָ��������������˶��ϵ��ڴ档
    }

    system("pause");
    return 0;
}