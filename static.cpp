#include<iostream>
using namespace std;

class Entity
{
    public:
         int x , y;
        static void print()
        {
            cout << x << y << endl;
        }
};

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;
    Entity ::print();

    Entity e1;
    e.x = 5;
    e.y = 8;
    Entity ::print();

    system("pause");
    return 0;
}