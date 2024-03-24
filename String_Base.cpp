#include<iostream>
#include<cstring>

using namespace std;

class String
{
private:
    char* Str;
    size_t length;
public:
    String();
    String(const char* s);//copy function
    String(const String& s);
    ~String();
    size_t GetLength() const;
    char operator[] (size_t index) const;
    String& operator= (const String& s);
    bool operator== (const String& s);
    bool operator!= (const String& s);
    String copy() const;
    String operator+(const String& s);
    friend ostream& operator<< (ostream& out, const String s);

};
String :: String()
{
    length = 0;
    Str = new char[1];
    Str[0] = 0;
}
String :: String(const char* s)
{
    length = strlen(s);
    Str = new char[length + 1];
    strcpy(Str,s);
}
String ::String(const String& s)
{
    length = s.length;
    Str = new char [length + 1];
    strcpy(Str, s.Str);
    cout << "Copied" << endl;
}
String ::~String()
{
    delete[] Str;
    cout << "destructed" << endl;
}
size_t String ::GetLength() const
{
    return length;
}
char String :: operator[] (size_t index) const
{
    return Str[index];
}
String& String :: operator= (const String& s)
{
    if (this != &s)
    {
        delete[] Str;
        length = s.length;
        Str = new char[length + 1];
        strcpy(Str, s.Str);
    }
    return *this;
}
bool String :: operator== (const String& s)
{
    return strcmp(Str,s.Str) == 0;
}
bool String :: operator!= (const String& s)
{
    return strcmp(Str,s.Str) != 0;
}
String String :: copy() const
{
    String s = *this;
    return s;
}
String String ::operator+(const String& s)
{
    String result;
    result.length = length + s.length;
    result.Str = new char [result.length + 1];
    strcpy(result.Str, Str);
    strcat(result.Str, s.Str);
    return result;
}
ostream& operator<< (ostream& out, const String s)
{
    out << s.Str;
    return out;
}
int main()
{
    String s("12345d");
    cout << s << endl;
    cout << s+"445" << endl;
    cout << s[5] << endl;
    cout << (s == "12345d") << endl;
    cout << (s != "12345d") << endl;
    s = s + "asd";
    String a, b, c;
    a = b = c = s;
    cout << a << b << c << s << endl;
    String x = s.copy();
    cout << x << endl;
    system("pause");
    return 0;
}