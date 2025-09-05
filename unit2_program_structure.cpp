/* 
 unit2_program_structure.cpp
 Demonstrates basic C++ program structure, namespaces, i/o streams and manipulators.
 Compile: g++ -std=c++17 -Wall unit2_program_structure.cpp -o unit2_program_structure
 Run: ./unit2_program_structure
*/

#include <iostream>
#include <iomanip> // for manipulators
#include <string>

namespace MyApp {
    void showHeader() {
        std::cout << "=== MyApp Header ===\n";
    }
}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    MyApp::showHeader();

    std::string name;
    int age;
    cout << "Enter your name: ";
    std::getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;

    cout << std::left << std::setw(10) << "Name:" << name << "\n";
    cout << std::left << std::setw(10) << "Age:" << age << "\n";

    // Type conversion example
    double d = 3.14159;
    int id = static_cast<int>(d); // explicit conversion
    cout << "double " << d << " converted to int " << id << "\n";

    return 0;
}