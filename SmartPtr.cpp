//SmartPtr 当你调用new时，不需要delete来清除，甚至不需要new。
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

//在初始化智能指针后，它将拥有原始的指针。 这意味着智能指针负责删除原始指针指定的内存。
//unique_ptr 中的唯一数据成员是封装的指针。 这意味着，unique_ptr 与该指针的大小完全相同，不是四个字节就是八个字节。
//使用重载了 * 和 -> 运算符的智能指针访问封装指针的速度不会明显慢于直接访问原始指针的速度。

int main()
{

    return 0;
}