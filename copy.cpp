#include<iostream>
#include<cstring>

using namespace std;

class String
{
private:
    unsigned int m_Size;
    char* m_Buffer;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    String(const String& Other)//c++�ṩ�Ŀ������캯�����൱�� : m_Buffer(Other.m_Buffer), m_Size(Other.m_Buffer)
//����������Ȼ��ǳ�㿽������˻���Ҫ�������ƿ������캯��
    {   m_Size = Other.m_Size;
        m_Buffer = new char[Other.m_Size + 1];
        memcpy(m_Buffer, Other.m_Buffer, Other.m_Size + 1);
        cout << "Copied" << endl;
    }//�����������ڽ����ิ��ʱ���Զ�����class�Ŀ������캯�����������������ɳ��������

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }
    friend ostream& operator<<(ostream& stream, const String& string);//��������Ϊ��Ԫ���ú������������ⲿ����˽�б���
};
//��������ʱҪ�����ܵ�ʹ��const,��Ϊ�����ں����ڲ������Ƿ�Ҫ�ڸ��ƣ�û��Ҫ��ÿ�ε��ú�����Ҫ����һ��
void PrintString(String string)//�˴��������ÿ��Լ��ٵ��ÿ������캯����������Ϊ�ú�����ֱ�Ӵ���string��һ��������ÿִ��һ�Σ���Ҫ���ÿ������캯��
{
    cout << string << endl;//���������<<�������Ԫ����������ֱ�ӵ������˽�г�Ա����˸ú���PrintString()����Ҫ����Ϊ��Ԫ����
}

ostream& operator<<(ostream& stream, const String& string)
{
    stream << string.m_Buffer; 
    return stream;
}
struct Vector
{
    float x, y;
};



int main()
{
    Vector a1 = {2, 3};
    Vector b1= a1;//��a���Ƹ���b������a��b�����������ı������洢���໥���������򡣸ı�b��ֵ��Ӱ��a

    Vector* a2 = new Vector();
    Vector* b2 = a2;//��a2���ָ��洢�ĵĵ�ַ���Ƹ�b2���޸�b2��ֵ��Ӱ��a2����a2��b2��ָ��ͬһ���ڴ�����
    b2 ->x = 3;//��ʱa2 ->xҲ���޸�Ϊ3��

    String s1("InitialZ");
    //Copied 1:
    PrintString(s1);//����дcout << s1.m_Buffer,��Ϊ���������ʱ������Ĳ���������String�࣬���������Ա
    //ǳ������Copied 2:
    String s2 = s1;//��s1�ĳ�Ա������Ƹ���s2������m_Buffer��ָ�룬�洢���ǵ�ַ����˸��ƹ���s1��s2��m_Bufferָ����ͬ�ĵط�
    //������ִ����������ʱ��s1�е�delete[]�Ѿ�������m_Buffer���ڴ棬����ʱs2��delete[]����ͼ�����Ѿ������ڳ�����ڴ棬���Ա���
    s2[2] = 'a';
    //Copied 3:
    PrintString(s2);
    //Copied 4:
    PrintString(s1);//���ı�s2��m_Buffer��ͬʱҲ��ı�s1�ģ���Ϊ����ָ��ͬһ�����ݡ�
    system("pause");
    return 0;

}