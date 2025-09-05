/* 
 unit4_operator_overloading.cpp
 Demonstrates operator overloading (unary, binary) and conversion operators.
 Compile: g++ -std=c++17 -Wall unit4_operator_overloading.cpp -o unit4_operator_overloading
 Run: ./unit4_operator_overloading
*/

#include <iostream>

class Complex {
public:
    double re, im;
    Complex(double r=0, double i=0): re(r), im(i) {}

    // binary operator +
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    // unary operator - (negation)
    Complex operator-() const {
        return Complex(-re, -im);
    }

    // conversion to double (magnitude)
    explicit operator double() const {
        return std::sqrt(re*re + im*im);
    }

    void print() const {
        std::cout << "(" << re << (im>=0 ? "+" : "") << im << "i)";
    }
};

int main() {
    Complex a(3,4), b(1,-2);
    Complex c = a + b;
    std::cout << "a="; a.print(); std::cout << ", b="; b.print(); std::cout << "\n";
    std::cout << "a + b = "; c.print(); std::cout << '\n';
    Complex d = -a;
    std::cout << "-a = "; d.print(); std::cout << '\n';
    double mag = static_cast<double>(a);
    std::cout << "Magnitude of a = " << mag << '\n';
    return 0;
}