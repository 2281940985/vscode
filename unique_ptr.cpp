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
        //unique_ptr<Entity> entity = new Entity();//��������ʹ�ã���Ϊunique_ptr�Ĺ��캯����explicit����Ҫ��ʾ����
        //Entity -> make_unique -> unique_ptr
        unique_ptr<Entity> entity = make_unique<Entity>();//����ת����Ϊ��ʾ���ã����ϲ��������Ҹ���ȫ��
        //unique_ptr<Entity> entity(new Entity());//ֱ�Ӵ���ָ�룬���ϲ���
        entity ->Print();

        //unique_ptr<Entity> e0 = entity;//unique_ptr��ɾ���˿������캯���Ϳ������캯��������
    }

    system("pause");
}
// ��ַ��   https://learn.microsoft.com/zh-cn/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170