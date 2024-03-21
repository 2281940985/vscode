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

    Entity* e4 = new Entity("Lxd");//new�������ڶ��Ϸ����������ڴ棬Ҳ���Ե��ù��캯����
//==Entity* e4 = (Entity*)malloc(sizeof(Entity));���д������ֻ�����ڴ棬�����ù��캯��
    cout << e4 ->GetName() << endl;

    Entity* e5 = new Entity[50];//����50��Entity�������׵�ַ��e5
    delete[] e5;//new []�����ڴ棬����ʹ��delete[]���ͷ��ڴ�

    int *b = new int[50];
    Entity* e6 = new(b) Entity();//���ù��캯��������һ��ָ���ĵ�ַ�г�ʼ��Entity(),ָ���ڴ��ַΪb(200 bytes)
    delete[] e6;


    system("pause");
    return 0;
}
