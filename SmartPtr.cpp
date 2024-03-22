//SmartPtr �������newʱ������Ҫdelete���������������Ҫnew��
#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Song
{
private:
    string SongName,Author;
    
    
public:
    wstring duration;
    Song(string SN, string AT) : SongName(SN), Author(AT){}
    ~Song(){} 
};

void UseRawPointer()
{
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song("Nothing on You", "Bruno Mars"); 

    // Use pSong...

    // Don't forget to delete!
    delete pSong;   
}

void UseSmartPointer()
{
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song("Nothing on You", "Bruno Mars"));

    // Use song2...
    wstring s = song2->duration;
    //...

} // song2 is deleted automatically here.

//�ڳ�ʼ������ָ�������ӵ��ԭʼ��ָ�롣 ����ζ������ָ�븺��ɾ��ԭʼָ��ָ�����ڴ档
//unique_ptr �е�Ψһ���ݳ�Ա�Ƿ�װ��ָ�롣 ����ζ�ţ�unique_ptr ���ָ��Ĵ�С��ȫ��ͬ�������ĸ��ֽھ��ǰ˸��ֽڡ�
//ʹ�������� * �� -> �����������ָ����ʷ�װָ����ٶȲ�����������ֱ�ӷ���ԭʼָ����ٶȡ�

int main()
{

    return 0;
}