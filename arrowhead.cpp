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

    Entity* ptr = &e1;//ָ��Ҫ�õ�ַ��ʼ��������&ȡ��ַ
    Entity& e2 = *(ptr);//�����Entity�����ã�ptr��ŵ��ǵ�ַ�����Ҫ�������ü�*ptr���Ƿ���Entity��
    //*ptr.Print();//����д����.�����ȼ�����*
    (*ptr).Print();
    ptr ->Print();


    ScopedPtr entity = new Entity();//�ұ߷���Entity��ָ�룬��ʼ�����Scopedptr�࣬����new���ص�ָ�븳ֵ��m_Obj���������˴���ʽ�任
    //ScopedPtr entity(new Entity());//Ҳ��������д,ֱ�ӳ�ʼ������û����ʽ�任

    entity.GetObject() ->Print();//entity.GetObject()����Entity��ָ�룬��ͨ��ָ�����Entity���еĳ�Ա����Print
    entity->Print();//����->���أ�ʹ����ScopedPtr����ֱ�ӵ���Entity���еĺ������򻯴���
    


    system("pause");
    return 0;
}