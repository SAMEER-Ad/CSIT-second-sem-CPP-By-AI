/* 
 unit6_virtual_polymorphism.cpp
 Demonstrates virtual functions, late binding, abstract classes (pure virtual), virtual destructor,
 friend function, static member function, "this" pointer, and polymorphism.
 Compile: g++ -std=c++17 -Wall unit6_virtual_polymorphism.cpp -o unit6_virtual_polymorphism
 Run: ./unit6_virtual_polymorphism
*/

#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() { std::cout << "Shape destructor\n"; } // virtual destructor
    virtual double area() const = 0; // pure virtual -> abstract class
    virtual void draw() const { std::cout << "Drawing Shape\n"; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159 * r * r; }
    void draw() const override { std::cout << "Drawing Circle of radius " << r << '\n'; }
    void showThis() const { std::cout << "this ptr: " << this << '\n'; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double ww, double hh) : w(ww), h(hh) {}
    double area() const override { return w * h; }
    void draw() const override { std::cout << "Drawing Rectangle " << w << "x" << h << '\n'; }
};

// friend function example
class FriendExample {
    int value;
public:
    FriendExample(int v=0): value(v) {}
    friend void showFriend(const FriendExample& f);
    static void staticFunc() { std::cout << "FriendExample::staticFunc\n"; }
};

void showFriend(const FriendExample& f) {
    std::cout << "Friend value = " << f.value << '\n';
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>(2.0));
    shapes.emplace_back(std::make_unique<Rectangle>(3.0,4.0));

    for (const auto& s : shapes) {
        s->draw(); // late binding
        std::cout << "Area = " << s->area() << '\n';
    }

    Circle c(5.0);
    c.showThis();

    FriendExample fe(42);
    showFriend(fe);
    FriendExample::staticFunc();

    return 0;
}