#include<iostream>
#include<string>
using namespace std;
void PrintString(const string& str)
{
    cout << str << endl;
}
int main()
{
    string name = string("InitialZ") + " zty";
    name.append("dad");
    PrintString(name);

    int x = 8;
    auto f = [=]() mutable
    {
        x++;
        cout << x << endl;
    };
    f();
    system("pause");
    return 0;
}