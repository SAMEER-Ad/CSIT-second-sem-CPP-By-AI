/* 
 unit2_functions_and_pointers.cpp
 Demonstrates function overloading, inline function, default argument, pass-by-reference,
 return-by-reference (safe), pointers and pointer-to-function basics.
 Compile: g++ -std=c++17 -Wall unit2_functions_and_pointers.cpp -o unit2_functions_and_pointers
 Run: ./unit2_functions_and_pointers
*/

#include <iostream>

// inline function
inline int square(int x) { return x * x; }

// overloaded functions
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

// default argument and pass by reference
void increment(int &x, int delta = 1) { x += delta; }

// return by reference (dangerous if reference to local variable) - safe example returning static
int& static_counter() {
    static int counter = 0;
    return counter;
}

// pointer and pointer to function
int multiply(int a, int b) { return a * b; }

int main() {
    std::cout << "square(5) = " << square(5) << '\n';
    std::cout << "add(3,4) = " << add(3,4) << ", add(3.1, 4.2) = " << add(3.1,4.2) << '\n';

    int n = 10;
    increment(n);
    std::cout << "After increment: " << n << '\n';
    increment(n, 5);
    std::cout << "After increment by 5: " << n << '\n';

    int &c = static_counter(); // safe to hold static
    c = 7;
    std::cout << "static_counter() = " << static_counter() << '\n';

    // pointer to function
    int (*op)(int,int) = &multiply;
    std::cout << "multiply via pointer: " << op(6,7) << '\n';

    // pointers and arrays
    int arr[3] = {1,2,3};
    int *p = arr;
    std::cout << "arr via pointer: ";
    for (int i=0;i<3;++i) std::cout << *(p+i) << ' ';
    std::cout << '\n';

    return 0;
}