#include <iostream>
using namespace std;

class Shape {   // 基类 Shape
public:
    Shape() {
        cout << "Shape" << endl;
    }
    ~Shape() {
        cout << "~Shape" << endl;
    }
};

class PaintCost {   // 基类 PaintCost
public:
    PaintCost() {
        cout << "PaintCost" << endl;
    }
    ~PaintCost() {
        cout << "~PaintCost" << endl;
    }
};

// 派生类
class Rectangle : public Shape, public PaintCost  //基类构造顺序 依照 继承顺序
{
public:
    Rectangle() :b(), a(), Shape(), PaintCost(){
        cout << "Rectangle" << endl;
    }
    ~Rectangle() {
        cout << "~Rectangle" << endl;
    }
    PaintCost b;        // 类成员变量构造顺序 依照 变量定义顺序
    Shape a; 
};

int main(void)
{
    Rectangle Rect;
    return 0;
}