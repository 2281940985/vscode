#include<iostream>
#include<string>

using namespace std;

class Entity
{
private:
    string MyName;
    int MyAge;
public:
    Entity(const string& name) : MyName(name), MyAge(-1) {}//�������캯���ֱ��벻ͬ�Ĳ���
    Entity(int age) : MyName("Unknow"), MyAge(age) {}//�����Զ�ʶ����Ĳ�������ִ�ж�Ӧ�Ĺ��캯��

    //explicit Entity(int age) : MyName("Unknow"), MyAge(age) {},��Ǹù��캯��������ʽת��������ִ�е�26�д���
    void PrintEntity(const Entity& entity);
};

void Entity :: PrintEntity(const Entity& entity)
{
    cout << entity.MyName << " " << entity.MyAge << endl;
}
int main()
{
    Entity e1(22);
    e1.PrintEntity(24);//��������Ϊ22����ת����Entity�����û����

    Entity e2("InitialZ");
    //e2.PrintEntity("InitialZ");"InitialZ"��const char ���飬Ҫ����������ʽת�����ܳ�ΪEntity��Ϊ�������뺯��
    //const char arry -> string -> Entity,����ʽת��ֻ�ܷ���һ�Σ�������б���

    e2.PrintEntity(string ("Lxd"));//ֱ�ӽ�const char arry ת��Ϊstring��������ʽת���������гɹ���

    system("pause");
    return 0;
}