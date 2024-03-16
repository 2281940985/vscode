#include<iostream>
#include<string>
using namespace std;
class Entity
{
public:
    virtual string GetName(){return "Entity" ;}

};
class Player : public Entity
{
private:
    std ::string my_name;
public:
    Player(const std ::string& name) : my_name(name){}
    std ::string GetName(){return my_name;}
};
int main()
{
    Entity* e = new Entity();
    cout << e ->GetName() << endl;

    Player* p = new Player("InitialZ");
    cout << p ->GetName() << endl;

    Entity* entity = p;
    cout << entity ->GetName() << endl;
    system("pause");

    return 0;
}