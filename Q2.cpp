#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    int positionX, positionY;
    double borderThickness;
public:
    Shape(int x, int y, double thickness) : positionX(x), positionY(y), borderThickness(thickness) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(int x, int y, double thickness, double r) : Shape(x, y, thickness), radius(r) {}

    void draw() override { cout << "Drawing Circle" << endl; }
    double calculateArea() override { return M_PI * radius * radius; }
    double calculatePerimeter() override { return 2 * M_PI * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(int x, int y, double thickness, double w, double h) : Shape(x, y, thickness), width(w), height(h) {}

    void draw() override { cout << "Drawing Rectangle" << endl; }
    double calculateArea() override { return width * height; }
    double calculatePerimeter() override { return 2 * (width + height); }
};

class Triangle : public Shape {
    double sideA, sideB, sideC;
public:
    Triangle(int x, int y, double thickness, double a, double b, double c) : Shape(x, y, thickness), sideA(a), sideB(b), sideC(c) {}

    void draw() override { cout << "Drawing Triangle" << endl; }
    double calculateArea() override { 
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC)); 
    }
    double calculatePerimeter() override { return sideA + sideB + sideC; }
};

class Polygon : public Shape {
    int numSides;
    double sideLength;
public:
    Polygon(int x, int y, double thickness, int sides, double length) : Shape(x, y, thickness), numSides(sides), sideLength(length) {}

    void draw() override { cout << "Drawing Polygon" << endl; }
    double calculateArea() override { return (numSides * sideLength * sideLength) / (4 * tan(M_PI / numSides)); }
    double calculatePerimeter() override { return numSides * sideLength; }
};

int main() {
    Circle c(10, 10, 2, 5);
    Rectangle r(5, 5, 1, 4, 6);
    Triangle t(3, 3, 1, 3, 4, 5);
    Polygon p(2, 2, 1, 6, 4);

    c.draw();
    cout << "Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << endl;

    r.draw();
    cout << "Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << endl;

    t.draw();
    cout << "Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << endl;

    p.draw();
    cout << "Area: " << p.calculateArea() << ", Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}

