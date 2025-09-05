/* 
 unit3_class_basic.cpp
 Demonstrates a simple class with constructors, destructor, member functions, objects as arguments.
 Compile: g++ -std=c++17 -Wall unit3_class_basic.cpp -o unit3_class_basic
 Run: ./unit3_class_basic
*/

#include <iostream>
#include <string>

class Rectangle {
private:
    double width;
    double height;

public:
    // default constructor
    Rectangle() : width(0), height(0) { std::cout << "Default constructor called\n"; }

    // parameterized constructor
    Rectangle(double w, double h) : width(w), height(h) { std::cout << "Param constructor called\n"; }

    // destructor
    ~Rectangle() { std::cout << "Destructor called for Rectangle\n"; }

    double area() const { return width * height; }

    // member function defined outside (example)
    void print() const;
};

// definition outside class
void Rectangle::print() const {
    std::cout << "Rectangle(width=" << width << ", height=" << height << ", area=" << area() << ")\n";
}

void print_area(const Rectangle& r) {
    std::cout << "Area from function: " << r.area() << '\n';
}

int main() {
    Rectangle r1;             // default
    Rectangle r2(3.5, 2.0);   // parameterized
    r1.print();
    r2.print();

    print_area(r2);

    // returning object from function (inline example)
    auto make_rect = []() -> Rectangle { return Rectangle(4.0, 5.0); };
    Rectangle r3 = make_rect();
    r3.print();

    return 0;
}