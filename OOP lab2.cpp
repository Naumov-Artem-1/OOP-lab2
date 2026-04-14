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
    virtual  ~Point()
    {
        cout << "~Point(): destructor" << endl;
    }
    void setXY(int newX, int newY);
    void print() const
    {
        cout << type << " -> x = " << x << ", y = " << y << endl;
    }

    int getX() const{ return x;}

    int getY() const{return y;}
};

void Point::setXY(int newX, int newY)
{
    x = newX;
    y = newY;
}


class ColorPoint : public Point
{
private:
    string color;

public:

    ColorPoint() : Point()
    {
        color = "white";
        type = "ColorPoint";
        cout << "ColorPoint(): default constructor" << endl;
    }

    ColorPoint(int newX, int newY, const string& newColor)
        : Point(newX, newY)
    {
        color = newColor;
        type = "ColorPoint";
        cout << "ColorPoint(int, int, string): constructor with parameters" << endl;
    }

    ColorPoint(const ColorPoint& other)
        : Point(other)
    {
        color = other.color;
        cout << "ColorPoint(const ColorPoint&): copy constructor" << endl;
    }

    void PrintType()const;

    ~ColorPoint()
    {
        cout << "~ColorPoint(): destructor" << endl;
    }

    void setColor(const string& newColor)
    {
        color = newColor;
    }

    void print() const
    {
        Point::print();
        cout << "Color: " << color << endl;
    }
};

void ColorPoint::PrintType() const {
    cout << "Type: " << type << endl;
}

class Line
{
private:
    Point start;
    Point finish;

public:
    Line() : start(0, 0), finish(1, 1)
    {
        cout << "Line(): constructor" << endl;
    }
    Line(const Line& other)
        : start(other.start), finish(other.finish)
    {
        cout << "Line(const Line&): copy constructor" << endl;
    }

    Line(const Point& p1, const Point& p2) : start(p1), finish(p2)
    {
        cout << "Line(Point, Point): constructor" << endl;
    }

    ~Line()
    {
        cout << "~Line(): destructor" << endl;
    }

    void print() const
    {
        cout << "Line start: ";
        start.print();
        cout << "Line finish: ";
        finish.print();
    }
};

class Circle
{
private:
    Point* center;
    int radius;

public:
    Circle() : center(new Point(0, 0)), radius(1)
    {
        cout << "Circle(): constructor" << endl;
    }

    Circle(int x, int y, int r) : center(new Point(x, y)), radius(r)
    {
        cout << "Circle(int, int, int): constructor" << endl;
    }

    Circle(const Circle& other)
        : center(new Point(*other.center)), radius(other.radius)
    {
        cout << "Circle(const Circle&): copy constructor" << endl;
    }

    ~Circle()
    {
        cout << "~Circle(): destructor" << endl;
        delete center;
    }

    void print() const
    {
        cout << "Circle center: ";
        center->print();
        cout << "Radius = " << radius << endl;
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

     /*cout << " ~~~Dynamic objects~~~" << endl;
     Point* p4 = new Point();
     p4->print();
     Point* p5 = new Point(30, 40);
     p5->print();
     Point* p6=new Point(*p5);
     p6->print();
     delete p4;
     delete p5;
     delete p6;*/

      /*cout << " ~~~Objects of ColorPoint~~~ " << endl;
      ColorPoint cp1;
      cp1.print();
      ColorPoint cp2(5, 7, "red");
      cp2.print();
      ColorPoint cp3(cp2);
      cp3.print();*/

      /*cout << " ~~~Composition by object (Line)~~~ " << endl;
      Point p11(10, 20);
      Point p22(30, 40);
      Line l1(p11, p22);
      l1.print();*/

     /*cout << " ~~~Composition pointer~~~ " << endl;
     Circle c1(5, 6, 10);
     c1.print();*/

     cout << " ~~~Copy Line~~~ " << endl;
     Point a(1, 2);
     Point b(3, 4);
     Line l1(a, b);
     Line l2(l1);

}


