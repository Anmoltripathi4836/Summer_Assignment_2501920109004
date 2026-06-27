#include <iostream>
using namespace std;

// 1. Interface (Abstract Class)

class Test {
public:
    virtual int square(int n) = 0;
};

class Arithmetic : public Test {
public:
    int square(int n) {
        return n * n;
    }
};


// 2. Outer and Inner Class

class Outer {
public:
    void display() {
        cout << "Display of Outer Class" << endl;
    }

    class Inner {
    public:
        void display() {
            cout << "Display of Inner Class" << endl;
        }
    };
};

// 3. Point Class

class Point {
private:
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void display() {
        cout << "Point = (" << x << ", " << y << ")" << endl;
    }
};

// 4. Box and Box3D

class Box {
protected:
    double length, breadth;

public:
    Box(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
};

class Box3D : public Box {
private:
    double height;

public:
    Box3D(double l, double b, double h) : Box(l, b) {
        height = h;
    }

    double volume() {
        return length * breadth * height;
    }
};



int main() {

    cout << "===== Program 1 =====" << endl;
    Arithmetic obj;
    cout << "Square of 5 = " << obj.square(5) << endl;

    cout << "\n===== Program 2 =====" << endl;
    Outer out;
    out.display();

    Outer::Inner in;
    in.display();

    cout << "\n===== Program 3 =====" << endl;
    Point p1;
    p1.setXY(10, 20);
    p1.display();

    Point p2(30, 40);
    p2.display();

    cout << "\n===== Program 4 =====" << endl;
    Box b(5, 4);
    cout << "Area = " << b.area() << endl;

    Box3D b3(5, 4, 3);
    cout << "Area = " << b3.area() << endl;
    cout << "Volume = " << b3.volume() << endl;

    return 0;
}