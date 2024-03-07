#include <iostream>
using namespace std;

class Shape {   // ���� Shape
public:
    Shape() {
        cout << "Shape" << endl;
    }
    ~Shape() {
        cout << "~Shape" << endl;
    }
};

class PaintCost {   // ���� PaintCost
public:
    PaintCost() {
        cout << "PaintCost" << endl;
    }
    ~PaintCost() {
        cout << "~PaintCost" << endl;
    }
};

// ������
class Rectangle : public Shape, public PaintCost  //���๹��˳�� ���� �̳�˳��
{
public:
    Rectangle() :b(), a(), Shape(), PaintCost(){
        cout << "Rectangle" << endl;
    }
    ~Rectangle() {
        cout << "~Rectangle" << endl;
    }
    PaintCost b;        // ���Ա��������˳�� ���� ��������˳��
    Shape a; 
};

int main(void)
{
    Rectangle Rect;
    return 0;
}