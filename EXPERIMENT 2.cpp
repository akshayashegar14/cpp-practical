
#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Base Class
class Shape
{
public:
    virtual float area() = 0;

    virtual void displayName() = 0;

    virtual ~Shape() {}
};

// Circle Class
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    float area() override
    {
        return 3.14 * radius * radius;
    }

    void displayName() override
    {
        cout << "\nShape Type : Circle" << endl;
        cout << "Radius     : " << radius << " cm" << endl;
    }
};

// Rectangle Class
class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    float area() override
    {
        return length * breadth;
    }

    void displayName() override
    {
        cout << "\nShape Type : Rectangle" << endl;
        cout << "Length     : " << length << " cm" << endl;
        cout << "Breadth    : " << breadth << " cm" << endl;
    }
};

// Triangle Class
class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    float area() override
    {
        return 0.5 * base * height;
    }

    void displayName() override
    {
        cout << "\nShape Type : Triangle" << endl;
        cout << "Base       : " << base << " cm" << endl;
        cout << "Height     : " << height << " cm" << endl;
    }
};

int main()
{
    Circle c(7.5);
    Rectangle r(8, 5);
    Triangle t(12, 9);

    Shape *ptr;

    cout << fixed << setprecision(2);
    cout << "================================" << endl;
    cout << "       GEOMETRY CALCULATOR      " << endl;
    cout << "================================" << endl;

    ptr = &c;
    ptr->displayName();
    cout << "Area       : " << ptr->area() << " sq.cm" << endl;

    ptr = &r;
    ptr->displayName();
    cout << "Area       : " << ptr->area() << " sq.cm" << endl;

    ptr = &t;
    ptr->displayName();
    cout << "Area       : " << ptr->area() << " sq.cm" << endl;

    cout << "\n================================" << endl;
    cout << "     CALCULATION COMPLETED     " << endl;
    cout << "================================" << endl;

    return 0;
}
