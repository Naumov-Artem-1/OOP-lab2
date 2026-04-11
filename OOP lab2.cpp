#include <iostream>
#include <string>
using namespace std;
class Point {
private:
    int x;
    int y;
protected:
    string type;

public:
    Point() : x(0), y(0), type("Point")
    {
        cout << "Point(): default constructor" << endl;
    }
    Point(int newX, int newY) : x(newX), y(newY), type("Point")
    {
        cout << "Point(int, int): constructor with parameters" << endl;
    }
    Point(const Point& other)
        : x(other.x), y(other.y), type(other.type)
    {
        cout << "Point(const Point&): copy constructor" << endl;
    }
    ~Point()
    {
        cout << "~Point(): destructor" << endl;
    }
    void print() const
    {
        cout << "Point: " << type << " (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
     /*cout << " ~~~Objects of Point~~~ " << endl;

     Point p1;
     p1.print();
     Point p2(10, 20);
     p2.print();
     Point p3(p2);
     p3.print();*/

     cout << "=== Dynamic objects ===" << endl;
     Point* p4 = new Point();
     p4->print();
     Point* p5 = new Point(30, 40);
     p5->print();
     Point* p6=new Point(*p5);
     p6->print();
     delete p4;
     delete p5;
     delete p6;
}


