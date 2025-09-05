/* 
 unit3_static_members.cpp
 Demonstrates static data members and static member functions.
 Compile: g++ -std=c++17 -Wall unit3_static_members.cpp -o unit3_static_members
 Run: ./unit3_static_members
*/

#include <iostream>

class Counter {
private:
    int id;
    static int count; // declaration
public:
    Counter() : id(++count) {}
    int get_id() const { return id; }
    static int get_count() { return count; } // static member function
};

// define and initialize static member
int Counter::count = 0;

int main() {
    Counter c1, c2;
    std::cout << "c1 id: " << c1.get_id() << ", c2 id: " << c2.get_id() << '\n';
    std::cout << "Total created: " << Counter::get_count() << '\n';
    return 0;
}