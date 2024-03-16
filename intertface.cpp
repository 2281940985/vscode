#include<iostream>
#include<string>
using namespace std;
class PrintClassName
{
public:
    virtual void GetClassName() = 0;
    
};

class Entity : public PrintClassName
{
public:
    virtual string GetName() {return "Entity" ;}\
    void GetClassName()
    {
        cout << "Entity" << endl;
    }

};
class Player : public Entity, PrintClassName
{
private:
    std ::string my_name;
public:
    Player(const std ::string& name) : my_name(name){}
    std ::string GetName(){return my_name;}
    void GetClassName()
    {
        cout << "Player" << endl;
    }
};
int main()
{
    Entity* e = new Entity();
    cout << e ->GetName() << endl;
    e ->GetClassName();

    Player* p = new Player("InitialZ");
    cout << p ->GetName() << endl;
    p ->GetClassName();

    Entity* entity = p;
    cout << entity ->GetName() << endl;
    entity ->GetClassName();

    system("pause");

    return 0;
}