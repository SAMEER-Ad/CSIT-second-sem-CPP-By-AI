/* 
 unit7_templates_exceptions.cpp
 Demonstrates function templates, class templates, template with multiple args,
 template inheritance basics and exception handling (try/throw/catch).
 Compile: g++ -std=c++17 -Wall unit7_templates_exceptions.cpp -o unit7_templates_exceptions
 Run: ./unit7_templates_exceptions
*/

#include <iostream>
#include <stdexcept>
#include <string>

// function template
template<typename T>
T my_max(T a, T b) { return (a > b) ? a : b; }

// class template
template<typename T>
class Pair {
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T get_first() const { return first; }
    T get_second() const { return second; }
};

// template with multiple parameters
template<typename T, typename U>
struct Mixed {
    T a;
    U b;
    Mixed(T aa, U bb) : a(aa), b(bb) {}
};

// Exception example
double divide(double a, double b) {
    if (b == 0.0) throw std::runtime_error("Division by zero");
    return a / b;
}

int main() {
    std::cout << "my_max(3,7) = " << my_max(3,7) << '\n';
    std::cout << "my_max(2.5, 1.2) = " << my_max(2.5,1.2) << '\n';

    Pair<std::string> p("hello", "world");
    std::cout << "Pair: " << p.get_first() << ", " << p.get_second() << '\n';

    Mixed<int,double> m(5, 3.14);
    std::cout << "Mixed: " << m.a << ", " << m.b << '\n';

    try {
        std::cout << "10 / 2 = " << divide(10,2) << '\n';
        std::cout << "10 / 0 = " << divide(10,0) << '\n'; // triggers
    } catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << '\n';
    }

    return 0;
}