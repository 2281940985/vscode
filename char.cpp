#include <iostream>
int length_char = sizeof(char);

int main()
{
    char name[] = "zty";
    std :: cout << length_char << std :: endl;//char类型单个字符串所占的字节=1
    std :: cout << sizeof (name) << std :: endl;//整个name数组的长度--4个字节
    std :: cout << sizeof (name[1]) << std :: endl;//字符串数组的第一个元素所占的字节=char占的字节=1
    char *ptr = name;
    for (int i =0; i<4; i++)
    {
        std :: cout << *ptr << std :: endl;
        std :: cout << ptr << std :: endl;//为什么这里不显示指针的地址而是内容
        ptr++;//执行 ptr++ 后，指针 ptr 会向前移动 4个字节，指向下一个整型元素的地址。
    }
    
    system("pause");
}